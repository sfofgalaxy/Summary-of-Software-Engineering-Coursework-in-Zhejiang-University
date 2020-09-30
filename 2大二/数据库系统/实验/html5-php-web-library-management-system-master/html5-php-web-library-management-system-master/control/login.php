<?php
require "connect_to_DB.php";

$Key = $_REQUEST["Key"];
$pwd = $_REQUEST["Password"];

$sql = "SELECT * FROM administrators";

$r = $conn -> query($sql);
$un = false;
$pd = false;

while ($row = mysqli_fetch_array($r)){
    $gaid = $row["Aid"];
    $gun = $row["Aname"];
    $gpd = $row["Apassword"];
    if($gaid == $Key or $gun == $Key){
        $un = true;
        if ($gpd == $pwd){
            $pd = true;
            break;
        }
    }
}

if ($un and $pd){
    echo "登录成功";
}else{
    echo "用户名或密码错误";
}

?>