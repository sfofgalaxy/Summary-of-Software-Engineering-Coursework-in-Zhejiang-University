<?php
require "connect_to_DB.php";

$rid = $_REQUEST["Rid"];
$isbn = $_REQUEST["ISBN"];
$act = $_REQUEST["Act"];
$msg = $_REQUEST["Message"];

$sql = "UPDATE recommend SET Status='$act', Response='$msg' WHERE Rid='$rid' AND ISBN='$isbn'";

$r = $conn -> query($sql);

if ($r){
    echo $sql."已发消息";
}else{
    echo $sql."发送失败";
}


?>