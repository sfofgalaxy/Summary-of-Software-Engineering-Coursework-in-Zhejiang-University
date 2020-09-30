<?php
require "connect_to_DB.php";

$ISBN = $_REQUEST["ISBN"];
$Bname = $_REQUEST["Bname"];
$Cover = $_REQUEST["Cover"];
$Press = $_REQUEST["Press"];
$Author = $_REQUEST["Author"];
$Category = $_REQUEST["Category"];
$Bcode = $_REQUEST["Bcode"];
$position = $_REQUEST["position"];

$sql1 = "INSERT INTO library VALUES ('$ISBN', '$Bname','$Cover','$Press','$Author','$Category',1,1,0,0)";

$result1 = $conn -> query($sql1);

$sql2 = "INSERT INTO book VALUES ('$Bcode','$ISBN',1,'$position')";

$result2 = $conn -> query($sql2);

echo "成功添加图书！"

?>