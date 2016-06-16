<?
//Параметр: 
$params = "Proj"; 
include "sintar2007.php";
?>

#include "globals.h"

<?
//Выбираем переменные из программного проекта
$projdb = ibase_connect($Proj);
$qry = "select ObjectName, VarValue, TypeID from Object  
  where Category=1 and TypeID<14 and VarValue!='' and VarValue is not NULL
  order by ObjectName";
$proj_q = ibase_query($projdb, $qry);
//$VarType = ''; 
while ($sig = ibase_fetch_object($proj_q))
{
   if ($sig->TypeID == '8')
     $VarType = 'float';
   elseif ($sig->TypeID == '9')
     $VarType = 'short';
   elseif ($sig->TypeID == '10')
     $VarType = 'int';
   elseif ($sig->TypeID == '11')
     $VarType = 'unsigned short';
   elseif ($sig->TypeID == '12')
     $VarType = 'unsigned char';
   elseif ($sig->TypeID == '13')
     $VarType = 'bool';
   echo "  {$VarType} _{$sig->ObjectName} = {$sig->VarValue};\n";
}
echo "\n";
?>
 
