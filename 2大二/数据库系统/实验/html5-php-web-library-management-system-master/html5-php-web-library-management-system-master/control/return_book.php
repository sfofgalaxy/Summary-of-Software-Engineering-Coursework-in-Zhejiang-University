<?php
require "connect_to_DB.php";

$Rid = $_REQUEST["Rid"];
$Bcode = $_REQUEST["Bcode"];

$sql1 = "SELECT BorrowDate,Deadline,Penalty FROM borrowing WHERE Rid='$Rid' AND Bcode='$Bcode'";

$r1 = $conn -> query($sql1);

$sql2 = "";

while ($row = mysqli_fetch_array($r1)){
    $bd = $row["BorrowDate"];
    $dl = $row["Deadline"];
    $p = $row["Penalty"];
    $sql2 = $sql2."INSERT INTO returned VALUES ('$Rid', '$Bcode', '$bd', '$dl', curdate(), '$p', 0)";
}

echo "sql2:".$sql2;

$r2 = $conn -> query($sql2);

$sql3 = "UPDATE book SET Status=1 WHERE Bcode='$Bcode'";

$r3 = $conn -> query($sql3);


$sql4 = "SELECT ISBN FROM book WHERE Bcode='$Bcode'";

$r4 = $conn -> query($sql4);

$sql5 = "";

while ($row = mysqli_fetch_array($r4)){
    $isbn = $row["ISBN"];
    $sql5 = $sql5."UPDATE library SET InAmount=InAmount+1 WHERE ISBN='$isbn'";
}

echo "sql5".$sql5;

$r5 = $conn -> query($sql5);

$sql6 = "DELETE FROM borrowing WHERE Rid='$Rid' AND Bcode='$Bcode'";

$r6 = $conn -> query($sql6);

echo "还书成功";

$conn -> close();




?>