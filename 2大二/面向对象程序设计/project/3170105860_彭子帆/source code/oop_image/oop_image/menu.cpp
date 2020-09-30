#include "menu.h"
#include "ui_menu.h"
#include "factor.h"
Menu::Menu(QWidget *parent) :QMainWindow(parent),ui(new Ui::Menu)
{
    ui->setupUi(this);
    current_pos_x = default_xpos;
    current_pos_y = default_ypos;
    current_width = default_width;
    current_height = default_height;
    split_mode_button = 0;
    image_mode_button = 0;
}


Menu::~Menu()
{
    delete ui;
    if(!image->isNull())
        delete image;
    if(!scene)
        delete scene;
    if(!histgram)
        delete histgram;
    if(!histgram_picture)
        delete histgram_picture;
    if(!hist_scene)
        delete hist_scene;
}


void Menu::on_open_image_clicked()
{
    open_image_funtion();
    ui->graphics_view->setScene(scene);
    ui->graphics_view->resize(400, 400);
    ui->graphics_view->show();

}


void Menu::wheelEvent(QWheelEvent *event)
{
    if(image->isNull())     return;
    ui->graphics_view->scale(1 / zoom_value, 1 / zoom_value);
    zoom_in_or_out = event->delta();
    zoom_funtion();
    ui->graphics_view->scale(zoom_value,zoom_value);
}


void Menu::on_luminance_image_valueChanged(int arg1)
{
    if(image->isNull())     return;
    bright_value = arg1;
    luminance_funtion();
    update_picture();
}


void Menu::on_saturation_image_valueChanged(double arg1)
{
    if(image->isNull())     return;
    saturation_value = arg1 / 20;
    saturation_funtion();
    update_picture();
}


void Menu::on_contrast_image_valueChanged(int arg1)
{
    if(image->isNull())     return;
    contrast_value = arg1 / 20.0;
    contrast_funtion();
    update_picture();
}


void Menu::update_picture()
{
    if(image->isNull())     return;
    delete scene;
    scene = new QGraphicsScene;
    scene->addPixmap(QPixmap::fromImage(*image));
    ui->graphics_view->setScene(scene);
    ui->graphics_view->resize(400, 400);
    ui->graphics_view->show();
}


void Menu::on_Reset_clicked()
{
    reset();
}


void Menu::on_save_image_clicked()
{
    if(image->isNull())     return;
    // use FileDialog to capture the saving path
    QString save_filepath = QFileDialog::getSaveFileName(this,tr("Save Image"),"",tr("Images (*.png *.bmp *.jpg)"));
    // similar to capature the screen
    QScreen *screen = QGuiApplication::primaryScreen();
    screen->grabWindow(image->save(save_filepath));
    QMessageBox::information(this,"Success","Success to save the picture");
}


void Menu::on_rotate_clicked()
{
    if(image->isNull())     return;
    QMatrix angle_rotate;
    angle_rotate.rotate(10);
    *image = image->transformed(angle_rotate,Qt::SmoothTransformation);
    update_picture();
}


void Menu::on_zoom_in_image_clicked()
{
    if(image->isNull())     return;
    ui->graphics_view->scale(1 / zoom_value, 1 / zoom_value);
    zoom_in_or_out = 1;
    zoom_funtion();
    ui->graphics_view->scale(zoom_value,zoom_value);
}


void Menu::on_zoom_out_image_clicked()
{
    if(image->isNull())     return;
    ui->graphics_view->scale(1 / zoom_value, 1 / zoom_value);
    zoom_in_or_out = -1;
    zoom_funtion();
    ui->graphics_view->scale(zoom_value,zoom_value);
}


void Menu::on_split_image_clicked()
{
    QMessageBox::information(this,"Split","Press Q W E R to split the picture\nThey refers to the four corner of the image");
    split_mode_button = 1;
}


void Menu::keyPressEvent(QKeyEvent *event)
{
    if(image->isNull())     return;
    if(split_mode_button)
    {
        switch (event->key())
        {
            case Key_Q:
                split_mode = left_up_corner;
                break;
            case Key_W:
                split_mode = right_up_corner;
                break;
            case Key_E:
                split_mode = left_down_corner;
                break;
            case Key_R:
                split_mode = right_down_corner;
                break;
        }
        split_mode_button = 0;
        split_picture();
        update_picture();
        return;
    }

    if(image_mode_button == 1)
    {
        reset();
        switch (event->key())
        {
            case Key_A:
                reset();
                current_pos_x -= 10;
                break;
            case Key_D:
                reset();
                current_pos_x += 10;
                break;
            case Key_W:
                reset();
                current_pos_y -= 10;
                break;
            case Key_S:
               // image_initial_set();
                current_pos_y += 10;
                break;
            case Key_L:
                image_mode_button = -1;
                break;
            case Key_J:
                current_width += 10;
                break;
            case Key_K:
                current_height += 10;
                break;
        }
            add_image_function();
            update_picture();
    }
}


void Menu::on_Water_mark_image_clicked()
{
    water_mark_function();
    update_picture();
}


void Menu::on_Histogram_clicked()
{
    if(image->isNull())     return;
    if(!hist_scene) delete hist_scene;

    hist_scene = new QGraphicsScene;
    get_histogram_function();
    paint_histogram_function();

    hist_scene->addPixmap(QPixmap::fromImage(*histgram_picture));
    ui->hist_view->setScene(hist_scene);
    ui->hist_view->scale(0.25,0.25);
    ui->hist_view->resize(161, 161);
    ui->hist_view->show();
}


void Menu::on_ellipse_clicked()
{
    if(image->isNull())     return;
    image_mode_button = 1;
    image_mode = ecllipse_mode;
}


void Menu::on_rectangular_clicked()
{
    if(image->isNull())     return;
    image_mode_button = 1;
    image_mode = rectangular_mode;
}




void Menu::on_picturemark_clicked()
{
    if(image->isNull()) return;
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
    mark_picture = new QImage(file_name);

    if(mark_picture->isNull())
        return;
    picture_mark_function();
    update_picture();
}
