/****************************************************************************
** Meta object code from reading C++ file 'RunEventNavigationBox.h'
**
** Created: Mon Jul 11 23:33:05 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../src/TotemDQMLite/GUI/interface/RunEventNavigationBox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RunEventNavigationBox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RunEventNavigationBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x0a,
      38,   22,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RunEventNavigationBox[] = {
    "RunEventNavigationBox\0\0RunNrEditted()\0"
    "EventNrEditted()\0"
};

void RunEventNavigationBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RunEventNavigationBox *_t = static_cast<RunEventNavigationBox *>(_o);
        switch (_id) {
        case 0: _t->RunNrEditted(); break;
        case 1: _t->EventNrEditted(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData RunEventNavigationBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RunEventNavigationBox::staticMetaObject = {
    { &QGroupBox::staticMetaObject, qt_meta_stringdata_RunEventNavigationBox,
      qt_meta_data_RunEventNavigationBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RunEventNavigationBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RunEventNavigationBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RunEventNavigationBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RunEventNavigationBox))
        return static_cast<void*>(const_cast< RunEventNavigationBox*>(this));
    return QGroupBox::qt_metacast(_clname);
}

int RunEventNavigationBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGroupBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
