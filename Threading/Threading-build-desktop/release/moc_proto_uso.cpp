/****************************************************************************
** Meta object code from reading C++ file 'proto_uso.h'
**
** Created: Wed 22. May 13:43:39 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Threading/proto_uso.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proto_uso.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_proto_uso[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   11,   10,   10, 0x05,
      49,   10,   10,   10, 0x05,
      70,   10,   10,   10, 0x05,
     118,   95,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     178,  169,   10,   10, 0x0a,
     211,  202,   10,   10, 0x0a,
     255,  241,   10,   10, 0x0a,
     300,  169,   10,   10, 0x0a,
     332,  202,   10,   10, 0x0a,
     417,  370,   10,   10, 0x0a,
     484,  202,   10,   10, 0x0a,
     537,  510,   10,   10, 0x0a,
     611,  585,   10,   10, 0x0a,
     682,  665,   10,   10, 0x0a,
     723,  202,   10,   10, 0x0a,
     762,  169,   10,   10, 0x0a,
     794,  202,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_proto_uso[] = {
    "proto_uso\0\0request\0WriteToOut_Thread(QByteArray)\0"
    "DEV_INFO_RESPONSED()\0GET_ALL_DATA_RESPONSED()\0"
    "channel,calibrated,K,C\0"
    "GET_CALIBRATE_RESPONSED(quint8,quint8,float,float)\0"
    "dev_addr\0GET_DEV_INFO_REQ(qint8)\0"
    "response\0GET_DEV_INFO_RESP(QByteArray)\0"
    "dev_addr,chnl\0"
    "CHANNEL_SET_PARAMETERS_REQ(qint8,CHANNEL*[])\0"
    "CHANNEL_ALL_GET_DATA_REQ(qint8)\0"
    "CHANNEL_ALL_GET_DATA_RESP(QByteArray)\0"
    "dev_addr,new_addr,dev_name,version,description\0"
    "CHANNEL_SET_ADDRESS_DESC(quint8,quint8,QString,QByteArray,QString)\0"
    "REQUEST_ERROR(QByteArray)\0"
    "dev_addr,channel,point,num\0"
    "CHANNEL_SET_CALIBRATE(quint8,quint8,char,ulong)\0"
    "dev_addr,channel,mode,K,C\0"
    "CHANNEL_SET_CALIBRATE(quint8,quint8,char,float,float)\0"
    "dev_addr,channel\0"
    "CHANNEL_GET_CALIBRATE_REQ(quint8,quint8)\0"
    "CHANNEL_GET_CALIBRATE_RESP(QByteArray)\0"
    "CHANNEL_SET_ALL_DEFAULT(quint8)\0"
    "ResponseHandling(QByteArray)\0"
};

void proto_uso::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        proto_uso *_t = static_cast<proto_uso *>(_o);
        switch (_id) {
        case 0: _t->WriteToOut_Thread((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->DEV_INFO_RESPONSED(); break;
        case 2: _t->GET_ALL_DATA_RESPONSED(); break;
        case 3: _t->GET_CALIBRATE_RESPONSED((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 4: _t->GET_DEV_INFO_REQ((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        case 5: _t->GET_DEV_INFO_RESP((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->CHANNEL_SET_PARAMETERS_REQ((*reinterpret_cast< qint8(*)>(_a[1])),(*reinterpret_cast< CHANNEL*(*)[]>(_a[2]))); break;
        case 7: _t->CHANNEL_ALL_GET_DATA_REQ((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        case 8: _t->CHANNEL_ALL_GET_DATA_RESP((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->CHANNEL_SET_ADDRESS_DESC((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 10: _t->REQUEST_ERROR((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 11: _t->CHANNEL_SET_CALIBRATE((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< char(*)>(_a[3])),(*reinterpret_cast< ulong(*)>(_a[4]))); break;
        case 12: _t->CHANNEL_SET_CALIBRATE((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< char(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5]))); break;
        case 13: _t->CHANNEL_GET_CALIBRATE_REQ((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 14: _t->CHANNEL_GET_CALIBRATE_RESP((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 15: _t->CHANNEL_SET_ALL_DEFAULT((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 16: _t->ResponseHandling((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData proto_uso::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject proto_uso::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_proto_uso,
      qt_meta_data_proto_uso, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &proto_uso::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *proto_uso::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *proto_uso::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_proto_uso))
        return static_cast<void*>(const_cast< proto_uso*>(this));
    return QObject::qt_metacast(_clname);
}

int proto_uso::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void proto_uso::WriteToOut_Thread(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void proto_uso::DEV_INFO_RESPONSED()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void proto_uso::GET_ALL_DATA_RESPONSED()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void proto_uso::GET_CALIBRATE_RESPONSED(quint8 _t1, quint8 _t2, float _t3, float _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
