$(document).ready(function () {
    $("#retrieve_history_button").click(function () {
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

        $.post("control/history_query.php",
            {
                Rid: rid,
                Bcode: barcode,
                ISBN: isbn,
                Rname: rname,
                Bname: book_name
            },
            function (data, status) {
                document.getElementById("history-list-table-body").innerHTML = data;
            });

    });



});

function set_penalty_hy(rid, bcode, borrowdate) {
    $.post("control/set_book_penalty.php",{
        Rid:rid,
        Bcode:bcode
    },function (data, status) {
        if (data.indexOf("缴纳成功") > -1){
            document.getElementById("hy_"+rid+bcode+borrowdate).disabled = true;
        }else {
            alert("缴纳失败");
        }
    })
}
