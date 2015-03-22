/****************************************************************************
** Meta object code from reading C++ file 'setthresholds.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "setthresholds.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setthresholds.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SetThresholds[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   15,   14,   14, 0x08,
      54,   15,   14,   14, 0x08,
      88,   15,   14,   14, 0x08,
     122,   15,   14,   14, 0x08,
     156,   15,   14,   14, 0x08,
     190,   15,   14,   14, 0x08,
     224,   14,   14,   14, 0x08,
     248,   14,   14,   14, 0x08,
     267,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SetThresholds[] = {
    "SetThresholds\0\0arg1\0"
    "on_lineEdit_2_textEdited(QString)\0"
    "on_lineEdit_3_textEdited(QString)\0"
    "on_lineEdit_4_textEdited(QString)\0"
    "on_lineEdit_5_textEdited(QString)\0"
    "on_lineEdit_6_textEdited(QString)\0"
    "on_lineEdit_7_textEdited(QString)\0"
    "on_buttonBox_accepted()\0CheckForValidity()\0"
    "on_Apply_clicked()\0"
};

void SetThresholds::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SetThresholds *_t = static_cast<SetThresholds *>(_o);
        switch (_id) {
        case 0: _t->on_lineEdit_2_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_lineEdit_3_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_lineEdit_4_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_lineEdit_5_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_lineEdit_6_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_lineEdit_7_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_buttonBox_accepted(); break;
        case 7: _t->CheckForValidity(); break;
        case 8: _t->on_Apply_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SetThresholds::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SetThresholds::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SetThresholds,
      qt_meta_data_SetThresholds, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SetThresholds::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SetThresholds::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SetThresholds::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SetThresholds))
        return static_cast<void*>(const_cast< SetThresholds*>(this));
    return QDialog::qt_metacast(_clname);
}

int SetThresholds::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
