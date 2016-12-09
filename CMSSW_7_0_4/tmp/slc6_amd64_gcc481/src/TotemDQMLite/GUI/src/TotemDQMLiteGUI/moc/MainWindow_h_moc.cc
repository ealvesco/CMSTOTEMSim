/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Mon Jul 11 23:33:03 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../../src/TotemDQMLite/GUI/interface/MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
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
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      22,   11,   11,   11, 0x0a,
      38,   11,   11,   11, 0x0a,
      50,   11,   11,   11, 0x0a,
      59,   11,   11,   11, 0x0a,
      75,   11,   11,   11, 0x0a,
      95,   88,   11,   11, 0x0a,
     144,   11,  139,   11, 0x0a,
     199,  157,  139,   11, 0x0a,
     262,  260,   11,   11, 0x0a,
     282,   11,   11,   11, 0x0a,
     299,   11,   11,   11, 0x0a,
     320,  316,   11,   11, 0x0a,
     356,  342,   11,   11, 0x0a,
     393,   11,   11,   11, 0x0a,
     406,   11,   11,   11, 0x0a,
     419,   11,   11,   11, 0x0a,
     433,   11,   11,   11, 0x0a,
     447,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0Refresh()\0RefreshCanvas()\0"
    "AddWindow()\0AddTab()\0AddWindowFrom()\0"
    "AddTabFrom()\0,ident\0"
    "OpenCanvasInNewWindow(DQMPlot*,std::string)\0"
    "bool\0OpenSource()\0"
    "recoFileNames,confFileName,layoutFileName\0"
    "OpenSource(std::vector<std::string>,std::string,std::string)\0"
    "n\0EventNrChanged(int)\0EventNumberInc()\0"
    "EventNumberDec()\0idx\0RunNumberChanged(int)\0"
    "runNr,eventNr\0RunAndEventNumbersChanged(uint,uint)\0"
    "SaveLayout()\0LoadLayout()\0ClearLayout()\0"
    "CloseSource()\0SaveAs()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->Refresh(); break;
        case 1: _t->RefreshCanvas(); break;
        case 2: _t->AddWindow(); break;
        case 3: _t->AddTab(); break;
        case 4: _t->AddWindowFrom(); break;
        case 5: _t->AddTabFrom(); break;
        case 6: _t->OpenCanvasInNewWindow((*reinterpret_cast< DQMPlot*(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2]))); break;
        case 7: { bool _r = _t->OpenSource();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = _t->OpenSource((*reinterpret_cast< const std::vector<std::string>(*)>(_a[1])),(*reinterpret_cast< const std::string(*)>(_a[2])),(*reinterpret_cast< const std::string(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: _t->EventNrChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->EventNumberInc(); break;
        case 11: _t->EventNumberDec(); break;
        case 12: _t->RunNumberChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->RunAndEventNumbersChanged((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 14: _t->SaveLayout(); break;
        case 15: _t->LoadLayout(); break;
        case 16: _t->ClearLayout(); break;
        case 17: _t->CloseSource(); break;
        case 18: _t->SaveAs(); break;
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
