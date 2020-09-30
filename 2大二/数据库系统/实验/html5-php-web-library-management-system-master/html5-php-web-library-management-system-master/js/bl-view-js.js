var right = false;

$(document).ready(function () {
    $("#retrieve_bl_button").click(function () {
        try {
            var rid = document.getElementById("input_rid").value;
        } catch (e) {
            rid = "";
        }

        try {
            var barcode = document.getElementById("input_barcode").value;
        } catch (e){
            barcode = "";
        }

        try {
            var isbn = document.getElementById("input_isbn").value;
        } catch (e) {
            isbn = "";
        }

        try {
            var rname = document.getElementById("input_bname").value;
        }catch (e){
            rname = "";
        }

        try {
            var book_name = document.getElementById("input_bname").value;
        } catch (e) {
            book_name = "";
        }

        $.post("control/bl_query.php",
            {
                Rid: rid,
                Bcode: barcode,
                ISBN: isbn,
                Rname: rname,
                Bname: book_name
            },
            function (data, status) {
                document.getElementById("bl-list-table-body").innerHTML = data;
            });

    });

    $("#borrow_button").click(function () {
        var date1 = new Date();
        var date2 = new Date(date1);
        date2.setDate(date1.getDate() + 30);
        var y = date2.getFullYear();
        var m = date2.getMonth() + 1;
        var d = date2.getDate();

        var date = y + "-";

        if (m < 10){
            date += "0"+ m + "-";
        }else {
            date += m + "-";
        }

        if (d < 10){
            date += "0"+d;
        }else {
            date += d;
        }

        $('#borrow_deadline').val(date);


    });

    $("#borrow_book_button").click(function () {
        try {
            var borrow_rid = document.getElementById("borrow_rid").value;
        }catch (e){
            alert("请输入读者证号");
        }
        try {
            var borrow_bcode = document.getElementById("borrow_bcode").value;
        }catch (e){
            alert("请输入条形码号")
        }
        try {
            var borrow_deadline = document.getElementById("borrow_deadline").value;
        }catch (e){
            alert("请输入应还日期")
        }

        if (borrow_rid.length != 8){
            alert("请输入正确的读者证号");
            return null;
        }
        else if (borrow_bcode.length != 6){
            alert("请输入正确的条形码号");
            return null;
        }else if (!right){
            alert("该读者无权借书");
        }
        else if (borrow_deadline == "")
            alert("请输入应还日期");
        else {
            $.post("control/borrow_book.php",
                {
                    Rid:borrow_rid,
                    Bcode:borrow_bcode,
                    Deadline:borrow_deadline
                },
                function(data,status){
                });
        }
    })

});

function change_bl_detail_modal(rid, bcode) {
    // alert(penalty);
    // alert("rid:"+rid+"\nbcode:"+bcode);
    $.post("control/bl_detail.php",{
        Rid: rid,
        Bcode: bcode
    },function (data, status) {
        // alert(data);
        var l = data.split("|");
        var rname = l[0];
        var photo = l[1];
        var deadline = l[2];
        var rewnewline = l[3];
        document.getElementById("bl_reader_name").innerHTML = rname;
        document.getElementById("bl_photo").src = photo;
        document.getElementById("bl_deadline").innerHTML = deadline;
        if (deadline != rewnewline){
            document.getElementById("bl_renew").innerHTML = "续借后到期日期为:" + rewnewline;
        }
    })
}

function return_book(rid, bcode) {
    $.post("control/return_book.php",
        {
            Rid:rid,
            Bcode:bcode,
        },
        function(data,status){
        id = "rb_"+rid+bcode;
        document.getElementById(id).disabled = true;

        try{
            document.getElementById("pe_"+rid+bcode).disabled = false;
        }catch (e){
            return null;
            }


        });
}

function cl() {
    // alert("失去焦点");
    v = document.getElementById("borrow_rid").value;
    lab = document.getElementById("borrow_reader_right");
    if (v.length == 8){
        $.post("control/verify_right.php",{
            Rid: v
        },function (data, status) {
            // alert("status: "+ status+"\n"+data);
            if (data.indexOf("该读者无欠款，可以借书") > -1){
                lab.innerHTML = "可以借书";
                right = true;
            }else{
                lab.innerHTML = "无权借书";
                right = false;
            }
        })
    }else if (v.length != 0){
        lab.innerHTML = "请输入正确的读者证号";
    }else {
        lab.innerHTML = "";
    }
}

function set_penalty(rid, bcode) {
    $.post("control/set_book_penalty.php",{
        Rid:rid,
        Bcode:bcode
    },function (data, status) {
        if (data.indexOf("缴纳成功") > -1){
            document.getElementById("pe_"+rid+bcode).disabled = true;
        }else {
            alert("缴纳失败");
        }
    })
}
