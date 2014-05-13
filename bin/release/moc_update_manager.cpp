/****************************************************************************
** Meta object code from reading C++ file 'update_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/update_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'update_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_update_manager_t {
    QByteArrayData data[22];
    char stringdata[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_update_manager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_update_manager_t qt_meta_stringdata_update_manager = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 18),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 18),
QT_MOC_LITERAL(4, 54, 13),
QT_MOC_LITERAL(5, 68, 17),
QT_MOC_LITERAL(6, 86, 4),
QT_MOC_LITERAL(7, 91, 4),
QT_MOC_LITERAL(8, 96, 4),
QT_MOC_LITERAL(9, 101, 17),
QT_MOC_LITERAL(10, 119, 9),
QT_MOC_LITERAL(11, 129, 13),
QT_MOC_LITERAL(12, 143, 16),
QT_MOC_LITERAL(13, 160, 14),
QT_MOC_LITERAL(14, 175, 5),
QT_MOC_LITERAL(15, 181, 15),
QT_MOC_LITERAL(16, 197, 4),
QT_MOC_LITERAL(17, 202, 6),
QT_MOC_LITERAL(18, 209, 27),
QT_MOC_LITERAL(19, 237, 4),
QT_MOC_LITERAL(20, 242, 18),
QT_MOC_LITERAL(21, 261, 14)
    },
    "update_manager\0picture_downloaded\0\0"
    "set_card_directory\0dir_path_card\0"
    "set_serv_settings\0path\0user\0pass\0"
    "seek_card_picture\0card_name\0seek_database\0"
    "authentification\0QNetworkReply*\0reply\0"
    "QAuthenticator*\0auth\0erreur\0"
    "QNetworkReply::NetworkError\0code\0"
    "write_card_picture\0write_database\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_update_manager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       3,    1,   65,    2, 0x0a,
       5,    3,   68,    2, 0x0a,
       5,    2,   75,    2, 0x2a,
       9,    1,   80,    2, 0x0a,
      11,    0,   83,    2, 0x0a,
      12,    2,   84,    2, 0x08,
      17,    1,   89,    2, 0x08,
      20,    0,   92,    2, 0x08,
      21,    0,   93,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 15,   14,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void update_manager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        update_manager *_t = static_cast<update_manager *>(_o);
        switch (_id) {
        case 0: _t->picture_downloaded(); break;
        case 1: _t->set_card_directory((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->set_serv_settings((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->set_serv_settings((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->seek_card_picture((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->seek_database(); break;
        case 6: _t->authentification((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 7: _t->erreur((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 8: _t->write_card_picture(); break;
        case 9: _t->write_database(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (update_manager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&update_manager::picture_downloaded)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject update_manager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_update_manager.data,
      qt_meta_data_update_manager,  qt_static_metacall, 0, 0}
};


const QMetaObject *update_manager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *update_manager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_update_manager.stringdata))
        return static_cast<void*>(const_cast< update_manager*>(this));
    return QObject::qt_metacast(_clname);
}

int update_manager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void update_manager::picture_downloaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
