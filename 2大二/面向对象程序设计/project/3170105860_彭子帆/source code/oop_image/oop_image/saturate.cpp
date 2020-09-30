#include <factor.h>
#include <menu.h>
#include <header.h>


void Menu::saturation_funtion()
{
    // similar to luminace function
    // red, green,blue refer to Mitaka colored passage
    // calculate the whole number of pixels
    int red, green, blue, nRed, nGreen, nBlue;
    int pixels = image->width() * image->height();
    unsigned int *data = (unsigned int *)image->bits();

    double delta = 0, minVal, maxVal, L, S,alpha;

    for (int i = 0; i < pixels; ++i)
    {
        // calculate the red, green, blue passage value again
        nRed = qRed(data[i]);
        nGreen = qGreen(data[i]);
        nBlue = qBlue(data[i]);

        // calcuate the minvalue of whole rgb
        minVal = std::min(std::min(nRed, nGreen), nBlue);
        maxVal = std::max(std::max(nRed, nGreen), nBlue);

        delta = (maxVal - minVal) / 255.0;
        L = 0.5*(maxVal + minVal) / 255.0;

        S = (0.5 * delta / L > 0.5 * delta / (1 - L)) ? (0.5*delta / L) : (0.5 * delta / (1 - L));

        // calculate the ratio
        alpha = (S > 1 -saturation_value) ? S : 1 - saturation_value;
        alpha = 1.0 / alpha - 1;

        // adjust the corresponding rgb value according to alpha
        red = nRed + (nRed - L*255.0)*alpha;
        red = (red < 0x00) ? 0x00 : (red > 0xff) ? 0xff : red;
        green = nGreen + (nGreen - L*255.0)*alpha;
        green = (green < 0x00) ? 0x00 : (green > 0xff) ? 0xff : green;
        blue = nBlue + (nBlue - L*255.0)*alpha;
        blue = (blue < 0x00) ? 0x00 : (blue > 0xff) ? 0xff : blue;

        // change the data of picture
        data[i] = qRgba(red, green, blue, qAlpha(data[i]));
    }
}
