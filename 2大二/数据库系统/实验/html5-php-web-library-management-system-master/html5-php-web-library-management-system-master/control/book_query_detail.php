<?php
require "connect_to_DB.php";

$isbn = $_REQUEST["ISBN"];

$sql = "SELECT * FROM book WHERE ISBN='$isbn'";

$result = $conn->query($sql);

$response = "";

while ($row = mysqli_fetch_array($result)) {
    $isbn = $row["ISBN"];
    $bcode = $row["Bcode"];
    if ($row["Status"] == 1){
        $state = "在馆";
    }else{
        $state = "借出";
    }
    $statusid = "book1|".$isbn."-".$bcode."|Status";
    $positionid = "book1|".$isbn."-".$bcode."|position";
    $response = $response."<tr><td>".$isbn."</td><td>"
        .$row["Bcode"]."</td><td ondblclick='modify_td(\"$statusid\")'>".$state."</td><td ondblclick='modify_td(\"$positionid\")'>".$row["position"]."</td></tr>";
}

/*$cover = "";
$sql1 = "SELECT Cover FROM library WHERE ISBN='$isbn'";

$result1 = $conn -> query($sql1);

while ($row1 = mysqli_fetch_array($result)){
    $cover = $row["Cover"];
}

$response = $response."<tfoot><td><img src=\">".$cover."\"</td></tfoot>";*/

//echo ("<script language='JavaScript'>alert('$response')</script>");
if ($response != ""){
    echo $response;
}



?>