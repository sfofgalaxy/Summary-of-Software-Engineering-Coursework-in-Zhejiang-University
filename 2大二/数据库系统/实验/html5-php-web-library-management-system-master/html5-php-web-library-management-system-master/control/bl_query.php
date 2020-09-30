<?php
require "connect_to_DB.php";

$Rid = $_REQUEST["Rid"];
$Bcode = $_REQUEST["Bcode"];
/*$ISBN = $_REQUEST["ISBN"];
$Rname = $_REQUEST["Rname"];
$Bname = $_REQUEST["Bname"];*/

$sql = "SELECT Rid,Bcode,BorrowDate,Deadline,Renewline,Penalty FROM borrowing WHERE";

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

//    $sql = "SELECT * FROM reader WHERE Rid='11510082'";

    $result = $conn -> query($sql);

    $response = "";

    while ($row = mysqli_fetch_array($result)) {
        $penalty = $row["Penalty"];
        $gotRid = $row["Rid"];
        $gotBcode= $row["Bcode"];

        $rnid = "bl|".$gotRid."-".$gotBcode."|Renewline";


        $response = $response."<tr><td onclick='change_bl_detail_modal(\"$gotRid\",\"$gotBcode\")'
 data-toggle=\"modal\" data-target=\"#bl_detail_Modal\">".$gotRid."</td><td
  onclick='change_bl_detail_modal(\"$gotRid\",\"$gotBcode\")' data-toggle=\"modal\" data-target=\"#bl_detail_Modal\">"
            .$row["Bcode"]."</td><td onclick='change_bl_detail_modal(\"$gotRid\",\"$gotBcode\")'
  data-toggle=\"modal\" data-target=\"#bl_detail_Modal\">".$row["BorrowDate"]."</td>
  <td ondblclick='modify_td(\"$rnid\")'>".$row["Renewline"]."</td><td><input type='button' class='return_button search-book'
   id='rb_".$gotRid.$gotBcode."' onclick='return_book(\"$gotRid\", \"$gotBcode\")' value='还书'>";

        if ($penalty == 0){
            $response = $response."</td></tr>";
        }else{
            $response = $response." | <input type='button' class='return_button search-book' id='pe_".$gotRid.$gotBcode."' disabled='disabled' onclick='set_penalty(\"$gotRid\", \"$gotBcode\")' value='￥".$penalty."'></td></tr>";
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