#include"menu.h"
#include"factor.h"
#include"header.h"


void Menu::contrast_funtion()
{
    int pixels = image->width() * image->height();
    unsigned int *data = (unsigned int *)image->bits();

    int red, green, blue, nRed, nGreen, nBlue;


    float param = 1 / (1 - contrast_value) - 1;

    for (int i = 0; i < pixels; ++i)
    {
        nRed = qRed(data[i]);
        nGreen = qGreen(data[i]);
        nBlue = qBlue(data[i]);

        red = nRed + (nRed - 127) * param;
        red = (red < 0x00) ? 0x00 : (red > 0xff) ? 0xff : red;
        green = nGreen + (nGreen - 127) * param;
        green = (green < 0x00) ? 0x00 : (green > 0xff) ? 0xff : green;
        blue = nBlue + (nBlue - 127) * param;
        blue = (blue < 0x00) ? 0x00 : (blue > 0xff) ? 0xff : blue;

        data[i] = qRgba(red, green, blue, qAlpha(data[i]));
    }
}
