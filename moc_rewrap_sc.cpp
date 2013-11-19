/****************************************************************************
** Meta object code from reading C++ file 'rewrap_sc.h'
**
** Created: Wed Mar 13 13:37:01 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rewrap_sc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rewrap_sc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rewrap_sc[] = {

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
      11,   10,   10,   10, 0x08,
      25,   10,   10,   10, 0x08,
      40,   10,   10,   10, 0x08,
      55,   10,   10,   10, 0x08,
      70,   10,   10,   10, 0x08,
      85,   10,   10,   10, 0x08,
     100,   10,   10,   10, 0x08,
     116,   10,   10,   10, 0x08,
     132,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rewrap_sc[] = {
    "rewrap_sc\0\0scanned_old()\0scanned_new1()\0"
    "scanned_new2()\0scanned_new3()\0"
    "scanned_new4()\0scanned_new5()\0"
    "insertClicked()\0cancelClicked()\0"
    "startread()\0"
};

void rewrap_sc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        rewrap_sc *_t = static_cast<rewrap_sc *>(_o);
        switch (_id) {
        case 0: _t->scanned_old(); break;
        case 1: _t->scanned_new1(); break;
        case 2: _t->scanned_new2(); break;
        case 3: _t->scanned_new3(); break;
        case 4: _t->scanned_new4(); break;
        case 5: _t->scanned_new5(); break;
        case 6: _t->insertClicked(); break;
        case 7: _t->cancelClicked(); break;
        case 8: _t->startread(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rewrap_sc::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rewrap_sc::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_rewrap_sc,
      qt_meta_data_rewrap_sc, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rewrap_sc::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rewrap_sc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rewrap_sc::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rewrap_sc))
        return static_cast<void*>(const_cast< rewrap_sc*>(this));
    return QDialog::qt_metacast(_clname);
}

int rewrap_sc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
