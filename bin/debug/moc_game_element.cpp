/****************************************************************************
** Meta object code from reading C++ file 'game_element.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/game_element.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_element.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Carte_t {
    QByteArrayData data[26];
    char stringdata[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Carte_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Carte_t qt_meta_stringdata_Carte = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 4),
QT_MOC_LITERAL(2, 11, 8),
QT_MOC_LITERAL(3, 20, 4),
QT_MOC_LITERAL(4, 25, 4),
QT_MOC_LITERAL(5, 30, 9),
QT_MOC_LITERAL(6, 40, 7),
QT_MOC_LITERAL(7, 48, 9),
QT_MOC_LITERAL(8, 58, 6),
QT_MOC_LITERAL(9, 65, 4),
QT_MOC_LITERAL(10, 70, 7),
QT_MOC_LITERAL(11, 78, 4),
QT_MOC_LITERAL(12, 83, 8),
QT_MOC_LITERAL(13, 92, 8),
QT_MOC_LITERAL(14, 101, 10),
QT_MOC_LITERAL(15, 112, 4),
QT_MOC_LITERAL(16, 117, 5),
QT_MOC_LITERAL(17, 123, 5),
QT_MOC_LITERAL(18, 129, 5),
QT_MOC_LITERAL(19, 135, 5),
QT_MOC_LITERAL(20, 141, 5),
QT_MOC_LITERAL(21, 147, 8),
QT_MOC_LITERAL(22, 156, 10),
QT_MOC_LITERAL(23, 167, 4),
QT_MOC_LITERAL(24, 172, 6),
QT_MOC_LITERAL(25, 179, 12)
    },
    "Carte\0Kind\0CardType\0Name\0Sets\0ImageFile\0"
    "UrlCard\0Expansion\0Rarity\0Type\0SubType\0"
    "Clan\0Capacity\0Grouping\0Discipline\0"
    "Sect\0PCost\0BCost\0CCost\0Title\0Trait\0"
    "KeyWords\0Limitation\0Text\0Artist\0"
    "Commentaires\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Carte[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      24,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, 0x80000000 | 2, 0x00095009,
       3, QMetaType::QString, 0x00095001,
       4, QMetaType::QString, 0x00095001,
       5, QMetaType::QString, 0x00095001,
       6, QMetaType::QString, 0x00095001,
       7, QMetaType::QString, 0x00095001,
       8, QMetaType::QString, 0x00095001,
       9, QMetaType::QString, 0x00095001,
      10, QMetaType::QString, 0x00095001,
      11, QMetaType::QString, 0x00095001,
      12, QMetaType::QString, 0x00095001,
      13, QMetaType::QString, 0x00095001,
      14, QMetaType::QString, 0x00095001,
      15, QMetaType::QString, 0x00095001,
      16, QMetaType::QString, 0x00095001,
      17, QMetaType::QString, 0x00095001,
      18, QMetaType::QString, 0x00095001,
      19, QMetaType::QString, 0x00095001,
      20, QMetaType::QString, 0x00095001,
      21, QMetaType::QString, 0x00095001,
      22, QMetaType::QString, 0x00095001,
      23, QMetaType::QString, 0x00095001,
      24, QMetaType::QString, 0x00095001,
      25, QMetaType::QString, 0x00095001,

 // enums: name, flags, count, data

 // enum data: key, value

       0        // eod
};

void Carte::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject Carte::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Carte.data,
      qt_meta_data_Carte,  qt_static_metacall, 0, 0}
};


const QMetaObject *Carte::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Carte::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Carte.stringdata))
        return static_cast<void*>(const_cast< Carte*>(this));
    return QObject::qt_metacast(_clname);
}

int Carte::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< CardType*>(_v) = getKind(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getSets(); break;
        case 3: *reinterpret_cast< QString*>(_v) = getImageFile(); break;
        case 4: *reinterpret_cast< QString*>(_v) = getUrlCard(); break;
        case 5: *reinterpret_cast< QString*>(_v) = getExpansion(); break;
        case 6: *reinterpret_cast< QString*>(_v) = getRarity(); break;
        case 7: *reinterpret_cast< QString*>(_v) = getType(); break;
        case 8: *reinterpret_cast< QString*>(_v) = getSubType(); break;
        case 9: *reinterpret_cast< QString*>(_v) = getClan(); break;
        case 10: *reinterpret_cast< QString*>(_v) = getCapacity(); break;
        case 11: *reinterpret_cast< QString*>(_v) = getGrouping(); break;
        case 12: *reinterpret_cast< QString*>(_v) = getDiscipline(); break;
        case 13: *reinterpret_cast< QString*>(_v) = getSect(); break;
        case 14: *reinterpret_cast< QString*>(_v) = getPCost(); break;
        case 15: *reinterpret_cast< QString*>(_v) = getBCost(); break;
        case 16: *reinterpret_cast< QString*>(_v) = getCCost(); break;
        case 17: *reinterpret_cast< QString*>(_v) = getTitle(); break;
        case 18: *reinterpret_cast< QString*>(_v) = getTrait(); break;
        case 19: *reinterpret_cast< QString*>(_v) = getKeyWords(); break;
        case 20: *reinterpret_cast< QString*>(_v) = getLimitation(); break;
        case 21: *reinterpret_cast< QString*>(_v) = getText(); break;
        case 22: *reinterpret_cast< QString*>(_v) = getArtist(); break;
        case 23: *reinterpret_cast< QString*>(_v) = getCommentaires(); break;
        }
        _id -= 24;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 24;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 24;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 24;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 24;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 24;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 24;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 24;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
