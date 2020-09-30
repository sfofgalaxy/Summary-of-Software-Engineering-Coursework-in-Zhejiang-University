<?php
require "connect_to_DB.php";

$Rid = $_REQUEST["Rid"];
$Bcode = $_REQUEST["Bcode"];
$Deadline = $_REQUEST["Deadline"];

$sql1 = "SELECT Rid,Arrearage FROM reader WHERE Rid='$Rid'";
$sql2 = "SELECT Bcode,ISBN FROM book WHERE Bcode='$Bcode'";

$result1 = $conn ->query($sql1);

$result2 = $conn ->query($sql2);

if(empty($result1)){
    echo "找不到该读者";
}
elseif (empty($result2)){
    echo "找不到这本书";
}
else{
    while ($row1 = mysqli_fetch_array($result1)){
        if ($row1["Arrearage"] != 0){
            echo "该读者有未缴纳的罚金";
        }
        else{
            while ($row2 = mysqli_fetch_array($result2)){
                $isbn = $row2["ISBN"];
            }

//            $conn->autocommit(FALSE);

//            $conn->begin_transaction(MYSQLI_TRANS_START_READ_ONLY);

            $sql = "INSERT INTO borrowing VALUES ('$Rid', '$Bcode', curdate(), date_add(curdate(),INTERVAL 1 MONTH), date_add(curdate(), INTERVAL 1 MONTH),0)";
            $sqla = "UPDATE book set Status=0 WHERE Bcode='$Bcode'";
            $sqlb = "UPDATE library set InAmount=InAmount-1, TotalBrw=TotalBrw+1, Frequency=Frequency+1 WHERE ISBN=$isbn";

            $result = $conn -> query($sql);
//            $r1 = $conn -> affected_rows;
            $resulta = $conn -> query($sqla);
//            $r2 = $conn -> affected_rows;
            $resultb = $conn -> query($sqlb);
//            $r3 = $conn -> affected_rows;

            /*if ($r1>0 && $r2>0 && $r3>0){
                $conn ->commit();
                echo "借书成功";
            }else{
                $conn -> rollback();
                echo "借书出错";
            }*/

            echo "借书成功";

            $conn->close();

        }
    }
}

?>