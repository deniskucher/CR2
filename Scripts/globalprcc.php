<?
//Параметр: 
$params = "Proj"; 
include "sintar2007.php";
?>

#include "globals.h"

<?
$Types = array(8 => 'float', 'short', 'int', 'unsigned short', 'unsigned char', 'bool'); 
//Выбираем переменные из программного проекта
$projdb = ibase_connect($Proj);
$qry = "select ObjectName, VarValue, TypeID from Object  
  where Category = 1 and TypeID < 14 and VarValue != '' and VarValue is not NULL
  order by ObjectName";
$proj_q = ibase_query($projdb, $qry);
while ($sig = ibase_fetch_object($proj_q))
{
   echo "  {$Types[$sig->TypeID]} _{$sig->ObjectName} = {$sig->VarValue};\n";
}
echo "\n";
?>
 
