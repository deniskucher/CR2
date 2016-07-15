<?
//Параметр: ЛБД УНО
$params = "lbd"; 
include "sintar2007.php";
?>

#include "KD.h"
#include "globals.h"

<?
global $signals;

$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера

//Выбираем сигналы, принадлежащие заданному контроллеру

 $qra = "select SC.SIGNAME, K.CHANLCOUNT, K.ZAMER, K.LGR from SigCont SC, Controller C, AI K
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and SC.SigName=K.Name  order by K.Name "; 
$sig_ai   =ibase_query($sigdb, $qra);
$ai  = array();
$chan  = array();
$zamer = array();
$lgr  = array();

 while ($sig = ibase_fetch_object($sig_ai))
    {
       echo "  bool _{$sig->SIGNAME}F_1;\n";
	$ai[]=$sig->SIGNAME;
	$chan[]=$sig->CHANLCOUNT;
	$zamer[]=$sig->ZAMER;
	$lgr[]=$sig->LGR;

    }
?>

_TKD1 *pAI1[KOL_AI1+1]; // +1 worked in case KOL_AI count = 0 
_TKD2 *pAI2[KOL_AI2+1];
_TKD3 *pAI3[KOL_AI3+1];

void Init_KD()
{
 short i;
 for (i=0;i <= KOL_AI1;i++) 
 pAI1[i] = new _TKD1(0,0,0,0,0,0,0,0,0,0,0,0,0); 
 for (i=0;i <= KOL_AI2;i++) 
 pAI2[i] = new _TKD2(0); 
 for (i=0;i <= KOL_AI3;i++) 
 pAI3[i] = new _TKD3(0,0,0,0,0); 

<?
 $qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID and SC.TypeName='PFD'
  order by SC.SigName";
$sig_pfd   =ibase_query($sigdb, $qry);
// 4 массива запретов 
$zmx  = array();
$zmn = array();
$zdv = array();
$zrk  = array();

 
 while ($sig = ibase_fetch_object($sig_pfd))
 {
     if ($p=strpos($sig->SIGNAME,'ZMX'))
       $zmx[]   = substr($sig->SIGNAME,0,$p);
     elseif ($p=strpos($sig->SIGNAME,'ZMN'))
       $zmn[]   = substr($sig->SIGNAME,0,$p);
     elseif ($p=strpos($sig->SIGNAME,'ZDV'))
       $zdv[]   = substr($sig->SIGNAME,0,$p);
     elseif ($p=strpos($sig->SIGNAME,'RZRK'))
       $zrk[]   = substr($sig->SIGNAME,0,$p);
 }	
 echo "   i=0;\n";
 $n=count($zmx);
 $kai=count($ai);
 
 if ($n>0)
 {
  $z=0;
   for ($x = 0; $x < $kai; ++$x) 
 
  {
      for ($j = 0; $j < $n; ++$j) 
      { 
        if ($zmx[$j]==$ai[$x])
        { echo "  pAI1[i]->pMask_ZMX = &_{$ai[$x]}ZMX;\n";  ++$z;}
      }
      echo "   i++;//{$ai[$x]}\n";
      if ($z>=$n) break;
    }

 }   
 echo "   i=0;\n";
 $n=count($zmn);
 if ($n>0)
 {
  $z=0;
  for ($x = 0; $x < $kai; ++$x) 
    {
      for ($j = 0; $j < $n; ++$j) 
       { 
        if ($zmn[$j]==$ai[$x])
        {echo "  pAI1[i]->pMask_ZMN = &_{$ai[$x]}ZMN;\n"; ++$z;}
       }
      echo "   i++; //{$ai[$x]}\n";
      if ($z>=$n) break;
    }
 }    
 echo "   i=0;\n";


 $n=count($zdv);
 if ($n>0)
 {
  $z=0;
  for ($x = 0; $x < $kai; ++$x) 
    {
      for ($j = 0; $j < $n; ++$j) 
       { 
        if ($zdv[$j]==$ai[$x])
        {echo "  pAI1[i]->pMask_ZDV = &_{$ai[$x]}ZDV;\n"; ++$z;}
       }
      echo "   i++;//{$ai[$x]}\n";
      if ($z>=$n) break;
    }
 }
  echo "   i=0;\n"; 
 $n=count($zrk);   
 if ($n>0)
 {
  $i = 0;  $z=0;
  for ($x = 0; $x < $kai; ++$x) 
    {
     if ($zamer[$x]!= '<null>' and $lgr[$x]== '2')
       {
          for ($j = 0; $j < $n; ++$j) 
          { 
           if ($zrk[$j]==$zamer[$x] and $i ==0)
            {echo "  pAI2[i]->pMask_ZRK = &_{$zamer[$x]}RZRK;\n"; ++$z;} 
          }   
          $i++;
          if ($i >=2)
           { $i = 0;   echo "   i++;\n"; }  
       }
       if ($z>=$n) break;
     }     
  echo "   i=0;\n";
  $i = 0; 
    for ($x = 0; $x < $kai; ++$x) 
    {
      if ($zamer[$x]!= '<null>' and $lgr[$x]== '3')
       {
          for ($j = 0; $j < $n; ++$j) 
          { 
           if ($zrk[$j]==$zamer[$x] and $i ==0)
            {echo "  pAI3[i]->pMask_ZRK = &_{$zamer[$x]}RZRK;\n"; ++$z;}
          }   
          $i++;
          if ($i >=3)
           { $i = 0;   echo "   i++;\n"; }  
       }
       if ($z>=$n) break;          
   }
 }        
?>
}
void KD_RUN()
{
 short i;
 i=0;
 if (Delay_1m<600) Delay_1m++;
<?
 
 for ($x = 0; $x < $kai; ++$x) 
 {
     if  ($chan[$x] == '2')
   echo "  pAI1[i]->_KD1(_{$ai[$x]}, _{$ai[$x]}OKD, _{$ai[$x]}KRS,
       _{$ai[$x]}K1N, _{$ai[$x]}K2N, _{$ai[$x]}DV, _{$ai[$x]}MN,
       _{$ai[$x]}MX, _{$ai[$x]}SBRN, _{$ai[$x]}R, _{$ai[$x]}F,
       _{$ai[$x]}ZZ, _{$ai[$x]}F_1);  i++;\n"; 
   else
   echo "  pAI1[i]->_KD1(_{$ai[$x]}, _{$ai[$x]}OKD, _{$ai[$x]}KRS,
       _{$ai[$x]}K1N, _{$ai[$x]}K1N, _{$ai[$x]}DV, _{$ai[$x]}MN,
       _{$ai[$x]}MX, _{$ai[$x]}SBRN, _{$ai[$x]}R, _{$ai[$x]}F,
       _{$ai[$x]}ZZ, _{$ai[$x]}F_1);  i++;\n"; 
 }     
