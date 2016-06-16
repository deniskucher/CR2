<?
//Параметры: путь к разработке, контроллер, период задачи
$params = "lbd,takt"; 
include "sintar2007.php";
?>
void function TABTS
{
<?
echo "  int TT = {$takt};     //Период задачи	\n";
?>
  int TMC = 500/TT;	 //Период мерцания
  int SMC = 0;		 //Счетчик периода мерцания
  bool PMC = false;	 //Признак мерцания
  int TMG = 500/TT;	 //Период мигания
  int SMG = 0;		 //Счетчик периода мигания
  bool PMG = false;	 //Признак мигания

<?
global $signals;
$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера
//Выбираем сигналы DO и PFD, принадлежащие заданной ЛБД
$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and (SC.TypeName='DI' or SC.TypeName='DO' or SC.TypeName='PFD')
  order by SC.SigName";
$sig_q = ibase_query($sigdb, $qry);

//для подсветки ТАБЛО ТС  4 сигнала  из БД:
$ts = array();		//сообщение сигнализации
$dts = array();		//сигнал на табло

$knmc = '';		//кнопка мерцания
$knmg = '';		//кнопка мигания

while ($sig = ibase_fetch_object($sig_q))
{
//echo "{$sig->SIGNAME}\n";
  
  $proto = substr($sig->SIGNAME,8);   // $proto - возвращает строку после ИМ

  if ($proto == 'TS')
      $ts[] = $sig->SIGNAME;	
  elseif ($proto == 'DTS')
    $dts[] = $sig->SIGNAME;	

  elseif ($proto == 'KNMC')
    $knmc = $sig->SIGNAME;	
  elseif ($proto == 'KNMG')
    $knmg = $sig->SIGNAME;	
 	
}
$n = count($ts);

echo "  int n = {$n};        //Кол-во  сообщений ТС \n";

out1sig_arr($ts, 'TS', 'сообщение сигнализации');
out1sig_arr($dts, 'DTS', 'сигнал на табло');

echo "  bool KNMC = _{$knmc};  //кнопка мерцания \n";
echo "  bool KNMG = _{$knmg};  //кнопка мигания \n";

echo " bool PTS{$n}; 	//Признак i-го сообщения ТС \n";
echo " bool PRMC{$n};	//Признак мерцания i-го сообщения ТС\n";
echo " bool PRMG{$n};	//Признак мигания i-го сообщения ТС\n";
echo " bool PRR{$n};	//Признак ровного свечения i-го сообщения ТС\n";

?>
  if (SMC++ == TMC)
  {
    SMC = 0;
    PMC = !PMC; 
  }

  if (SMC++ == TMC)
  {
    SMG = 0;
    PMG = !PMG; 
  }


  for (i = 0; i < n; ++i) 
  {
     if (KNMC || PRR[i]) 
       { if(TS[i])
            DTS[i]=PRR[i]=PTS[i]=true; 	
          else 
		{
		 if (PTS[i])
			{ PRMG[i]=true; PRR[i]=PRMC[i]=falce; DTS[i]=PMG;}
 		  else  PTS[i]=DTS[i]=PRMG[i]=PRMC[i]=falce;
		}
       }
     else
     {
      if (!PRMG[i] && (PRMC[i] || TS[i]))
		{ PTS[i]=PRMC[i]=true; PRMG[i]=PRR[i]=falce; DTS[i]=PMG;}

      if ((!PRMG[i] && !PRMC[i] && !TS[i]) || (PRMG[i] && KNMG))
		PTS[i]=DTS[i]=PRMG[i]=PRMC[i]=falce;
      if (TS[i])
	{ PTS[i]=PRMC[i]=true; PRMG[i]=PRR[i]=falce; DTS[i]=PMG;}
       else
        { PRMG[i]=true; PRR[i]=PRMC[i]=falce; DTS[i]=PMG;}

     }

  }
};
