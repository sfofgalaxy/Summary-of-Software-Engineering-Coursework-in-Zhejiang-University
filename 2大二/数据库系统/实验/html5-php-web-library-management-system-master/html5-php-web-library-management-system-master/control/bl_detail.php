<?php
require "connect_to_DB.php";

$Rid = $_REQUEST["Rid"];
$Bcode = $_REQUEST["Bcode"];

$sql1 = "SELECT Rname,IDPhoto FROM reader WHERE Rid='$Rid'";
$sql2 = "SELECT Deadline,Renewline FROM borrowing WHERE Rid='$Rid' AND Bcode='$Bcode'";

$r1 = $conn -> query($sql1);
$r2 = $conn -> query($sql2);

$response = "";

while ($row1 = mysqli_fetch_array($r1)){
    $rname = $row1["Rname"];
    $photo = $row1["IDPhoto"];
    while ($row2 = mysqli_fetch_array($r2)){
        $deadline = $row2["Deadline"];
        $Renewline = $row2["Renewline"];
        $response = $response.$rname."|".$photo."|".$deadline."|".$Renewline;
    }
}

if ($response != ""){
    echo $response;
}else{
    echo "failed";
}

?>