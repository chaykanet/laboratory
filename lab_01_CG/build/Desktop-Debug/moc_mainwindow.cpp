/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10MainWindowE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN10MainWindowE = QtMocHelpers::stringData(
    "MainWindow",
    "centerGraphicView",
    "",
    "QList<QPointF>&",
    "points",
    "Triangle&",
    "triangle",
    "QRectF&",
    "rect",
    "drawTriangle",
    "QPainter&",
    "p",
    "drawAxes",
    "imageWidth",
    "imageHeight",
    "drawPoints",
    "on_drawPointsAndAxes_clicked",
    "on_about_app_clicked",
    "on_addPoint_clicked",
    "on_pushButton_clicked",
    "on_clear_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN10MainWindowE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   68,    2, 0x08,    1 /* Private */,
       9,    3,   75,    2, 0x08,    5 /* Private */,
      12,    4,   82,    2, 0x08,    9 /* Private */,
      15,    2,   91,    2, 0x08,   14 /* Private */,
      16,    0,   96,    2, 0x08,   17 /* Private */,
      17,    0,   97,    2, 0x08,   18 /* Private */,
      18,    0,   98,    2, 0x08,   19 /* Private */,
      19,    0,   99,    2, 0x08,   20 /* Private */,
      20,    0,  100,    2, 0x08,   21 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 5, 0x80000000 | 7,   11,    6,    8,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 7, QMetaType::Int, QMetaType::Int,   11,    8,   13,   14,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 3,   11,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ZN10MainWindowE.offsetsAndSizes,
    qt_meta_data_ZN10MainWindowE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN10MainWindowE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'centerGraphicView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QPointF> &, std::false_type>,
        QtPrivate::TypeAndForceComplete<Triangle &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QRectF &, std::false_type>,
        // method 'drawTriangle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPainter &, std::false_type>,
        QtPrivate::TypeAndForceComplete<Triangle &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QRectF &, std::false_type>,
        // method 'drawAxes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPainter &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QRectF &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'drawPoints'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPainter &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QList<QPointF> &, std::false_type>,
        // method 'on_drawPointsAndAxes_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_about_app_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addPoint_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->centerGraphicView((*reinterpret_cast< std::add_pointer_t<QList<QPointF>&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Triangle&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QRectF&>>(_a[3]))); break;
        case 1: _t->drawTriangle((*reinterpret_cast< std::add_pointer_t<QPainter&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Triangle&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QRectF&>>(_a[3]))); break;
        case 2: _t->drawAxes((*reinterpret_cast< std::add_pointer_t<QPainter&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QRectF&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 3: _t->drawPoints((*reinterpret_cast< std::add_pointer_t<QPainter&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QPointF>&>>(_a[2]))); break;
        case 4: _t->on_drawPointsAndAxes_clicked(); break;
        case 5: _t->on_about_app_clicked(); break;
        case 6: _t->on_addPoint_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_clear_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN10MainWindowE.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
