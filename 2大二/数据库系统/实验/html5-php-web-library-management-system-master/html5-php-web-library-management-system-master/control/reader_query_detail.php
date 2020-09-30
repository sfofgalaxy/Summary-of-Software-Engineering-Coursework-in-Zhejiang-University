<?php
require "connect_to_DB.php";

$Rid = $_REQUEST["Rid"];

$sql = "SELECT IDPhoto FROM reader WHERE Rid='$Rid'";

$result = $conn->query($sql);

$response = "";

while ($row = mysqli_fetch_array($result)) {
    $purl = $row["IDPhoto"];
//    <img src="/i/eg_tulip.jpg"  alt="上海鲜花港 - 郁金香" />
    $response = $response."<img src='$purl' alt=\"无头像\" />";
}

if ($response != ""){
    echo $response;
}

?>