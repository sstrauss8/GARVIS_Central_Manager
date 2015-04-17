/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x08,
      58,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     186,  137,   11,   11, 0x08,
     216,   11,   11,   11, 0x08,
     250,   11,   11,   11, 0x08,
     276,   11,   11,   11, 0x08,
     316,   11,   11,   11, 0x08,
     345,   11,   11,   11, 0x08,
     374,   11,   11,   11, 0x08,
     403,   11,   11,   11, 0x08,
     442,  436,   11,   11, 0x08,
     475,  436,   11,   11, 0x08,
     527,   11,   11,   11, 0x08,
     563,   11,   11,   11, 0x08,
     587,   11,   11,   11, 0x08,
     625,  617,   11,   11, 0x08,
     651,  617,   11,   11, 0x08,
     679,  617,   11,   11, 0x08,
     707,  617,   11,   11, 0x08,
     735,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0arg1\0"
    "on_comboBox_currentIndexChanged(QString)\0"
    "on_button_NewRoom_clicked()\0"
    "on_button_deleteRoom_clicked()\0"
    "populateRoomNames()\0"
    "currentIndex,loadControllerIndex,partialPopulate\0"
    "populateDevices(int,int,bool)\0"
    "on_pushButton_addDevice_clicked()\0"
    "on_pushButton_4_clicked()\0"
    "on_pushbutton_setThreshold3_2_clicked()\0"
    "on_pushbutton_set1_clicked()\0"
    "on_pushbutton_set2_clicked()\0"
    "on_pushbutton_set3_clicked()\0"
    "on_helpTutorial_button_clicked()\0index\0"
    "on_tabWidget_currentChanged(int)\0"
    "on_comboBox_loadController_currentIndexChanged(int)\0"
    "on_pushButton_addDevice_2_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_checkBox_smartDM_clicked()\0checked\0"
    "on_checkBox_clicked(bool)\0"
    "on_checkBox_2_clicked(bool)\0"
    "on_checkBox_3_clicked(bool)\0"
    "on_checkBox_4_clicked(bool)\0"
    "on_pushButton_2_clicked()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_button_NewRoom_clicked(); break;
        case 2: _t->on_button_deleteRoom_clicked(); break;
        case 3: _t->populateRoomNames(); break;
        case 4: _t->populateDevices((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->on_pushButton_addDevice_clicked(); break;
        case 6: _t->on_pushButton_4_clicked(); break;
        case 7: _t->on_pushbutton_setThreshold3_2_clicked(); break;
        case 8: _t->on_pushbutton_set1_clicked(); break;
        case 9: _t->on_pushbutton_set2_clicked(); break;
        case 10: _t->on_pushbutton_set3_clicked(); break;
        case 11: _t->on_helpTutorial_button_clicked(); break;
        case 12: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_comboBox_loadController_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_pushButton_addDevice_2_clicked(); break;
        case 15: _t->on_pushButton_clicked(); break;
        case 16: _t->on_checkBox_smartDM_clicked(); break;
        case 17: _t->on_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->on_checkBox_2_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->on_checkBox_3_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->on_checkBox_4_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->on_pushButton_2_clicked(); break;
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
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
