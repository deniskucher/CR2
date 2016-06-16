<?
//Параметр: ЛБД УНО
$params = "lbd"; 
include "sintar2007.php";
?>

#include "globals.h"

<?
global $signals;

$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера

//Выбираем сигналы DI, DO, PIN, PFD, принадлежащие заданному контроллеру

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and  (SC.TypeName='DI' or SC.TypeName='PIN' or SC.TypeName='DO'
  or SC.TypeName='PFD')   order by SC.SigName";
$sig_di   =ibase_query($sigdb, $qry);

$qry = "select SC.SigName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and (SC.TypeName='AI'or SC.TypeName='PFA' or SC.TypeName='AO'
  or SC.TypeName='MRI' or SC.TypeName='MRO')
  order by SC.SigName";
$sig_ai   =ibase_query($sigdb, $qry);

$qry = "select * from SigCont SC, Controller C, KO K
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and SC.SigName=K.Name   and  SC.TypeName='KO' order by K.Name"; 
$sig_ko   =ibase_query($sigdb, $qry);
  
$qry = "select K.BASEVAL, SC.SigName, SC.TypeName from SigCont SC, Controller C, KL K
  where C.Name='{$cont}' and SC.NodeID=C.NodeID 
  and SC.SigName=K.Name  and  SC.TypeName='KL' order by K.Name"; 
$sig_kl   =ibase_query($sigdb, $qry);


 while ($sig = ibase_fetch_object($sig_di))
       echo "  bool _{$sig->SIGNAME}=false;\n";

 while ($sig = ibase_fetch_object($sig_ai))
       echo "  shot _{$sig->SIGNAME}=0;\n";

 echo "  //Ключи  \n";

 while ($sig = ibase_fetch_object($sig_kl))
  { 
   if ($sig->BASEVAL == '0')
       echo "bool _{$sig->SIGNAME} = false;\n";
   else
       echo "bool _{$sig->SIGNAME} = true;\n";
  }
 echo "  //Уставки  \n";

 while ($sig = ibase_fetch_object($sig_ko))
    {
      $val  = $sig->BASEVAL;
      $max  = $sig->MAX;
      $min  = $sig->MIN;
      $kod  = round ($val /($max - $min) *32767);	
       echo "short _{$sig->SIGNAME} = $kod;\n"; 

    }

echo "\n";
?>
 
