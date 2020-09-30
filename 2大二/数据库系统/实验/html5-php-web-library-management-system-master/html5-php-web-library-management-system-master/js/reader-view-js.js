$(document).ready(function () {
    $("#retrieve_reader_button").click(function () {
        try {
            var rid = document.getElementById("input_rid").value;
        }catch (e){
            rid = "";
        }

        try {
            var rname= document.getElementById("input_rname").value;
        }catch (e){
            rname = "";
        }

        try {
            var gendert = document.getElementById("select_gender").value;
            var gender = "";
            if (gendert == "女"){
                gender = 1;
            }else if (gendert == "男"){
                gender = 0;
            }

        }catch (e){
            gender = "";
        }

        try {
            var card = "";
            var cardt = document.getElementById("select_card_status").value;
            if (cardt == "无证"){
                card = 0;
            }else if (cardt == "挂失"){
                card = 2;
            }else if (cardt == "正常"){
                card = 1;
            }
        }catch (e){
            card = "";
        }

        $.post("control/query_reader.php",
            {
                Rid:rid,
                Rname:rname,
                Gender:gender,
                CardStatus:card
            },
            function(data,status){
                document.getElementById("reader-list-table-body").innerHTML = data;
            });

    });
});


function change_reader_detail_modal(rid) {
    $.post("control/reader_query_detail.php",{
            Rid:rid
        },
        function (data, status) {
            document.getElementById("book_detail_modal_body").innerHTML = data;
        });
}

function set_reader_arrearage(rid) {
    $.post("control/set_reader_arrearage.php",{
            Rid:rid
        },
        function (data, status) {
        // alert(data);
        if (data.indexOf("缴纳成功") > -1){
            document.getElementById("ar_"+rid).disabled = true;
        }else if (data.indexOf("不能缴纳欠款") > -1){
            alert("该读者有过期未还图书，不能缴纳欠款");
            return null;
        }else {
            alert("出错了");
            return null;
        }
        });
}