/****************************************************************************
** Meta object code from reading C++ file 'tab_deck_tuning.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/tab_deck_tuning.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tab_deck_tuning.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tab_deck_tuning_t {
    QByteArrayData data[10];
    char stringdata[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_tab_deck_tuning_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_tab_deck_tuning_t qt_meta_stringdata_tab_deck_tuning = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 13),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 15),
QT_MOC_LITERAL(4, 47, 27),
QT_MOC_LITERAL(5, 75, 14),
QT_MOC_LITERAL(6, 90, 29),
QT_MOC_LITERAL(7, 120, 16),
QT_MOC_LITERAL(8, 137, 18),
QT_MOC_LITERAL(9, 156, 12)
    },
    "tab_deck_tuning\0clear_widgets\0\0"
    "refresh_widgets\0refresh_disciplinesLib_view\0"
    "QStandardItem*\0refresh_disciplinesCrypt_view\0"
    "clear_stat_model\0refresh_stat_model\0"
    "parent_index\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tab_deck_tuning[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08,
       3,    0,   45,    2, 0x08,
       4,    1,   46,    2, 0x08,
       6,    1,   49,    2, 0x08,
       7,    0,   52,    2, 0x08,
       8,    1,   53,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    9,

       0        // eod
};

void tab_deck_tuning::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tab_deck_tuning *_t = static_cast<tab_deck_tuning *>(_o);
        switch (_id) {
        case 0: _t->clear_widgets(); break;
        case 1: _t->refresh_widgets(); break;
        case 2: _t->refresh_disciplinesLib_view((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 3: _t->refresh_disciplinesCrypt_view((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 4: _t->clear_stat_model(); break;
        case 5: _t->refresh_stat_model((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject tab_deck_tuning::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_tab_deck_tuning.data,
      qt_meta_data_tab_deck_tuning,  qt_static_metacall, 0, 0}
};


const QMetaObject *tab_deck_tuning::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tab_deck_tuning::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tab_deck_tuning.stringdata))
        return static_cast<void*>(const_cast< tab_deck_tuning*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int tab_deck_tuning::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
