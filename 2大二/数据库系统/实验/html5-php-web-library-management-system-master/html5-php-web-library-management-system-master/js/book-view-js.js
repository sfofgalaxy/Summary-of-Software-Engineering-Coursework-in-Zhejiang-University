$(document).ready(function () {
    $("#retrieve_button").click(function () {
        try {
            var isbn = document.getElementById("input_ISBN").value;
        }catch (e){
            isbn = "";
        }

        try {
            var book_name = document.getElementById("input_book_name").value;
        }catch (e){
            book_name = "";
        }

        try {
            var author = document.getElementById("input_autdor").value;
        }catch (e){
            author = "";
        }

        try {
            var category = document.getElementById("select_category").value;
        }catch (e){
            category = "";
        }

        $.post("control/book_query.php",
            {
                ISBN:isbn,
                Bname:book_name,
                Author:author,
                Category:category
            },
            function(data,status){
                document.getElementById("book-list-table-body").innerHTML = data;
            });

    });

    $("#add_book").click(function () {
        try {
            adding_isbn = document.getElementById("adding_ISBN").value;
        }catch (e){
            alert("请输入ISBN");
        }
        try {
            var adding_bname = document.getElementById("adding_book_name").value;
        }catch (e){
            alert("请输入书名")
        }
        try {
            var adding_cover = document.getElementById("adding_cover").value;
                }catch (e){
            alert("请输入封面URL")
        }
        try {
            var adding_press = document.getElementById("adding_press").value;
                }catch (e){
            alert("请输入出版社")
        }
        try {
            var adding_author = document.getElementById("adding_author").value;
                }catch (e){
            alert("请输入作者")
        }
        try {
            var adding_category = document.getElementById("adding_category").value;
                }catch (e){
            alert("请输入")
        }
        try {
            var adding_bcode = document.getElementById("adding_Bcode").value;
                }catch (e){
            alert("请输入条码号")
        }
        try {
            var adding_position = document.getElementById("adding_position").value;
                }catch (e){
            alert("请输入位置")
        }

        if (adding_isbn == "")
            alert("请输入ISBN");
        else if (adding_bname == "")
            alert("请输入书名");
        else if (adding_cover == "")
            alert("请输入封面链接");
        else if (adding_press == "")
            alert("请输入出版社");
        else if (adding_author == "")
            alert("请输入作者");
        else if (adding_category == "")
            alert("请选择类目");
        else if (adding_bcode == "")
            alert("请输入条形码号");
        else if (position == "")
            alert("请输入图书位置");
        else {
            $.post("control/add_book.php",
                {
                    ISBN:adding_isbn,
                    Bname:adding_bname,
                    Cover:adding_cover,
                    Press:adding_press,
                    Author:adding_author,
                    Category:adding_category,
                    Bcode:adding_bcode,
                    position:adding_position
                },
                function(data,status){
                    alert("Data: " + data + "\nStatus: " + status);
                });
        }
    });




});

function change_book_detail_modal(isbn) {
    $.post("control/book_query_detail.php",{
            ISBN:isbn
        },
        function (data, status) {
            document.getElementById("book_detail_table_body").innerHTML = data;
        });
}

function getkey(inid, tdid) {
    alert("点击了");
    alert(inid);
    alert(tdid);
    // id = "modify_book_name_"+isbn;
    input_value = document.getElementById(inid);
    // tdid = ""+tdid+"haha";
    // alert("tdid:"+tdid);
    document.getElementById(tdid).innerHTML = input_value;



    /*alert("inputid:" + input_id + "\ntdid:" + tdid + "\nisbn:" + isbn);

    if (event.keyCode == 13){
        alert("按了回车");
        alert(input_id);
        var input = document.getElementById(input_id);
        var inputText = input.value;
        alert(inputText);
        alert(tdid);
        var tdins = document.getElementById(tdid);
        tdins.innerHTML = inputText;
        alert(tdins.innerHTML);
        input.remove();
    }*/
}

/*$(".td_input").blur(function () {
    v = $(this).value;
    alert(v);
});*/



/*function modify_book_name(tdid, isbn) {
    var tdins = document.getElementById(tdid);
    var text = tdins.innerHTML;
    var inid = "modify_book_name_"+isbn;
    fstring = "getkey('inid', 'tdid')";

    tdins.innerHTML = "<input id='"+inid+"' class='td_input' type='text' value='"+text+"'" +
        " style='text-align: center; width: "+tdins.width+"; height: "+tdins.height+"'/>" +
        "<input type='button' id='haha' value='提交' onclick='"+fstring+"'>";

    /!*var tn = document.getElementById(inid);

    alert(inid);

    alert("输入框即将消失");
    inputText = tn.value;
    tdins.innerHTML = inputText;*!/




    /!*tn.blur(function () {
        var inputText = tn.value;
        alert(tn.value);
        tdins.innerHTML = inputText;
    });*!/

}*/





