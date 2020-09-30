#include "menu.h"
#include "header.h"

void Menu::open_image_funtion()
{
    QStringList file_name_list;
    QString file_name;

    // Acquire the file name of the image
    file_name = QFileDialog::getOpenFileName(
                    this, tr("open image file"),
                    "./", tr("Image files(*.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm);;All files (*.*)"));

    // return when user cancel
    if(file_name.isEmpty())
        return;

    // case 2: open success
    image = new QImage(file_name);
    initial_image = *image;
    if(image->isNull())
        return;

    // create the scene and paint
    scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(*image));

}
