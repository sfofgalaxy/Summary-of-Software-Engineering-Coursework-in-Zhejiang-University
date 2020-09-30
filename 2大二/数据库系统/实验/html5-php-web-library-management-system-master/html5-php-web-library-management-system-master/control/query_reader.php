<?php
require "connect_to_DB.php";

$Rid = $_REQUEST["Rid"];
$Rname = $_REQUEST["Rname"];
$Gender = $_REQUEST["Gender"];
$CardStatus = $_REQUEST["CardStatus"];

$sql = "SELECT Rid,Rname,Rpassword,Arrearage,CardStatus,Gender FROM reader WHERE";

$hasone = false;
if ($Rid != ""){
    if ($hasone){
        $sql = $sql." AND Rid='$Rid'";
    }else{
        $sql = $sql." Rid='$Rid'";
        $hasone = true;
    }
}
if ($Rname != ""){
    if ($hasone){
        $sql = $sql." AND Rname='$Rname'";
    }else{
        $sql = $sql." Rname='$Rname'";
        $hasone = true;
    }
}
if ($Gender != ""){
    if ($hasone){
        $sql = $sql." AND Gender='$Gender'";
    }else{
        $sql = $sql." Gender='$Gender'";
        $hasone = true;
    }
}
if ($CardStatus != ""){
    if ($hasone){
        $sql = $sql." AND CardStatus='$CardStatus'";
    }else{
        $sql = $sql." CardStatus='$CardStatus'";
        $hasone = true;
    }
}

if ($hasone){

//    $sql = "SELECT * FROM reader WHERE Rid='11510082'";

    $result = $conn -> query($sql);

    $response = "";

    while ($row = mysqli_fetch_array($result)) {
        $Rid = $row["Rid"];
        $Arrearage = $row["Arrearage"];

        if ($row["Gender"] == 1){
            $gender = "女";
        }else{
            $gender = "男";
        }

        if ($row["CardStatus"] == 0){
            $card = "无证";
        }elseif ($row["CardStatus"] == 1){
            $card = "正常";
        }else{
            $card = "挂失";
        }

        $rnameid = "reader|".$Rid."|Rname";
        $rpwdid = "reader|".$Rid."|Rpassword";
        $cardstatusid = "reader|".$Rid."|CardStatus";
        $arrearage = "reader|".$Rid."|Arrearage";
        $genderid = "reader|".$Rid."|Gender";

        $response = $response."<tr><td onclick='change_reader_detail_modal(\"$Rid\")' data-toggle=\"modal\" data-target=\"#reader_detail_Modal\">".$Rid."</td><td ondblclick='modify_td(\"$rnameid\")'>"
            .$row["Rname"]."</td><td ondblclick='modify_td(\"$genderid\")'>".$gender."</td><td onclick='modify_td(\"$rpwdid\")'>".$row["Rpassword"]
            ."</td><td onclick='modify_td(\"$cardstatusid\")'>".$card."</td>";

        if ($Arrearage == 0){
            $response = $response."<td>无欠款</td></tr>";
        }elseif ($Arrearage > 0){
            $response = $response."<td onclick='modify_td(\"$arrearage\")'><input type='button' class='return_button search-book' style='width:60px;' id='ar_".$Rid."' value='￥".$Arrearage."' onclick='set_reader_arrearage(\"$Rid\")'></td></tr>";
        }else{
            $response = $response."<td>错误</td></tr>";
        }


    }

    if ($response != ""){
        echo $response;
    }else{
        echo "没有查询到读者。";
    }
}else{
    echo "请输入至少一条搜索条件";
}

?>