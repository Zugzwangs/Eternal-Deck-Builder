/****************************************************************************
** Meta object code from reading C++ file 'mvddeck.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/mvddeck.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mvddeck.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CryptCardItem_t {
    QByteArrayData data[3];
    char stringdata[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CryptCardItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CryptCardItem_t qt_meta_stringdata_CryptCardItem = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 16),
QT_MOC_LITERAL(2, 31, 0)
    },
    "CryptCardItem\0request_deleting\0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CryptCardItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex,    2,

       0        // eod
};

void CryptCardItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CryptCardItem *_t = static_cast<CryptCardItem *>(_o);
        switch (_id) {
        case 0: _t->request_deleting((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CryptCardItem::*_t)(QModelIndex );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CryptCardItem::request_deleting)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CryptCardItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CryptCardItem.data,
      qt_meta_data_CryptCardItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *CryptCardItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CryptCardItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CryptCardItem.stringdata))
        return static_cast<void*>(const_cast< CryptCardItem*>(this));
    if (!strcmp(_clname, "QStandardItem"))
        return static_cast< QStandardItem*>(const_cast< CryptCardItem*>(this));
    return QObject::qt_metacast(_clname);
}

int CryptCardItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void CryptCardItem::request_deleting(QModelIndex _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_LibraryCardItem_t {
    QByteArrayData data[3];
    char stringdata[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LibraryCardItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LibraryCardItem_t qt_meta_stringdata_LibraryCardItem = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 16),
QT_MOC_LITERAL(2, 33, 0)
    },
    "LibraryCardItem\0request_deleting\0\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LibraryCardItem[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex,    2,

       0        // eod
};

void LibraryCardItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LibraryCardItem *_t = static_cast<LibraryCardItem *>(_o);
        switch (_id) {
        case 0: _t->request_deleting((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LibraryCardItem::*_t)(QModelIndex );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LibraryCardItem::request_deleting)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject LibraryCardItem::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LibraryCardItem.data,
      qt_meta_data_LibraryCardItem,  qt_static_metacall, 0, 0}
};


const QMetaObject *LibraryCardItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LibraryCardItem::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LibraryCardItem.stringdata))
        return static_cast<void*>(const_cast< LibraryCardItem*>(this));
    if (!strcmp(_clname, "QStandardItem"))
        return static_cast< QStandardItem*>(const_cast< LibraryCardItem*>(this));
    return QObject::qt_metacast(_clname);
}

int LibraryCardItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void LibraryCardItem::request_deleting(QModelIndex _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_PDelegateDeck_t {
    QByteArrayData data[1];
    char stringdata[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PDelegateDeck_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PDelegateDeck_t qt_meta_stringdata_PDelegateDeck = {
    {
QT_MOC_LITERAL(0, 0, 13)
    },
    "PDelegateDeck\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PDelegateDeck[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void PDelegateDeck::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject PDelegateDeck::staticMetaObject = {
    { &QStyledItemDelegate::staticMetaObject, qt_meta_stringdata_PDelegateDeck.data,
      qt_meta_data_PDelegateDeck,  qt_static_metacall, 0, 0}
};


const QMetaObject *PDelegateDeck::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PDelegateDeck::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PDelegateDeck.stringdata))
        return static_cast<void*>(const_cast< PDelegateDeck*>(this));
    return QStyledItemDelegate::qt_metacast(_clname);
}

int PDelegateDeck::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_PTreeModel_t {
    QByteArrayData data[17];
    char stringdata[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PTreeModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PTreeModel_t qt_meta_stringdata_PTreeModel = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 15),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 12),
QT_MOC_LITERAL(4, 41, 11),
QT_MOC_LITERAL(5, 53, 6),
QT_MOC_LITERAL(6, 60, 11),
QT_MOC_LITERAL(7, 72, 4),
QT_MOC_LITERAL(8, 77, 17),
QT_MOC_LITERAL(9, 95, 3),
QT_MOC_LITERAL(10, 99, 17),
QT_MOC_LITERAL(11, 117, 14),
QT_MOC_LITERAL(12, 132, 13),
QT_MOC_LITERAL(13, 146, 14),
QT_MOC_LITERAL(14, 161, 8),
QT_MOC_LITERAL(15, 170, 15),
QT_MOC_LITERAL(16, 186, 16)
    },
    "PTreeModel\0CardItemChanged\0\0ModifiedItem\0"
    "DeckChanged\0parent\0AddCardItem\0strL\0"
    "IncrementCardItem\0Idx\0DecrementCardItem\0"
    "RemoveCardITem\0FindCryptCard\0"
    "CryptCardItem*\0CardName\0FindLibraryCard\0"
    "LibraryCardItem*\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PTreeModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06,
       4,    1,   57,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    1,   60,    2, 0x0a,
       8,    1,   63,    2, 0x0a,
      10,    1,   66,    2, 0x0a,
      11,    1,   69,    2, 0x0a,
      12,    1,   72,    2, 0x0a,
      15,    1,   75,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, QMetaType::QModelIndex,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    7,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void, QMetaType::QModelIndex,    9,
    0x80000000 | 13, QMetaType::QString,   14,
    0x80000000 | 16, QMetaType::QString,   14,

       0        // eod
};

void PTreeModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PTreeModel *_t = static_cast<PTreeModel *>(_o);
        switch (_id) {
        case 0: _t->CardItemChanged((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->DeckChanged((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->AddCardItem((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 3: _t->IncrementCardItem((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 4: _t->DecrementCardItem((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: _t->RemoveCardITem((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: { CryptCardItem* _r = _t->FindCryptCard((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< CryptCardItem**>(_a[0]) = _r; }  break;
        case 7: { LibraryCardItem* _r = _t->FindLibraryCard((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< LibraryCardItem**>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PTreeModel::*_t)(QModelIndex );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PTreeModel::CardItemChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (PTreeModel::*_t)(QModelIndex );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PTreeModel::DeckChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject PTreeModel::staticMetaObject = {
    { &QStandardItemModel::staticMetaObject, qt_meta_stringdata_PTreeModel.data,
      qt_meta_data_PTreeModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *PTreeModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PTreeModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PTreeModel.stringdata))
        return static_cast<void*>(const_cast< PTreeModel*>(this));
    return QStandardItemModel::qt_metacast(_clname);
}

int PTreeModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void PTreeModel::CardItemChanged(QModelIndex _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PTreeModel::DeckChanged(QModelIndex _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_StatsModel_t {
    QByteArrayData data[1];
    char stringdata[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_StatsModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_StatsModel_t qt_meta_stringdata_StatsModel = {
    {
QT_MOC_LITERAL(0, 0, 10)
    },
    "StatsModel\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StatsModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void StatsModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject StatsModel::staticMetaObject = {
    { &QStandardItemModel::staticMetaObject, qt_meta_stringdata_StatsModel.data,
      qt_meta_data_StatsModel,  qt_static_metacall, 0, 0}
};


const QMetaObject *StatsModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StatsModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StatsModel.stringdata))
        return static_cast<void*>(const_cast< StatsModel*>(this));
    return QStandardItemModel::qt_metacast(_clname);
}

int StatsModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStandardItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_WidgetMetaMapper_t {
    QByteArrayData data[4];
    char stringdata[40];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_WidgetMetaMapper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_WidgetMetaMapper_t qt_meta_stringdata_WidgetMetaMapper = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 12),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 7)
    },
    "WidgetMetaMapper\0synchroDatas\0\0newData\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetMetaMapper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void WidgetMetaMapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WidgetMetaMapper *_t = static_cast<WidgetMetaMapper *>(_o);
        switch (_id) {
        case 0: _t->synchroDatas((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject WidgetMetaMapper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_WidgetMetaMapper.data,
      qt_meta_data_WidgetMetaMapper,  qt_static_metacall, 0, 0}
};


const QMetaObject *WidgetMetaMapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetMetaMapper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetMetaMapper.stringdata))
        return static_cast<void*>(const_cast< WidgetMetaMapper*>(this));
    return QObject::qt_metacast(_clname);
}

int WidgetMetaMapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_PTreeView_t {
    QByteArrayData data[7];
    char stringdata[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PTreeView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PTreeView_t qt_meta_stringdata_PTreeView = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 17),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 17),
QT_MOC_LITERAL(4, 47, 14),
QT_MOC_LITERAL(5, 62, 8),
QT_MOC_LITERAL(6, 71, 4)
    },
    "PTreeView\0request_increment\0\0"
    "request_decrement\0request_delete\0"
    "fakeDrop\0StrL\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PTreeView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06,
       3,    1,   37,    2, 0x06,
       4,    1,   40,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    1,   43,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void, QMetaType::QModelIndex,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    6,

       0        // eod
};

void PTreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PTreeView *_t = static_cast<PTreeView *>(_o);
        switch (_id) {
        case 0: _t->request_increment((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->request_decrement((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->request_delete((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 3: _t->fakeDrop((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PTreeView::*_t)(QModelIndex );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PTreeView::request_increment)) {
                *result = 0;
            }
        }
        {
            typedef void (PTreeView::*_t)(QModelIndex );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PTreeView::request_decrement)) {
                *result = 1;
            }
        }
        {
            typedef void (PTreeView::*_t)(QModelIndex );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PTreeView::request_delete)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject PTreeView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_PTreeView.data,
      qt_meta_data_PTreeView,  qt_static_metacall, 0, 0}
};


const QMetaObject *PTreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PTreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PTreeView.stringdata))
        return static_cast<void*>(const_cast< PTreeView*>(this));
    return QTreeView::qt_metacast(_clname);
}

int PTreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void PTreeView::request_increment(QModelIndex _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PTreeView::request_decrement(QModelIndex _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PTreeView::request_delete(QModelIndex _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_PartialDeckView_t {
    QByteArrayData data[1];
    char stringdata[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PartialDeckView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PartialDeckView_t qt_meta_stringdata_PartialDeckView = {
    {
QT_MOC_LITERAL(0, 0, 15)
    },
    "PartialDeckView\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PartialDeckView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void PartialDeckView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject PartialDeckView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_PartialDeckView.data,
      qt_meta_data_PartialDeckView,  qt_static_metacall, 0, 0}
};


const QMetaObject *PartialDeckView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PartialDeckView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PartialDeckView.stringdata))
        return static_cast<void*>(const_cast< PartialDeckView*>(this));
    return QTreeView::qt_metacast(_clname);
}

int PartialDeckView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
