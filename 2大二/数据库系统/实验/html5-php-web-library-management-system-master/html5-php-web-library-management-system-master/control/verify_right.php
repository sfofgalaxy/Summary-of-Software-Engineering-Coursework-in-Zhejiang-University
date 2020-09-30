<?php
require "connect_to_DB.php";
$rid = $_REQUEST["Rid"];

$sql = "SELECT Arrearage FROM reader WHERE Rid='$rid'";

$r = $conn -> query($sql);

while ($row = mysqli_fetch_array($r)){
    if($row["Arrearage"] > 0){
        echo "该读者欠款".$row["Arrearage"]."元，不能借书";
    }else{
        echo "该读者无欠款，可以借书";
    }
}

?>