<?php
require "connect_to_DB.php";

$html = $_REQUEST["HTML"];
$value = $_REQUEST["Value"];
$Prima = $_REQUEST["Prima"];
$Attr = $_REQUEST["Attr"];
$Prima1 = $_REQUEST["Prima1"];

if ($html == "book"){
    $sql = "UPDATE library SET ".$Attr."='$value' WHERE ISBN='$Prima'";

    $r = $conn -> query($sql);

    while ($row = mysqli_fetch_array($r)){
    }
}elseif ($html == "reader"){
    if ($Attr == "CardStatus"){
        if ($value == "无证"){
            $value = 0;
        }elseif ($value == "正常"){
            $value = 1;
        }elseif ($value == "挂失"){
            $value = 2;
        }
    }

    $sql = "UPDATE reader SET ".$Attr."='$value' WHERE Rid='$Prima'";
    $r = $conn ->query($sql);
    while ($row = mysqli_fetch_array($r)){

    }

}elseif ($html == "bl"){
    $sql = "UPDATE borrowing SET ".$Attr."='$value' WHERE Rid='$Prima' AND Bcode='$Prima1'";
    $r = $conn -> query($sql);
    while ($row = mysqli_fetch_array($r)){};
}elseif ($html = "book1"){
    $sql = "UPDATE book SET position='$value' WHERE ISBN='$Prima' AND Bcode='$Prima1'";
    /*if ($value == "在馆"){
        $sql = "UPDATE book SET ".$Attr."=1 WHERE Bcode='$Prima' AND ISBN='$Prima1'";
    }elseif ($value == "借出"){
        $sql = "UPDATE book SET ".$Attr."=0 WHERE Bcode='$Prima' AND ISBN='$Prima1'";
    }*/
    $r = $conn ->query($sql);
    while ($row = mysqli_fetch_array($r)){};
}

if ($r){
    echo $sql."修改成功";
}else{
    echo $sql."修改失败";
}


?>