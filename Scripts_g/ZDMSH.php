<?
//���������: ���� � ����������, ����������, ������ ������
$params = "lbd,takt"; 
include "sintar2007.php";
?>
void function ZDMSH
{
<?
echo "  int TT = {$takt};     //������ ������	\n";
?>
  int TM = 500/TT;  //������ �������
  int SM = 0;	    //������� ������� �������
  bool PM = false;  //������� �������
<?
global $signals;
$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //��� �����������
//�������� ������� DO � PFD, ������������� �������� ���
$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and (SC.TypeName='DO' or SC.TypeName='PFD')
  order by SC.SigName";
$sig_q = ibase_query($sigdb, $qry);

//����� �������� ����������� 6 �������� ��������� �� �������� ���������:
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
  /*if ($zdname != $old_zdname)	//����� ��������
  {
    if (count($sg) % 6 != 0)
      echo "� �������� {$old_zdname} ��������� ������� SG\n";	
    if (count($sgr) % 6 != 0)
      echo "� �������� {$old_zdname} ��������� ������� SGR\n";	
    if (count($sgm) % 6 != 0)
      echo "� �������� {$old_zdname} ��������� ������� SGM\n";	
    if (count($sy) % 6 != 0)
      echo "� �������� {$old_zdname} ��������� ������� SY\n";	
    if (count($syr) % 6 != 0)
      echo "� �������� {$old_zdname} ��������� ������� SYR\n";	
    if (count($sym) % 6 != 0)
      echo "� �������� {$old_zdname} ��������� ������� SYM\n"; 	
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
echo "  int n = {$n};        //���-�� �������� \n";
out1sig_arr($sg, 'SG', '��������� �������');
out1sig_arr($sgr, 'SGR', '��������� ������ �������');
out1sig_arr($sgm, 'SGM', '��������� �������� �������');
out1sig_arr($sy, 'SY', '��������� ������');
out1sig_arr($syr, 'SYR', '��������� ������ ������');
out1sig_arr($sym, 'SYM', '��������� �������� ������');
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
