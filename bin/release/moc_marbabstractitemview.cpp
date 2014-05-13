/****************************************************************************
** Meta object code from reading C++ file 'marbabstractitemview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/marbabstractitemview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'marbabstractitemview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MarbAbstractItemView_t {
    QByteArrayData data[12];
    char stringdata[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MarbAbstractItemView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MarbAbstractItemView_t qt_meta_stringdata_MarbAbstractItemView = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 11),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 7),
QT_MOC_LITERAL(4, 42, 11),
QT_MOC_LITERAL(5, 54, 20),
QT_MOC_LITERAL(6, 75, 6),
QT_MOC_LITERAL(7, 82, 5),
QT_MOC_LITERAL(8, 88, 3),
QT_MOC_LITERAL(9, 92, 12),
QT_MOC_LITERAL(10, 105, 4),
QT_MOC_LITERAL(11, 110, 8)
    },
    "MarbAbstractItemView\0dataChanged\0\0"
    "topLeft\0bottomRight\0rowsAboutToBeRemoved\0"
    "parent\0start\0end\0rowsInserted\0save\0"
    "filename\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MarbAbstractItemView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x09,
       5,    3,   39,    2, 0x09,
       9,    3,   46,    2, 0x09,
      10,    1,   53,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    3,    4,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    6,    7,    8,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    6,    7,    8,
    QMetaType::Bool, QMetaType::QString,   11,

       0        // eod
};

void MarbAbstractItemView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MarbAbstractItemView *_t = static_cast<MarbAbstractItemView *>(_o);
        switch (_id) {
        case 0: _t->dataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 1: _t->rowsAboutToBeRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->rowsInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: { bool _r = _t->save((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject MarbAbstractItemView::staticMetaObject = {
    { &QAbstractItemView::staticMetaObject, qt_meta_stringdata_MarbAbstractItemView.data,
      qt_meta_data_MarbAbstractItemView,  qt_static_metacall, 0, 0}
};


const QMetaObject *MarbAbstractItemView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MarbAbstractItemView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MarbAbstractItemView.stringdata))
        return static_cast<void*>(const_cast< MarbAbstractItemView*>(this));
    return QAbstractItemView::qt_metacast(_clname);
}

int MarbAbstractItemView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
