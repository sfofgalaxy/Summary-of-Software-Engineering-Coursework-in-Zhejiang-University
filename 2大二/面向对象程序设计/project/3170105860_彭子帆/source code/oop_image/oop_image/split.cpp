#include <factor.h>
#include <menu.h>
#include <header.h>


void Menu::split_picture()
{
    switch (split_mode)
    {
        case left_up_corner:
            *image = image->copy(0,0,image->width() / 2,image->height() / 2);
            break;
        case right_up_corner:
            *image = image->copy(image->width() / 2,0,image->width(),image->height() / 2);
            break;
        case left_down_corner:
            *image = image->copy(0,image->height() / 2,image->width() / 2,image->height());
            break;
        case right_down_corner:
            *image = image->copy(image->width() / 2,image->height() / 2,image->width(),image->height());
            break;
    }
}
