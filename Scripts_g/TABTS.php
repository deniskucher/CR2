<?
//���������: ���� � ����������, ����������, ������ ������
$params = "lbd,takt"; 
include "sintar2007.php";
?>
void function TABTS
{
<?
echo "  int TT = {$takt};     //������ ������	\n";
?>
  int TMC = 500/TT;	 //������ ��������
  int SMC = 0;		 //������� ������� ��������
  bool PMC = false;	 //������� ��������
  int TMG = 500/TT;	 //������ �������
  int SMG = 0;		 //������� ������� �������
  bool PMG = false;	 //������� �������

<?
global $signals;
$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //��� �����������
//�������� ������� DO � PFD, ������������� �������� ���
$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and (SC.TypeName='DI' or SC.TypeName='DO' or SC.TypeName='PFD')
  order by SC.SigName";
$sig_q = ibase_query($sigdb, $qry);

//��� ��������� ����� ��  4 �������  �� ��:
$ts = array();		//��������� ������������
$dts = array();		//������ �� �����

$knmc = '';		//������ ��������
$knmg = '';		//������ �������

while ($sig = ibase_fetch_object($sig_q))
{
//echo "{$sig->SIGNAME}\n";
  
  $proto = substr($sig->SIGNAME,8);   // $proto - ���������� ������ ����� ��

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

echo "  int n = {$n};        //���-��  ��������� �� \n";

out1sig_arr($ts, 'TS', '��������� ������������');
out1sig_arr($dts, 'DTS', '������ �� �����');

echo "  bool KNMC = _{$knmc};  //������ �������� \n";
echo "  bool KNMG = _{$knmg};  //������ ������� \n";

echo " bool PTS{$n}; 	//������� i-�� ��������� �� \n";
echo " bool PRMC{$n};	//������� �������� i-�� ��������� ��\n";
echo " bool PRMG{$n};	//������� ������� i-�� ��������� ��\n";
echo " bool PRR{$n};	//������� ������� �������� i-�� ��������� ��\n";

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
