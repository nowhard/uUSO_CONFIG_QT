/****************************************************************************
** Meta object code from reading C++ file 'dev_info.h'
**
** Created: Tue 21. May 11:59:22 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Threading/dev_info.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dev_info.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dev_info[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      25,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      40,    9,    9,    9, 0x08,
      66,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dev_info[] = {
    "dev_info\0\0get_dev_info()\0set_dev_info()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_5_clicked()\0"
};

void dev_info::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        dev_info *_t = static_cast<dev_info *>(_o);
        switch (_id) {
        case 0: _t->get_dev_info(); break;
        case 1: _t->set_dev_info(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButton_5_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData dev_info::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dev_info::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dev_info,
      qt_meta_data_dev_info, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dev_info::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dev_info::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dev_info::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dev_info))
        return static_cast<void*>(const_cast< dev_info*>(this));
    return QDialog::qt_metacast(_clname);
}

int dev_info::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void dev_info::get_dev_info()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void dev_info::set_dev_info()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
