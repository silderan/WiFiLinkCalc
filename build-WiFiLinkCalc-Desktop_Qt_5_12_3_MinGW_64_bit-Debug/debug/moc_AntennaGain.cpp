/****************************************************************************
** Meta object code from reading C++ file 'AntennaGain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/AntennaGain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AntennaGain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QAntennaGainCB_t {
    QByteArrayData data[7];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QAntennaGainCB_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QAntennaGainCB_t qt_meta_stringdata_QAntennaGainCB = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QAntennaGainCB"
QT_MOC_LITERAL(1, 15, 11), // "gainChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 17), // "selectAntenaModel"
QT_MOC_LITERAL(4, 46, 12), // "antennaModel"
QT_MOC_LITERAL(5, 59, 14), // "onIndexChanged"
QT_MOC_LITERAL(6, 74, 5) // "index"

    },
    "QAntennaGainCB\0gainChanged\0\0"
    "selectAntenaModel\0antennaModel\0"
    "onIndexChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QAntennaGainCB[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   32,    2, 0x0a /* Public */,
       5,    1,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void QAntennaGainCB::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QAntennaGainCB *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gainChanged((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: _t->selectAntenaModel((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QAntennaGainCB::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QAntennaGainCB::gainChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QAntennaGainCB::staticMetaObject = { {
    &QComboBox::staticMetaObject,
    qt_meta_stringdata_QAntennaGainCB.data,
    qt_meta_data_QAntennaGainCB,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QAntennaGainCB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAntennaGainCB::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QAntennaGainCB.stringdata0))
        return static_cast<void*>(this);
    return QComboBox::qt_metacast(_clname);
}

int QAntennaGainCB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QAntennaGainCB::gainChanged(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QAntennaGainTable_t {
    QByteArrayData data[12];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QAntennaGainTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QAntennaGainTable_t qt_meta_stringdata_QAntennaGainTable = {
    {
QT_MOC_LITERAL(0, 0, 17), // "QAntennaGainTable"
QT_MOC_LITERAL(1, 18, 11), // "gainChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "gain"
QT_MOC_LITERAL(4, 36, 6), // "addRow"
QT_MOC_LITERAL(5, 43, 11), // "antenaModel"
QT_MOC_LITERAL(6, 55, 11), // "AntennaData"
QT_MOC_LITERAL(7, 67, 7), // "antData"
QT_MOC_LITERAL(8, 75, 4), // "load"
QT_MOC_LITERAL(9, 80, 16), // "QAntennaDataList"
QT_MOC_LITERAL(10, 97, 11), // "antDataList"
QT_MOC_LITERAL(11, 109, 4) // "save"

    },
    "QAntennaGainTable\0gainChanged\0\0gain\0"
    "addRow\0antenaModel\0AntennaData\0antData\0"
    "load\0QAntennaDataList\0antDataList\0"
    "save"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QAntennaGainTable[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   52,    2, 0x0a /* Public */,
       4,    1,   57,    2, 0x2a /* Public | MethodCloned */,
       4,    0,   60,    2, 0x2a /* Public | MethodCloned */,
       4,    1,   61,    2, 0x0a /* Public */,
       8,    1,   64,    2, 0x0a /* Public */,
      11,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    5,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    0x80000000 | 9,

       0        // eod
};

void QAntennaGainTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QAntennaGainTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gainChanged((*reinterpret_cast< quint32(*)>(_a[1]))); break;
        case 1: _t->addRow((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2]))); break;
        case 2: _t->addRow((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->addRow(); break;
        case 4: _t->addRow((*reinterpret_cast< const AntennaData(*)>(_a[1]))); break;
        case 5: _t->load((*reinterpret_cast< const QAntennaDataList(*)>(_a[1]))); break;
        case 6: { QAntennaDataList _r = _t->save();
            if (_a[0]) *reinterpret_cast< QAntennaDataList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QAntennaGainTable::*)(quint32 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QAntennaGainTable::gainChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QAntennaGainTable::staticMetaObject = { {
    &QTableWidget::staticMetaObject,
    qt_meta_stringdata_QAntennaGainTable.data,
    qt_meta_data_QAntennaGainTable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QAntennaGainTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAntennaGainTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QAntennaGainTable.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int QAntennaGainTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
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
void QAntennaGainTable::gainChanged(quint32 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
