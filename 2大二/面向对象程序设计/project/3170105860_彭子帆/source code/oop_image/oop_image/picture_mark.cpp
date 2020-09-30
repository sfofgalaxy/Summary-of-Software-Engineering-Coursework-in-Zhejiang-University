#include "header.h"
#include "menu.h"
#include "factor.h"

void Menu::picture_mark_function()
{
    QColor color(255,255,255);  //白色
    QPainter imagepainter(image);  //新建画板
    imagepainter.setCompositionMode(QPainter::CompositionMode_SoftLight);   //设置重叠效果
    *mark_picture = mark_picture->scaledToWidth(50,Qt::SmoothTransformation);
    *mark_picture = mark_picture->scaledToWidth(50,Qt::SmoothTransformation);
    imagepainter.drawImage(0,0, *mark_picture);
    imagepainter.end();
}
