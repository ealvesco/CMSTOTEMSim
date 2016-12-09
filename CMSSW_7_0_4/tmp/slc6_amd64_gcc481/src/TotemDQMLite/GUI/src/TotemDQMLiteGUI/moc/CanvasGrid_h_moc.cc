/****************************************************************************
** Meta object code from reading C++ file 'CanvasGrid.h'
**
** Created: Mon Jul 11 23:33:08 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../src/TotemDQMLite/GUI/interface/CanvasGrid.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CanvasGrid.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CanvasGrid[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      21,   11,   11,   11, 0x0a,
      30,   11,   11,   11, 0x0a,
      39,   11,   11,   11, 0x0a,
      48,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CanvasGrid[] = {
    "CanvasGrid\0\0AddCol()\0AddRow()\0DelCol()\0"
    "DelRow()\0Screenshot()\0"
};

void CanvasGrid::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CanvasGrid *_t = static_cast<CanvasGrid *>(_o);
        switch (_id) {
        case 0: _t->AddCol(); break;
        case 1: _t->AddRow(); break;
        case 2: _t->DelCol(); break;
        case 3: _t->DelRow(); break;
        case 4: _t->Screenshot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData CanvasGrid::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CanvasGrid::staticMetaObject = {
    { &QGridLayout::staticMetaObject, qt_meta_stringdata_CanvasGrid,
      qt_meta_data_CanvasGrid, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CanvasGrid::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CanvasGrid::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CanvasGrid::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CanvasGrid))
        return static_cast<void*>(const_cast< CanvasGrid*>(this));
    return QGridLayout::qt_metacast(_clname);
}

int CanvasGrid::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGridLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
