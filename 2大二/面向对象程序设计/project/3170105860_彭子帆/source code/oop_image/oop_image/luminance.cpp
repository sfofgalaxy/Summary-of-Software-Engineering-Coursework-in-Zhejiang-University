#include <factor.h>
#include <menu.h>
#include <header.h>


void Menu::luminance_funtion()
{
    // red, green,blue refer to Mitaka colored passage
    int red,green,blue;

    // calculate the whole number of pixels
    int pixels = image->width() * image->height();

    unsigned int *image_data = (unsigned int *)image->bits();

    for (int i = 0; i < pixels; ++i)
    {
        // the value of rgb should within 0-255
        // change the unproper number
        red= qRed(image_data[i])+ bright_value;
        red = (red < 0x00) ? 0x00 : (red > 0xff) ? 0xff : red;

        green= qGreen(image_data[i]) + bright_value;
        green = (green < 0x00) ? 0x00 : (green > 0xff) ? 0xff : green;

        blue= qBlue(image_data[i]) + bright_value;
        blue =  (blue  < 0x00) ? 0x00 : (blue  > 0xff) ? 0xff : blue ;

        image_data[i] = qRgba(red, green, blue, qAlpha(image_data[i]));
    }

}
