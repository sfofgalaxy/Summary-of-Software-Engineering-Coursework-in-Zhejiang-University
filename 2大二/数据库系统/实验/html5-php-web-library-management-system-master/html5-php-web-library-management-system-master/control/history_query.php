<?php
require "connect_to_DB.php";

$Rid = $_REQUEST["Rid"];
$Bcode = $_REQUEST["Bcode"];
/*$ISBN = $_REQUEST["ISBN"];
$Rname = $_REQUEST["Rname"];
$Bname = $_REQUEST["Bname"];*/

$sql = "SELECT Rid,Bcode,BorrowDate,ReturnDate,EndPenalty,Paid FROM returned WHERE";

$hasone = false;
if ($Rid != ""){
    if ($hasone){
        $sql = $sql." AND Rid='$Rid'";
    }else{
        $sql = $sql." Rid='$Rid'";
        $hasone = true;
    }
}

if ($Bcode != ""){
    if ($hasone){
        $sql = $sql." AND Bcode='$Bcode'";
    }else{
        $sql = $sql." Bcode='$Bcode'";
        $hasone = true;
    }
}


if ($hasone){

    $result = $conn -> query($sql);

    $response = "";

    while ($row = mysqli_fetch_array($result)) {
        $penalty = $row["EndPenalty"];
        $gotRid = $row["Rid"];
        $gotBcode= $row["Bcode"];
        $paid = $row["Paid"];
        $borrowdate = $row["BorrowDate"];

        $response = $response."<tr></tr>";

        $response = $response."<tr><td data-toggle=\"modal\" data-target=\"#history_Modal\">".$gotRid."</td><td data-toggle=\"modal\" data-target=\"#history_Modal\">"
            .$row["Bcode"]."</td><td data-toggle=\"modal\" data-target=\"#history_Modal\">".$row["BorrowDate"]."</td><td data-toggle=\"modal\" data-target=\"#history_Modal\">".$row["ReturnDate"]
            ."</td><td>".$penalty."</td><td>";

        if ($penalty == 0){
            $response = $response."无罚金</td></tr>";
        }else{
            if ($paid){
                $response = $response."已支付</td></tr>";
            }else{
                $response = $response."<input type='button' class='return_button search-book' id='hy_".$gotRid.$gotBcode.$borrowdate."' onclick='set_penalty_hy(\"$gotRid\", \"$gotBcode\", \"$borrowdate\")' value='￥".$penalty."'></td></tr>";
            }
        }


    }

    if ($response != ""){
        echo $response;
    }else{
        echo "没有查询到借书信息。";
    }
}else{
    echo "请输入至少一条搜索条件";
}

?>