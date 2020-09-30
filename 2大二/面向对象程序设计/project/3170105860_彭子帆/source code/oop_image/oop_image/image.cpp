#include "header.h"
#include "menu.h"
#include "factor.h"

void Menu::add_image_function()
{
    QPainter painter(image);
    painter.setPen(QPen(Qt::blue,4,Qt::SolidLine));
    switch (image_mode)
    {
        case ecllipse_mode:
            painter.drawEllipse(current_pos_x,current_pos_y,current_width,current_height);;
            break;
        case rectangular_mode:
            painter.drawRoundRect(current_pos_x,current_pos_y,current_width,current_height,50,50);
            break;
    }
}

void Menu::reset()
{
    if(image->isNull())     return;
    delete image;
    image = new QImage(initial_image);
    update_picture();
}

