window.onload = function () {
    // $(".content-box").load("views/book_view.html");

    $('#myModal').on('shown.bs.modal', function () {
        $('#myInput').trigger('focus')
    });

    $('#book_detail_Modal').on('shown.bs.modal',function () {
        $('#myInput').trigger('focus')
    })

};


/*
function nochange(id, ih) {

    document.getElementById(id).blur();
    window.focus();
    /!*var ele = document.getElementById(id);
    ele.onfocus(function () {
        ele.innerHTML = ih;
    })*!/
}*/
