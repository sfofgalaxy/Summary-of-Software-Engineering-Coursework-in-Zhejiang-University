<?php
require "connect_to_DB.php";

$ISBN = $_REQUEST["ISBN"];
$Category = $_REQUEST["Category"];
$book_name = $_REQUEST["Bname"];
$author = $_REQUEST["Author"];

$sql = "SELECT ISBN,Bname,Category,cover,Author,Press,Amount,InAmount,TotalBrw FROM library WHERE";

$hasone = false;
if ($ISBN != ""){
    if ($hasone){
        $sql = $sql." AND ISBN='$ISBN'";
    }else{
        $sql = $sql." ISBN='$ISBN'";
        $hasone = true;
    }
}
if ($book_name != ""){
    if ($hasone){
        $sql = $sql." AND Bname='$book_name'";
    }else{
        $sql = $sql." Bname='$book_name'";
        $hasone = true;
    }
}
if ($author != ""){
    if ($hasone){
        $sql = $sql." AND Author='$author'";
    }else{
        $sql = $sql." Author='$author'";
        $hasone = true;
    }
}
if ($Category != ""){
    if ($hasone){
        $sql = $sql." AND Category='$Category'";
    }else{
        $sql = $sql." Category='$Category'";
        $hasone = true;
    }
}

if ($hasone){
    $result = $conn->query($sql);

    $response = "";

    while ($row = mysqli_fetch_array($result)) {
        $isbn = $row["ISBN"];
        $bnameid = "book|".$isbn."|Bname";
        $catid = "book|".$isbn."|Category";
        $authorid = "book|".$isbn."|Author";
        $pressid = "book|".$isbn."|Press";
        $inamountid = "book|".$isbn."|InAmount";
        $response = $response."<tr><td onclick='change_book_detail_modal(\"$isbn\")' data-toggle=\"modal\" data-target=\"#book_detail_Modal\">"
            .$isbn."</td><td ondblclick='modify_td(\"$bnameid\")'>".$row["Bname"]."</td><td onclick='modify_td(\"$catid\")'>"
            .$row["Category"]."</td><td onclick='modify_td(\"$authorid\")'>".$row["Author"]
            ."</td><td onclick='modify_td(\"$pressid\")'>".$row["Press"]."</td><td onclick='modify_td(\"$inamountid\")'>".$row["InAmount"]."</td></tr>";
    }

    if ($response != ""){
        echo $response;
    }else{
        echo "没有查询到图书。";
    }
}else{
    echo "请输入至少一条搜索条件";
}

?>