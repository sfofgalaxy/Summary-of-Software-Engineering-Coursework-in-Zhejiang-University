<?php
require "connect_to_DB.php";

$rid = $_REQUEST["Rid"];
$bcode = $_REQUEST["Bcode"];

$sql = "SELECT EndPenalty FROM returned WHERE Rid='$rid' AND Bcode='$bcode' AND EndPenalty>0 AND Paid=0";

$sql1 = "UPDATE returned SET Paid=1 WHERE Rid='$rid' AND Bcode='$bcode' AND EndPenalty>0";

$r = $conn -> query($sql);

while ($row = mysqli_fetch_array($r)){
    $endp = $row["EndPenalty"];
}

$sql2 = "UPDATE reader SET Arrearage=Arrearage-'$endp' WHERE Rid='$rid'";

$r1 = $conn -> query($sql1);

$r2 = $conn -> query($sql2);

if ($r1 and  $r2){
    echo "缴纳成功";
}else{
    echo "出错";
}

?>