/****************************************************************************
** Meta object code from reading C++ file 'menu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../oop_image/menu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'menu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Menu_t {
    QByteArrayData data[18];
    char stringdata0[374];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Menu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Menu_t qt_meta_stringdata_Menu = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Menu"
QT_MOC_LITERAL(1, 5, 21), // "on_open_image_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 31), // "on_luminance_image_valueChanged"
QT_MOC_LITERAL(4, 60, 4), // "arg1"
QT_MOC_LITERAL(5, 65, 32), // "on_saturation_image_valueChanged"
QT_MOC_LITERAL(6, 98, 30), // "on_contrast_image_valueChanged"
QT_MOC_LITERAL(7, 129, 16), // "on_Reset_clicked"
QT_MOC_LITERAL(8, 146, 21), // "on_save_image_clicked"
QT_MOC_LITERAL(9, 168, 17), // "on_rotate_clicked"
QT_MOC_LITERAL(10, 186, 24), // "on_zoom_in_image_clicked"
QT_MOC_LITERAL(11, 211, 25), // "on_zoom_out_image_clicked"
QT_MOC_LITERAL(12, 237, 22), // "on_split_image_clicked"
QT_MOC_LITERAL(13, 260, 27), // "on_Water_mark_image_clicked"
QT_MOC_LITERAL(14, 288, 20), // "on_Histogram_clicked"
QT_MOC_LITERAL(15, 309, 18), // "on_ellipse_clicked"
QT_MOC_LITERAL(16, 328, 22), // "on_rectangular_clicked"
QT_MOC_LITERAL(17, 351, 22) // "on_picturemark_clicked"

    },
    "Menu\0on_open_image_clicked\0\0"
    "on_luminance_image_valueChanged\0arg1\0"
    "on_saturation_image_valueChanged\0"
    "on_contrast_image_valueChanged\0"
    "on_Reset_clicked\0on_save_image_clicked\0"
    "on_rotate_clicked\0on_zoom_in_image_clicked\0"
    "on_zoom_out_image_clicked\0"
    "on_split_image_clicked\0"
    "on_Water_mark_image_clicked\0"
    "on_Histogram_clicked\0on_ellipse_clicked\0"
    "on_rectangular_clicked\0on_picturemark_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Menu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    1,   90,    2, 0x08 /* Private */,
       5,    1,   93,    2, 0x08 /* Private */,
       6,    1,   96,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Menu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Menu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_open_image_clicked(); break;
        case 1: _t->on_luminance_image_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_saturation_image_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_contrast_image_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_Reset_clicked(); break;
        case 5: _t->on_save_image_clicked(); break;
        case 6: _t->on_rotate_clicked(); break;
        case 7: _t->on_zoom_in_image_clicked(); break;
        case 8: _t->on_zoom_out_image_clicked(); break;
        case 9: _t->on_split_image_clicked(); break;
        case 10: _t->on_Water_mark_image_clicked(); break;
        case 11: _t->on_Histogram_clicked(); break;
        case 12: _t->on_ellipse_clicked(); break;
        case 13: _t->on_rectangular_clicked(); break;
        case 14: _t->on_picturemark_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Menu::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Menu.data,
    qt_meta_data_Menu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Menu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Menu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Menu.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Menu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