echo " i=0;\n";

$i = 0;
$zam='<null>';
   for ($x = 0; $x < $kai; ++$x) 
   {
    if  ($i ==0 and $lgr[$x]== '2' and $zamer[$x]!= '<null>')
       {
        $zam=$zamer[$x];
        $A1=$ai[$x];
        $i++;
       }

    elseif  ($i ==1 and $lgr[$x]== '2' and $zamer[$x] == $zam)
       {
        $A2=$ai[$x];
        echo "  pAI2[i]->_KD2(_{$A1}R, _{$A2}R,_{$zamer[$x]}OKD, _{$zamer[$x]}KRS,
       _{$zamer[$x]}DEL, _{$A1}F, _{$A2}F, _{$zamer[$x]}SBRN,
       _{$zamer[$x]}R, _{$zamer[$x]}F, _{$zamer[$x]}ZZ);  i++;\n";
        $i =0;
        $zam='<null>';
       }
   }
echo " i=0;\n";
 
$i = 0;
$zam='<null>';

 for ($x = 0; $x < $kai; ++$x) 
   {
         if  ($i ==0 and $lgr[$x]== '3' and $zamer[$x]!= '<null>')
       {
        $zam=$zamer[$x];
        $A1=$ai[$x];
        $i++;
       }

    elseif  ($i ==1 and $lgr[$x]== '3' and  $zamer[$x] == $zam)
       {
        $A2=$ai[$x];
        $i++;
       }
    elseif  ($i ==2 and $lgr[$x]== '3' and  $zamer[$x] == $zam)
       {
        $A3=$ai[$x];
       echo "  pAI3[i]->_KD3(_{$A1}R, _{$A2}R, _{$A3}R, _{$zamer[$x]}OKD, _{$zamer[$x]}KRS,
       _{$zamer[$x]}DEL, _{$zamer[$x]}SBRN, _{$A1}F_1, _{$A2}F_1, _{$A3}F_1,
       _{$zamer[$x]}R, _{$zamer[$x]}F, _{$A1}F, _{$A2}F, _{$A3}F, _{$zamer[$x]}ZZ,
       _{$A1}KRS, _{$A2}KRS, _{$A3}KRS);  i++;\n";
       $i =0; $zam='<null>';
       }
    
  } 
echo "};\n";
?>
 
