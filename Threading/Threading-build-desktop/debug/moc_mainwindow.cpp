/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Fri 17. May 15:02:23 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Threading/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      64,   11,   11,   11, 0x08,
      90,   11,   11,   11, 0x08,
     114,   11,   11,   11, 0x08,
     151,  142,   11,   11, 0x08,
     182,  177,   11,   11, 0x08,
     202,  177,   11,   11, 0x08,
     223,   11,   11,   11, 0x08,
     263,  245,   11,   11, 0x08,
     305,  302,   11,   11, 0x08,
     323,   11,   11,   11, 0x08,
     338,   11,   11,   11, 0x08,
     358,   11,   11,   11, 0x08,
     378,   11,   11,   11, 0x08,
     410,   11,   11,   11, 0x08,
     445,   11,   11,   11, 0x08,
     473,   11,   11,   11, 0x08,
     507,   11,   11,   11, 0x08,
     539,   11,   11,   11, 0x08,
     571,   11,   11,   11, 0x08,
     614,   11,   11,   11, 0x08,
     644,   11,   11,   11, 0x08,
     683,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_pushButton_5_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_action_COM_triggered()\0"
    "on_dev_info_responsed()\0"
    "on_dev_get_data_responsed()\0dev_addr\0"
    "on_connect_device(quint8)\0mess\0"
    "MessageReadOK(bool)\0MessageWriteOK(bool)\0"
    "MessageNotConnected()\0OK,ID,Description\0"
    "Display_Dev_Info(bool,quint16,QString)\0"
    "OK\0Info_Is_Set(bool)\0Get_All_Data()\0"
    "UnactiveInterface()\0ActivateInterface()\0"
    "on_calibrate_0_button_clicked()\0"
    "on_calibrate_full_button_clicked()\0"
    "on_calibrate_flag_clicked()\0"
    "on_calibrate_set_button_clicked()\0"
    "on_menu_load_settings_clicked()\0"
    "on_menu_save_settings_clicked()\0"
    "on_action_Set_Settings_Default_triggered()\0"
    "on_action_connect_triggered()\0"
    "on_action_set_chn_settings_triggered()\0"
    "on_action_dev_polling_triggered()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_5_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->on_action_COM_triggered(); break;
        case 3: _t->on_dev_info_responsed(); break;
        case 4: _t->on_dev_get_data_responsed(); break;
        case 5: _t->on_connect_device((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 6: _t->MessageReadOK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->MessageWriteOK((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->MessageNotConnected(); break;
        case 9: _t->Display_Dev_Info((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 10: _t->Info_Is_Set((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->Get_All_Data(); break;
        case 12: _t->UnactiveInterface(); break;
        case 13: _t->ActivateInterface(); break;
        case 14: _t->on_calibrate_0_button_clicked(); break;
        case 15: _t->on_calibrate_full_button_clicked(); break;
        case 16: _t->on_calibrate_flag_clicked(); break;
        case 17: _t->on_calibrate_set_button_clicked(); break;
        case 18: _t->on_menu_load_settings_clicked(); break;
        case 19: _t->on_menu_save_settings_clicked(); break;
        case 20: _t->on_action_Set_Settings_Default_triggered(); break;
        case 21: _t->on_action_connect_triggered(); break;
        case 22: _t->on_action_set_chn_settings_triggered(); break;
        case 23: _t->on_action_dev_polling_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
