/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Painter/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Window_t {
    const uint offsetsAndSize[32];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Window_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Window_t qt_meta_stringdata_Window = {
    {
QT_MOC_LITERAL(0, 6), // "Window"
QT_MOC_LITERAL(7, 11), // "ChangeWidth"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 3), // "val"
QT_MOC_LITERAL(24, 11), // "ChangeColor"
QT_MOC_LITERAL(36, 12), // "LoadFromFile"
QT_MOC_LITERAL(49, 10), // "SaveToFile"
QT_MOC_LITERAL(60, 8), // "StepBack"
QT_MOC_LITERAL(69, 5), // "Clear"
QT_MOC_LITERAL(75, 10), // "paintEvent"
QT_MOC_LITERAL(86, 12), // "QPaintEvent*"
QT_MOC_LITERAL(99, 5), // "event"
QT_MOC_LITERAL(105, 10), // "LineChosen"
QT_MOC_LITERAL(116, 15), // "SuperLineChosen"
QT_MOC_LITERAL(132, 12), // "CircleChosen"
QT_MOC_LITERAL(145, 15) // "RectangleChosen"

    },
    "Window\0ChangeWidth\0\0val\0ChangeColor\0"
    "LoadFromFile\0SaveToFile\0StepBack\0Clear\0"
    "paintEvent\0QPaintEvent*\0event\0LineChosen\0"
    "SuperLineChosen\0CircleChosen\0"
    "RectangleChosen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x0a,    1 /* Public */,
       4,    1,   83,    2, 0x0a,    3 /* Public */,
       5,    0,   86,    2, 0x0a,    5 /* Public */,
       6,    0,   87,    2, 0x0a,    6 /* Public */,
       7,    0,   88,    2, 0x0a,    7 /* Public */,
       8,    0,   89,    2, 0x0a,    8 /* Public */,
       9,    1,   90,    2, 0x0a,    9 /* Public */,
      12,    0,   93,    2, 0x0a,   11 /* Public */,
      13,    0,   94,    2, 0x0a,   12 /* Public */,
      14,    0,   95,    2, 0x0a,   13 /* Public */,
      15,    0,   96,    2, 0x0a,   14 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Window *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->ChangeWidth((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->ChangeColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 2: _t->LoadFromFile(); break;
        case 3: _t->SaveToFile(); break;
        case 4: _t->StepBack(); break;
        case 5: _t->Clear(); break;
        case 6: _t->paintEvent((*reinterpret_cast< std::add_pointer_t<QPaintEvent*>>(_a[1]))); break;
        case 7: _t->LineChosen(); break;
        case 8: _t->SuperLineChosen(); break;
        case 9: _t->CircleChosen(); break;
        case 10: _t->RectangleChosen(); break;
        default: ;
        }
    }
}

const QMetaObject Window::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Window.offsetsAndSize,
    qt_meta_data_Window,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Window_t
, QtPrivate::TypeAndForceComplete<Window, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QPaintEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Window.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
