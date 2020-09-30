#include <factor.h>
#include <menu.h>
#include <header.h>


void Menu::water_mark_function()
{
    image = new QImage;
    *image = initial_image.copy(0,0,initial_image.width(),initial_image.height());
    QPainter painter(image);
    int start_x = image->width() / 10;
    int start_y = image->height() / 10;

    // first fill into the picture as the ground
    painter.fillRect(start_x,start_y,start_x + 150,start_y + 45,Qt::transparent);
    // set the word written into the picture
    QFont ft = painter.font();
    ft.setPixelSize(40);
    painter.setFont(ft);
    painter.drawText(start_x,start_y,start_x + 360,start_y + 45,Qt::AlignLeft,"Sing,dance,rap");

    QRgb rgbSrc,rgbMark;
    int r,g,b;
    float alpha = 0.6, beta = 1- alpha;

    // write into the picture pixel by pixel
    // simliar to contrast\luminance\saturate function
    for(int x = 0; x < image->width(); x++)
    {
       for(int y = 0; y < image->height(); y++)
       {
            rgbSrc = image->pixel(x,y);
            rgbMark = image->pixel(x,y);

            // calcate the red\green\blue value of each pixel
            r = int(qRed(rgbSrc) * alpha + qRed(rgbMark) * beta);
            g = int(qGreen(rgbSrc) * alpha + qGreen(rgbMark) * beta);
            b = int(qBlue(rgbSrc) * alpha + qBlue(rgbMark) * beta);

            // to prevent overflow or underflow
            // each range from 0 to 255
            r = (0 <= r && r <= 255) ? r : 0;
            g = (0 <= g && g <= 255) ? g : 0;
            b = (0 <= b && b <= 255) ? b : 0;
            // write into the pixel
            image->setPixel(x,y,qRgb(r,g,b));
      }
   }

}
