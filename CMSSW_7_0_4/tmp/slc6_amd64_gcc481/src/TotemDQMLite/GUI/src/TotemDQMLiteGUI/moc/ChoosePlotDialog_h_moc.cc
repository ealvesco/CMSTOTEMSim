/****************************************************************************
** Meta object code from reading C++ file 'ChoosePlotDialog.h'
**
** Created: Mon Jul 11 23:33:04 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../src/TotemDQMLite/GUI/interface/ChoosePlotDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChoosePlotDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ChoosePlotDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      34,   17,   17,   17, 0x0a,
      45,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ChoosePlotDialog[] = {
    "ChoosePlotDialog\0\0UpdateOutView()\0"
    "Accepted()\0Empty()\0"
};

void ChoosePlotDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ChoosePlotDialog *_t = static_cast<ChoosePlotDialog *>(_o);
        switch (_id) {
        case 0: _t->UpdateOutView(); break;
        case 1: _t->Accepted(); break;
        case 2: _t->Empty(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ChoosePlotDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ChoosePlotDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ChoosePlotDialog,
      qt_meta_data_ChoosePlotDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ChoosePlotDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ChoosePlotDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ChoosePlotDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ChoosePlotDialog))
        return static_cast<void*>(const_cast< ChoosePlotDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ChoosePlotDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
