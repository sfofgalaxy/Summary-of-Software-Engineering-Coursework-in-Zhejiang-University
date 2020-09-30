<?php
require "connect_to_DB.php";

$ht = $_REQUEST["HT"];

if ($ht == "book") {
    $sql = "SELECT ISBN,Bname,Category,cover,Author,Press,Amount,InAmount,TotalBrw FROM library";

    $result = $conn->query($sql);

    $response = "";

    while ($row = mysqli_fetch_array($result)) {
        $isbn = $row["ISBN"];
        $bnameid = "book|" . $isbn . "|Bname";
        $catid = "book|" . $isbn . "|Category";
        $authorid = "book|" . $isbn . "|Author";
        $pressid = "book|" . $isbn . "|Press";
        $inamountid = "book|" . $isbn . "|InAmount";
        $response = $response . "<tr><td onclick='change_book_detail_modal(\"$isbn\")' data-toggle=\"modal\" data-target=\"#book_detail_Modal\">"
            . $isbn . "</td><td ondblclick='modify_td(\"$bnameid\")'>" . $row["Bname"] . "</td><td onclick='modify_td(\"$catid\")'>"
            . $row["Category"] . "</td><td onclick='modify_td(\"$authorid\")'>" . $row["Author"]
            . "</td><td onclick='modify_td(\"$pressid\")'>" . $row["Press"] . "</td><td onclick='modify_td(\"$inamountid\")'>" . $row["InAmount"] . "</td></tr>";
    }

    echo $response;
} elseif ($ht == "reader") {
    $sql = "SELECT Rid,Rname,Rpassword,Arrearage,CardStatus,Gender FROM reader";


    $result = $conn->query($sql);

    $response = "";

    while ($row = mysqli_fetch_array($result)) {
        $Rid = $row["Rid"];
        $Arrearage = $row["Arrearage"];

        if ($row["Gender"] == 1) {
            $gender = "女";
        } else {
            $gender = "男";
        }

        if ($row["CardStatus"] == 0) {
            $card = "无证";
        } elseif ($row["CardStatus"] == 1) {
            $card = "正常";
        } else {
            $card = "挂失";
        }

        $rnameid = "reader|" . $Rid . "|Rname";
        $rpwdid = "reader|" . $Rid . "|Rpassword";
        $cardstatusid = "reader|" . $Rid . "|CardStatus";
        $arrearage = "reader|" . $Rid . "|Arrearage";
        $genderid = "reader|" . $Rid . "|Gender";

        $response = $response . "<tr><td onclick='change_reader_detail_modal(\"$Rid\")' data-toggle=\"modal\" data-target=\"#reader_detail_Modal\">" . $Rid . "</td><td ondblclick='modify_td(\"$rnameid\")'>"
            . $row["Rname"] . "</td><td ondblclick='modify_td(\"$genderid\")'>" . $gender . "</td><td onclick='modify_td(\"$rpwdid\")'>" . $row["Rpassword"]
            . "</td><td onclick='modify_td(\"$cardstatusid\")'>" . $card . "</td>";

        if ($Arrearage == 0) {
            $response = $response . "<td>无欠款</td></tr>";
        } elseif ($Arrearage > 0) {
            $response = $response . "<td onclick='modify_td(\"$arrearage\")'><input type='button' class='return_button search-book' style='width:60px;' id='ar_" . $Rid . "' value='￥" . $Arrearage . "' onclick='set_reader_arrearage(\"$Rid\")'></td></tr>";
        } else {
            $response = $response . "<td>错误</td></tr>";
        }


    }

    if ($response != "") {
        echo $response;
    }
} elseif ($ht == "bl") {

    $sql = "SELECT Rid,Bcode,BorrowDate,Deadline,Renewline,Penalty FROM borrowing";


    $result = $conn->query($sql);

    $response = "";

    while ($row = mysqli_fetch_array($result)) {
        $penalty = $row["Penalty"];
        $gotRid = $row["Rid"];
        $gotBcode = $row["Bcode"];

        $rnid = "bl|" . $gotRid . "-" . $gotBcode . "|Renewline";


        $response = $response . "<tr><td onclick='change_bl_detail_modal(\"$gotRid\",\"$gotBcode\")'
 data-toggle=\"modal\" data-target=\"#bl_detail_Modal\">" . $gotRid . "</td><td
  onclick='change_bl_detail_modal(\"$gotRid\",\"$gotBcode\")' data-toggle=\"modal\" data-target=\"#bl_detail_Modal\">"
            . $row["Bcode"] . "</td><td onclick='change_bl_detail_modal(\"$gotRid\",\"$gotBcode\")'
  data-toggle=\"modal\" data-target=\"#bl_detail_Modal\">" . $row["BorrowDate"] . "</td>
  <td ondblclick='modify_td(\"$rnid\")'>" . $row["Renewline"] . "</td><td><input type='button' class='return_button search-book'
   id='rb_" . $gotRid . $gotBcode . "' onclick='return_book(\"$gotRid\", \"$gotBcode\")' value='还书'>";

        if ($penalty == 0) {
            $response = $response . "</td></tr>";
        } else {
            $response = $response . " | <input type='button' class='return_button search-book' id='pe_" . $gotRid . $gotBcode . "' disabled='disabled' onclick='set_penalty(\"$gotRid\", \"$gotBcode\")' value='￥" . $penalty . "'></td></tr>";
        }


    }

    if ($response != "") {
        echo $response;
    }

} elseif ($ht == "history") {

    $sql = "SELECT Rid,Bcode,BorrowDate,ReturnDate,EndPenalty,Paid FROM returned";


    $result = $conn->query($sql);

    $response = "";

    while ($row = mysqli_fetch_array($result)) {
        $penalty = $row["EndPenalty"];
        $gotRid = $row["Rid"];
        $gotBcode = $row["Bcode"];
        $paid = $row["Paid"];
        $borrowdate = $row["BorrowDate"];

        $response = $response . "<tr></tr>";

        $response = $response . "<tr><td data-toggle=\"modal\" data-target=\"#history_Modal\">" . $gotRid . "</td><td data-toggle=\"modal\" data-target=\"#history_Modal\">"
            . $row["Bcode"] . "</td><td data-toggle=\"modal\" data-target=\"#history_Modal\">" . $row["BorrowDate"] . "</td><td data-toggle=\"modal\" data-target=\"#history_Modal\">" . $row["ReturnDate"]
            . "</td><td>" . $penalty . "</td><td>";

        if ($penalty == 0) {
            $response = $response . "无罚金</td></tr>";
        } else {
            if ($paid) {
                $response = $response . "已支付</td></tr>";
            } else {
                $response = $response . "<input type='button' class='return_button search-book' id='hy_" . $gotRid . $gotBcode . $borrowdate . "' onclick='set_penalty_hy(\"$gotRid\", \"$gotBcode\", \"$borrowdate\")' value='￥" . $penalty . "'></td></tr>";
            }
        }

    }

    if ($response != "") {
        echo $response;
    }

}


?>