/****************************************************************************
** Meta object code from reading C++ file 'connect_dialog.h'
**
** Created: Mon 9. Dec 16:14:18 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Threading/connect_dialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connect_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_connect_dialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   15,   15,   15, 0x08,
      72,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_connect_dialog[] = {
    "connect_dialog\0\0dev_addr\0"
    "connect_device(quint8)\0on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
};

void connect_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        connect_dialog *_t = static_cast<connect_dialog *>(_o);
        switch (_id) {
        case 0: _t->connect_device((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData connect_dialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject connect_dialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_connect_dialog,
      qt_meta_data_connect_dialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &connect_dialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *connect_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *connect_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_connect_dialog))
        return static_cast<void*>(const_cast< connect_dialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int connect_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void connect_dialog::connect_device(quint8 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
