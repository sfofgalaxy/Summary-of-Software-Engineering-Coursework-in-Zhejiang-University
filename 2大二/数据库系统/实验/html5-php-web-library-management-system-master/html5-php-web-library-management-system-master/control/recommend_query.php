<?php

require "connect_to_DB.php";

$sql = "SELECT * FROM recommend";

$r = $conn -> query($sql);

$response = "";

while ($row = mysqli_fetch_array($r)){
    $rid = $row["Rid"];
    $isbn = $row["ISBN"];
    $sql1 = "SELECT Rname FROM reader WHERE Rid='$rid'";
    $r1 = $conn -> query($sql1);
    $buyed = 1;
    $refused = 0;

    while ($row1 = mysqli_fetch_array($r1)){
        $rname = $row1["Rname"];
    }

    $response = $response."<tr><td>".$rid."</td><td>".$rname."</td><td>".$row["ISBN"]."</td><td>".$row["Bname"]
        ."</td><td>".$row["Press"]."</td><td>".$row["Author"]."</td><td>";

    if($row["Status"] == 1){
        $response = $response."已购入";
    }elseif ($row["Status"] == 0){
        $response = $response."<input type='button' class='search-book' id='recommend1_".$rid.$isbn."'
         onclick='recommend(\"$rid\",\"$isbn\", \"$buyed\")' value='已购'> | <input type='button'
          class='search-book' id='recommend2_".$rid.$isbn."' onclick='recommend(\"$rid\",\"$isbn\",\"$refused\")'
           value='移出'>";
    }elseif ($row["Status"] == 2){
        $response = $response."不购入";
    }
    $response = $response."</td></tr>";



}

echo $response;

?>