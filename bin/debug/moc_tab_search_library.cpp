/****************************************************************************
** Meta object code from reading C++ file 'tab_search_library.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/tab_search_library.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tab_search_library.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_tab_search_library_t {
    QByteArrayData data[11];
    char stringdata[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_tab_search_library_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_tab_search_library_t qt_meta_stringdata_tab_search_library = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 17),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 20),
QT_MOC_LITERAL(4, 59, 14),
QT_MOC_LITERAL(5, 74, 9),
QT_MOC_LITERAL(6, 84, 14),
QT_MOC_LITERAL(7, 99, 17),
QT_MOC_LITERAL(8, 117, 3),
QT_MOC_LITERAL(9, 121, 17),
QT_MOC_LITERAL(10, 139, 8)
    },
    "tab_search_library\0new_card_selected\0"
    "\0card_picture_missing\0AdapteSousType\0"
    "ClearForm\0RechercheCarte\0request_affichage\0"
    "Idx\0AfficheImageCarte\0CardName\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tab_search_library[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06,
       3,    1,   52,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    0,   55,    2, 0x08,
       5,    0,   56,    2, 0x08,
       6,    0,   57,    2, 0x08,
       7,    1,   58,    2, 0x08,
       9,    1,   61,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void tab_search_library::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        tab_search_library *_t = static_cast<tab_search_library *>(_o);
        switch (_id) {
        case 0: _t->new_card_selected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->card_picture_missing((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->AdapteSousType(); break;
        case 3: _t->ClearForm(); break;
        case 4: _t->RechercheCarte(); break;
        case 5: _t->request_affichage((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->AfficheImageCarte((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (tab_search_library::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tab_search_library::new_card_selected)) {
                *result = 0;
            }
        }
        {
            typedef void (tab_search_library::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&tab_search_library::card_picture_missing)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject tab_search_library::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_tab_search_library.data,
      qt_meta_data_tab_search_library,  qt_static_metacall, 0, 0}
};


const QMetaObject *tab_search_library::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tab_search_library::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tab_search_library.stringdata))
        return static_cast<void*>(const_cast< tab_search_library*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int tab_search_library::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void tab_search_library::new_card_selected(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void tab_search_library::card_picture_missing(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
