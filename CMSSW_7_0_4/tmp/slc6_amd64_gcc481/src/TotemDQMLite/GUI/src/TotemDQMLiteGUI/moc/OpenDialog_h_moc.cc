/****************************************************************************
** Meta object code from reading C++ file 'OpenDialog.h'
**
** Created: Mon Jul 11 23:33:09 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../src/TotemDQMLite/GUI/interface/OpenDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OpenDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OpenDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      22,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      49,   11,   11,   11, 0x08,
      64,   11,   11,   11, 0x08,
      78,   11,   11,   11, 0x08,
      95,   11,   11,   11, 0x08,
     108,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OpenDialog[] = {
    "OpenDialog\0\0AddReco()\0ValidateInput()\0"
    "EditConf()\0HistBackward()\0HistForward()\0"
    "ClearRecoFiles()\0BrowseConf()\0"
    "BrowseLayout()\0"
};

void OpenDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OpenDialog *_t = static_cast<OpenDialog *>(_o);
        switch (_id) {
        case 0: _t->AddReco(); break;
        case 1: _t->ValidateInput(); break;
        case 2: _t->EditConf(); break;
        case 3: _t->HistBackward(); break;
        case 4: _t->HistForward(); break;
        case 5: _t->ClearRecoFiles(); break;
        case 6: _t->BrowseConf(); break;
        case 7: _t->BrowseLayout(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OpenDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OpenDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_OpenDialog,
      qt_meta_data_OpenDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OpenDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OpenDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OpenDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OpenDialog))
        return static_cast<void*>(const_cast< OpenDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int OpenDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
