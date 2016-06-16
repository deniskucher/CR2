<?
//���������: ���� � ����������, ����������, ������ ������
$params = "lbd,takt"; 
include "sintar2007.php";
?>

#include "globals.h" 
#include "TABTS.h" 

void  _TABTSS()
{
<?
echo "  int TT = {$takt};     //������ ������	\n";
?>
  int TMC = 500/TT;	 //������ ��������
  int SMC = 0;		 //������� ������� ��������
  bool PMC = false;	 //������� ��������
  int TMG = 500/TT;	 //������ �������
  int SMG = 0;		 //������� ������� �������
  bool PMG  =false;	 //������� �������
  bool KNMC =false;	 //������ ��������
  bool KNMG =false;      //������ �������

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
// 4 �������� ��������� ��
$pts  = array();
$prmc = array();
$prmg = array();
$prr  = array();


while ($sig = ibase_fetch_object($sig_q))
{
//echo "{$sig->SIGNAME}\n";
  
  $proto = substr($sig->SIGNAME,8);   // $proto - ���������� ������ ����� ��

  if ($proto == 'TS')
   {   
   $ts[] = $sig->SIGNAME;
   $pts[]='false';
   $prmc[]='false';
   $prmg[]='false';
   $prr[]='false';
   }	
  elseif ($proto == 'DTS')
    $dts[] = $sig->SIGNAME;	

  elseif ($proto == 'KNMC')
    $knmc = $sig->SIGNAME;	
  elseif ($proto == 'KNMG')
    $knmg = $sig->SIGNAME;	
 	
}
$n = count($ts);

echo "  int n = {$n};        //���-��  ��������� �� \n";

out1sig_arr($ts, 'TS',$n, '��������� ��');
out1sig_arr($dts, 'DTS',$n, '������ �� �����');

echo "   KNMC = _{$knmc};  //������ �������� \n";
echo "   KNMG = _{$knmg};  //������ ������� \n";

out2sig_arr($pts, 'PTS',  $n, '������� i-�� ��������� ��');
out2sig_arr($pts, 'PRMC', $n, '������� �������� i-�� ��������� ��');
out2sig_arr($pts, 'PRMG', $n, '������� ������� i-�� ��������� ��');
out2sig_arr($pts, 'PRR',  $n, '������� ������� �������� i-�� ��������� ��');

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

int i;
  for (i = 0; i < n; ++i) 
  {
     if (KNMC || PRR[i]) 
       { if (TS[i])
            DTS[i]=PRR[i]=PTS[i]=true; 	
          else 
		{
		 if (PTS[i])
			{ PRMG[i]=true; PRR[i]=PRMC[i]=false; DTS[i]=PMG;}
 		  else  PTS[i]=DTS[i]=PRMG[i]=PRMC[i]=false;
		}
       }
     else
     {
      if (!PRMG[i] && (PRMC[i] || TS[i]))
		{ PTS[i]=PRMC[i]=true; PRMG[i]=PRR[i]=false; DTS[i]=PMG;}

      if ((!PRMG[i] && !PRMC[i] && !TS[i]) || (PRMG[i] && KNMG))
		PTS[i]=DTS[i]=PRMG[i]=PRMC[i]=false;
      if (TS[i])
	{ PTS[i]=PRMC[i]=true; PRMG[i]=PRR[i]=false; DTS[i]=PMG;}
       else
        { PRMG[i]=true; PRR[i]=PRMC[i]=false; DTS[i]=PMG;}

     }

  }
}


