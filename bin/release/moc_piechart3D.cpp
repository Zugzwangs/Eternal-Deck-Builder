/****************************************************************************
** Meta object code from reading C++ file 'piechart3D.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/Charts/piechart3D.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'piechart3D.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PieChart3D_t {
    QByteArrayData data[5];
    char stringdata[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PieChart3D_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PieChart3D_t qt_meta_stringdata_PieChart3D = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 6),
QT_MOC_LITERAL(2, 18, 5),
QT_MOC_LITERAL(3, 24, 9),
QT_MOC_LITERAL(4, 34, 11)
    },
    "PieChart3D\0Render\0Plain\0WireFrame\0"
    "Translucent\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PieChart3D[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    3,   18,

 // enum data: key, value
       2, uint(PieChart3D::Plain),
       3, uint(PieChart3D::WireFrame),
       4, uint(PieChart3D::Translucent),

       0        // eod
};

void PieChart3D::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject PieChart3D::staticMetaObject = {
    { &PieChart::staticMetaObject, qt_meta_stringdata_PieChart3D.data,
      qt_meta_data_PieChart3D,  qt_static_metacall, 0, 0}
};


const QMetaObject *PieChart3D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PieChart3D::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PieChart3D.stringdata))
        return static_cast<void*>(const_cast< PieChart3D*>(this));
    return PieChart::qt_metacast(_clname);
}

int PieChart3D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = PieChart::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
