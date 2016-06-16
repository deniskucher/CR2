<?
//Параметр: ЛБД УНО
$params = "lbd"; 
include "sintar2007.php";
?>
#ifndef SigChangeH
#define SigChangeH

<?
global $signals;

$sigdb = ibase_connect($signals);
$cont = substr(basename($lbd,'.ib'),3); //Имя контроллера

//Выбираем сигналы DI, DO и PFD, принадлежащие заданной ЛБД
$qry = "select SC.SigName, SC.TypeName from SigCont SC, Controller C
  where C.Name='{$cont}' and SC.NodeID=C.NodeID"; 
$sig_q = ibase_query($sigdb, $qry);
while ($sig = ibase_fetch_object($sig_q))
{
  /*if ((($sig->TYPENAME == 'DO') and (substr($sig->SIGNAME,-3) == 'DTS'))
  or (($sig->TYPENAME == 'PFD') and (substr($sig->SIGNAME,-2) == 'TS'))
  or (($sig->TYPENAME == 'DI') 
  and ((substr($sig->SIGNAME,-4) == 'KNMC') or (substr($sig->SIGNAME,-4) == 'KNMG'))))*/
    echo "extern char *p{$sig->SIGNAME};\n"; 

}
?>
extern void Read_Sig();
extern void Write_Sig();
extern void Init_P();
#endif
