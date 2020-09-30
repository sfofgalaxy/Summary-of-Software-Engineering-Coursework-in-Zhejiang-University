/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphics_view;
    QPushButton *open_image;
    QLabel *lumin_label;
    QSpinBox *luminance_image;
    QLabel *saturate_label;
    QDoubleSpinBox *saturation_image;
    QLabel *contrast;
    QSpinBox *contrast_image;
    QPushButton *Reset;
    QPushButton *save_image;
    QPushButton *rotate;
    QPushButton *zoom_in_image;
    QPushButton *zoom_out_image;
    QPushButton *split_image;
    QPushButton *Water_mark_image;
    QPushButton *Histogram;
    QGraphicsView *hist_view;
    QPushButton *ellipse;
    QPushButton *rectangular;
    QPushButton *picturemark;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(582, 649);
        centralWidget = new QWidget(Menu);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphics_view = new QGraphicsView(centralWidget);
        graphics_view->setObjectName(QString::fromUtf8("graphics_view"));
        graphics_view->setGeometry(QRect(10, 0, 400, 531));
        open_image = new QPushButton(centralWidget);
        open_image->setObjectName(QString::fromUtf8("open_image"));
        open_image->setGeometry(QRect(410, 0, 141, 32));
        lumin_label = new QLabel(centralWidget);
        lumin_label->setObjectName(QString::fromUtf8("lumin_label"));
        lumin_label->setGeometry(QRect(410, 30, 81, 21));
        lumin_label->setLayoutDirection(Qt::LeftToRight);
        luminance_image = new QSpinBox(centralWidget);
        luminance_image->setObjectName(QString::fromUtf8("luminance_image"));
        luminance_image->setGeometry(QRect(491, 30, 51, 22));
        saturate_label = new QLabel(centralWidget);
        saturate_label->setObjectName(QString::fromUtf8("saturate_label"));
        saturate_label->setGeometry(QRect(420, 60, 71, 21));
        saturation_image = new QDoubleSpinBox(centralWidget);
        saturation_image->setObjectName(QString::fromUtf8("saturation_image"));
        saturation_image->setGeometry(QRect(490, 60, 62, 22));
        contrast = new QLabel(centralWidget);
        contrast->setObjectName(QString::fromUtf8("contrast"));
        contrast->setGeometry(QRect(420, 90, 71, 21));
        contrast_image = new QSpinBox(centralWidget);
        contrast_image->setObjectName(QString::fromUtf8("contrast_image"));
        contrast_image->setGeometry(QRect(490, 90, 51, 22));
        Reset = new QPushButton(centralWidget);
        Reset->setObjectName(QString::fromUtf8("Reset"));
        Reset->setGeometry(QRect(420, 410, 131, 32));
        save_image = new QPushButton(centralWidget);
        save_image->setObjectName(QString::fromUtf8("save_image"));
        save_image->setGeometry(QRect(420, 380, 131, 32));
        rotate = new QPushButton(centralWidget);
        rotate->setObjectName(QString::fromUtf8("rotate"));
        rotate->setGeometry(QRect(420, 350, 131, 32));
        zoom_in_image = new QPushButton(centralWidget);
        zoom_in_image->setObjectName(QString::fromUtf8("zoom_in_image"));
        zoom_in_image->setGeometry(QRect(410, 120, 71, 32));
        zoom_out_image = new QPushButton(centralWidget);
        zoom_out_image->setObjectName(QString::fromUtf8("zoom_out_image"));
        zoom_out_image->setGeometry(QRect(500, 120, 81, 32));
        split_image = new QPushButton(centralWidget);
        split_image->setObjectName(QString::fromUtf8("split_image"));
        split_image->setGeometry(QRect(420, 320, 131, 32));
        Water_mark_image = new QPushButton(centralWidget);
        Water_mark_image->setObjectName(QString::fromUtf8("Water_mark_image"));
        Water_mark_image->setGeometry(QRect(420, 290, 131, 32));
        Histogram = new QPushButton(centralWidget);
        Histogram->setObjectName(QString::fromUtf8("Histogram"));
        Histogram->setGeometry(QRect(420, 260, 131, 32));
        hist_view = new QGraphicsView(centralWidget);
        hist_view->setObjectName(QString::fromUtf8("hist_view"));
        hist_view->setGeometry(QRect(420, 440, 161, 161));
        ellipse = new QPushButton(centralWidget);
        ellipse->setObjectName(QString::fromUtf8("ellipse"));
        ellipse->setGeometry(QRect(420, 230, 131, 32));
        rectangular = new QPushButton(centralWidget);
        rectangular->setObjectName(QString::fromUtf8("rectangular"));
        rectangular->setGeometry(QRect(420, 200, 131, 32));
        picturemark = new QPushButton(centralWidget);
        picturemark->setObjectName(QString::fromUtf8("picturemark"));
        picturemark->setGeometry(QRect(420, 170, 131, 32));
        Menu->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Menu);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 582, 26));
        Menu->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Menu);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Menu->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Menu);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Menu->setStatusBar(statusBar);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Menu", nullptr));
        open_image->setText(QApplication::translate("Menu", "Open", nullptr));
        lumin_label->setText(QApplication::translate("Menu", "   Luminance", nullptr));
        saturate_label->setText(QApplication::translate("Menu", "Saturation", nullptr));
        contrast->setText(QApplication::translate("Menu", "Contrast", nullptr));
        Reset->setText(QApplication::translate("Menu", "Reset", nullptr));
        save_image->setText(QApplication::translate("Menu", "Save", nullptr));
        rotate->setText(QApplication::translate("Menu", "Rotate", nullptr));
        zoom_in_image->setText(QApplication::translate("Menu", "Zoom in", nullptr));
        zoom_out_image->setText(QApplication::translate("Menu", "Zoom out", nullptr));
        split_image->setText(QApplication::translate("Menu", "Split", nullptr));
        Water_mark_image->setText(QApplication::translate("Menu", "Water mark", nullptr));
        Histogram->setText(QApplication::translate("Menu", "Histogram", nullptr));
        ellipse->setText(QApplication::translate("Menu", "Ellipse", nullptr));
        rectangular->setText(QApplication::translate("Menu", "Rectangular", nullptr));
        picturemark->setText(QApplication::translate("Menu", "picture mark", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
