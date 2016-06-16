<?
//Параметры: путь к разработке, контроллер, период задачи
$params = "lbd,takt"; 
include "sintar2007.php";
?>
void function ZDMSH
{
<?
echo "  int TT = {$takt};     //Период задачи	\n";
?>
  int TM = 500/TT;  //Период мигания
  int SM = 0;	    //Счетчик периода мигания
  bool PM = false;  //Признак мигания
<?
global $signals;
$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера
//Выбираем сигналы DO и PFD, принадлежащие заданной ЛБД
$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and (SC.TypeName='DO' or SC.TypeName='PFD')
  order by SC.SigName";
$sig_q = ibase_query($sigdb, $qry);

//Одной задвижке принадлежат 6 сигналов подсветки ее текущего состояния:
$sg = array();
$sgr = array();
$sgm = array();
$sy = array();
$syr = array();
$sym = array();
$old_zdname = '';

while ($sig = ibase_fetch_object($sig_q))
{
//echo "{$sig->SIGNAME}\n";
  $zdname = substr($sig->SIGNAME,0,7);	
  /*if ($zdname != $old_zdname)	//Новая задвижка
  {
    if (count($sg) % 6 != 0)
      echo "У задвижки {$old_zdname} нехватает сигнала SG\n";	
    if (count($sgr) % 6 != 0)
      echo "У задвижки {$old_zdname} нехватает сигнала SGR\n";	
    if (count($sgm) % 6 != 0)
      echo "У задвижки {$old_zdname} нехватает сигнала SGM\n";	
    if (count($sy) % 6 != 0)
      echo "У задвижки {$old_zdname} нехватает сигнала SY\n";	
    if (count($syr) % 6 != 0)
      echo "У задвижки {$old_zdname} нехватает сигнала SYR\n";	
    if (count($sym) % 6 != 0)
      echo "У задвижки {$old_zdname} нехватает сигнала SYM\n"; 	
    $old_zdname = $zdname;
  } */	
  $proto = substr($sig->SIGNAME,7);
  if ($proto == 'SG') 
    $sg[] = $sig->SIGNAME;	
  elseif ($proto == 'SGR')
    $sgr[] = $sig->SIGNAME;	
  elseif ($proto == 'SGM')
    $sgm[] = $sig->SIGNAME;	
  elseif ($proto == 'SY')
    $sy[] = $sig->SIGNAME;	
  elseif ($proto == 'SYR')
    $syr[] = $sig->SIGNAME;	
  elseif ($proto == 'SYM')
    $sym[] = $sig->SIGNAME;	
}
$n = count($sgr);
echo "  int n = {$n};        //Кол-во задвижек \n";
out1sig_arr($sg, 'SG', 'Подсветка зеленым');
out1sig_arr($sgr, 'SGR', 'Подсветка ровным зеленым');
out1sig_arr($sgm, 'SGM', 'Подсветка мигающим зеленым');
out1sig_arr($sy, 'SY', 'Подсветка желтым');
out1sig_arr($syr, 'SYR', 'Подсветка ровным желтым');
out1sig_arr($sym, 'SYM', 'Подсветка мигающим желтым');
?>
  if (SM++ == TM)
  {
    SM = 0;
    PM = !PM; 
  }

  for (i = 0; i < n; ++i) 
  {
    if (PM)
    {
      SG[i] = SGM[i];
      SY[i] = SYM[i];
    }
    else
    {
      SG[i] = SGR[i];
      SY[i] = SYR[i];
    }
  }
};
