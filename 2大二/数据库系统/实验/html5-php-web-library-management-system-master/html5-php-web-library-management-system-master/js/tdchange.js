var tbclass = ".tbcontainer";
var inputfomate = "<input type='text' style='text-align: center'/>";
var pre = null;
var tdinputselection = "";
var keyed = null;
var orvalue = null;
var ht = "temp";
var rowv = "temp";
var rowv1 = "";
var colv = "temp";

function getSelectionStart(o) {
    if (o.createTextRange) {
        var r = document.selection.createRange().duplicate();
        r.moveEnd('character', o.value.length);
        if (r.text == '') return o.value.length;
        return o.value.lastIndexOf(r.text);
    } else return o.selectionStart;
}

function getSelectedText() {
    if (window.getSelection) {
        return window.getSelection().toString();
    }
    else if (document.getSelection) {
        return document.getSelection();
    }
    else if (document.selection) {
        return document.selection.createRange().text;
    }
}

$(function () {
    $(tbclass).dblclick(function (e) {
        stopevent(e);
        var cur = e.target;
        if ($(cur).is("td")) {
            // alert("是td表格");
            if (ht == "book") {
                if (colv == "ISBN" || colv == "Bname") {
                    stp();
                    return null;
                } else {
                    switchtdinput(cur);
                }
            } else if (ht == "reader") {
                if (colv == "Rid" || colv == "Rname" || colv == "Gender" || colv == "Arrearage") {
                    stp();
                    return null;
                } else {
                    switchtdinput(cur);
                }

            } else if (ht == "bl") {
                if (colv=="Renewline"){
                    switchtdinput(cur);
                }else {
                    stp();
                    return null;
                }
            }else if (ht == "book1"){
                // alert(ht);
                // alert(colv);
                if (colv == "position"){
                    // alert("通过验证");
                    switchtdinput(cur);
                }else {
                    stp();
                    return null;
                }
            }

            else {
                stp();
                return null;
            }

        }
    });
    $(tbclass).find("tr").each(function () {
        $(this).find("td").each(function (i) {
            $(this).data("i", i);
        });
    });
});

function stp() {
    ht = "temp";
    colv = 'temp';
    rowv = 'temp';
    rowv1 = "";
}

function switchtdinput(obj) {
    if (pre) doinpleave(pre);
    orvalue = obj.innerHTML;
    var width = $(obj).width() * 0.4;
    var objtxt = $.trim($(obj).text());
    $(obj).html($(inputfomate).val(objtxt));
    pre = $(obj).find('input').css("border", "1px solid red").width(width)[0];
    $(obj).find('input').trigger("focus").trigger("select");
    $(obj).find('input').click(function (event) {
        stopevent(event);
        return false;
    }).blur(function (event) {
        inpleave(event, this);
    }).keypress(function (event) {
        keypress13(event, this);
    }).keyup(function (event) {
        return setpreornext(event, this);
    }).keydown(function (event) {
        tdinputselection = getSelectedText();
        stopevent(event);
    });
}

function stopevent(event) {
    event.stopPropagation();
}

function modify_td(rc) {
    var l = rc.split("|");
    ht = l[0];
    rowv = l[1];
    colv = l[2];
    if (ht == "bl" || ht == "book1"){
        var l1 = rowv.split("-");
        rowv1 = l1[1];
        rowv = l1[0];
    }
    // alert("ht:"+ht+"\nrowv:"+rowv+"\nrowv1"+rowv1+"\ncolv:"+colv);
}

function keypress13(event, obj) {

    if (event.keyCode == 13) {
        var v = obj.value;
        // alert("ht:"+ht+"\nrowv:"+rowv+"\nrowv1"+rowv1+"\ncolv:"+colv+"\nvalue:"+v);
        // alert("value:" + v);

        $.post("control/update_tables.php",
            {
                HTML: ht,
                Prima: rowv,
                Prima1: rowv1,
                Attr: colv,
                Value: v
            },
            function (data, status) {
            // alert(data);
                if (data.indexOf("修改成功")){
                    keyed = true;
                    doinpleave(obj);
                }else{
                    keyed = false;
                    doinpleave(obj);
                    alert(data)
                }
                // alert(data);
            });
    }
}

function inpleave(event, obj) {
    stopevent(event);
    doinpleave(obj);
}

function doinpleave(obj) {
    if (!obj) return;
    var val = $(obj).val();
    var $par = $(obj).parent()[0];
    if (keyed) {
        $($par).text(val);
    } else {
        $($par).text(orvalue);
    }
    pre = null;
    keyed = false;
    stp();
}

function setpreornext(event, objThis) {
    var count = -1;
    stopevent(event);
    var obj;
    if (event.keyCode == 40 || event.which == 40 || event.keyCode == 38 || event.which == 38 || event.keyCode == 13 || event.which == 13 || event.keyCode == 37 || event.which == 37 || event.keyCode == 39 || event.which == 39) {
        count = parseInt($(objThis).parent().data("i"));
        if (event.keyCode == 40 || event.which == 40) {
            obj = $(objThis).parent().parent().next("tr").find("td").get(count);
        } else if (event.keyCode == 38 || event.which == 38) {
            obj = $(objThis).parent().parent().prev("tr").find("td").get(count);
        } else if (event.keyCode == 13 || event.which == 13) {
            obj = $(objThis).parent().parent().find("td").get(count + 1);
        }
        else if (event.keyCode == 37 || event.which == 37) {
            if (getSelectionStart(objThis) == 0 && (tdinputselection != $(objThis).val())) {
                obj = $(objThis).parent().parent().find("td").get(count - 1);
            }
        }
        else if (event.keyCode == 39 || event.which == 39) {
            if (getSelectionStart(objThis) == $(objThis).val().length && (tdinputselection != $(objThis).val()))
                obj = $(objThis).parent().parent().find("td").get(count + 1);
        }
        if (obj) {
            doinpleave(objThis);
            switchtdinput(obj);
        }
    }
    if (event.keyCode == 13 || event.which == 13) return false;
    else return true;

}