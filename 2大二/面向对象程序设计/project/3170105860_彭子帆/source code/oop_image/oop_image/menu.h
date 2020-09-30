#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "header.h"
using namespace Qt;
namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    ~Menu();


public Q_SLOT:


private slots:
    void on_open_image_clicked();                           //open-image button
    void on_luminance_image_valueChanged(int arg1);         //luminance-image spin box
    void on_saturation_image_valueChanged(double arg1);     //saturation-image spin box
    void on_contrast_image_valueChanged(int arg1);          //contrast-image spin box
    void on_Reset_clicked();                                //reset-image button
    void on_save_image_clicked();                           //save-image button
    void on_rotate_clicked();                               //rotate-image button
    void on_zoom_in_image_clicked();                        //zoom-in-image button
    void on_zoom_out_image_clicked();                       //zoom-out-image button
    void on_split_image_clicked();                          //split-image button
    void on_Water_mark_image_clicked();                     //water_mark-image button
    void on_Histogram_clicked();                            //histogram_image button
    void on_ellipse_clicked();                              //ellipse-image button
    void on_rectangular_clicked();                          //rectangular_image button
    void on_picturemark_clicked();                          //picture_mark_button

private:
    Ui::Menu* ui;               // point to the UI of the Menu
    QImage* image;              // save the image loaded in
    QImage initial_image;       // save the initial image
    QImage* histgram_picture;   // save the picture of histogram
    QImage* mark_picture;       // save the picture of histogram
    QGraphicsScene* scene;      // save the picture view;
    QGraphicsScene* hist_scene; // save the histogram view
    qreal zoom_value = 1;       // save the current zoom value
    int   bright_value;         // save the brightness of picture
    int   last_bright_value;    // save the current brightness of picture
    double saturation_value;    // save the saturation of picture
    float contrast_value;       // save the contrast of picture
    qreal zoom_in_or_out;       // save the value of zoom
    int   split_mode;           // save the split mode
    int   split_mode_button;    // save whether to split
    QVector<int>* histgram;     // save the histgram of the picture
    int image_mode;             // save the image mode
    int current_pos_x;          // save the start of image x axis
    int current_pos_y;          // save the start of image y axis
    int current_width;          // save image width
    int current_height;         // save image height
    int paint_size;             // save painter height
    int image_mode_button;      // image_mode_button
private:
    void open_image_funtion();          // underlying logic open-image function
    void zoom_funtion();                // underlying logic zoom function
    void luminance_funtion();           // underlying logic luminance funciton
    void saturation_funtion();          // underlying logic saturation funciton
    void contrast_funtion();            // underlying logic saturation funciton
    void update_picture();              // update picutre after fixing
    void split_picture();               // underlying logic split picture function
    void water_mark_function();         // underlying logic water_mark_function
    void get_histogram_function();      // underlying logic calculate histogram function
    void paint_histogram_function();    // underlying logic paint the histogram picture function
    void add_image_function();          // underlying logic ellipse/rectangular function
    void image_update_picture();
    void reset();                       // underlying initial image function
    void picture_mark_function();       // underlying initial image function
};

#endif // MENU_H
