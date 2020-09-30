<?php
require "connect_to_DB.php";

$Rid = &$_REQUEST["Rid"];

$sql1 = "SELECT Penalty FROM borrowing WHERE Rid='$Rid'";
$can = true;

$r1 = $conn -> query($sql1);

while ($row = mysqli_fetch_array($r1)){
    if ($row["Penalty"] > 0){
        $can = false;
    }
}

if ($can){
    $sql2 = "UPDATE returned SET Paid=1 WHERE Rid='$Rid' AND EndPenalty>0";
    $sql3 = "UPDATE reader SET Arrearage=0 WHERE Rid='$Rid'";

    $r2 = $conn -> query($sql2);
    $r3 = $conn -> query($sql3);

    if ($r2 and $r3){
        echo "缴纳成功";
    }else{
        echo "缴纳出错";
    }

}else{
    echo "该读者有过期未还图书，不能缴纳欠款";
}



?>