/****************************************************************************
** Meta object code from reading C++ file 'profortosi_progress_1.h'
**
** Created: Tue Mar 12 18:50:54 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "profortosi_progress_1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profortosi_progress_1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_profortosi_progress_1[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x08,
      36,   22,   22,   22, 0x08,
      45,   22,   22,   22, 0x08,
      52,   22,   22,   22, 0x08,
      72,   64,   22,   22, 0x08,
      94,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_profortosi_progress_1[] = {
    "profortosi_progress_1\0\0continious()\0"
    "review()\0back()\0startread()\0row,col\0"
    "tableclicked(int,int)\0delete_pf()\0"
};

void profortosi_progress_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        profortosi_progress_1 *_t = static_cast<profortosi_progress_1 *>(_o);
        switch (_id) {
        case 0: _t->continious(); break;
        case 1: _t->review(); break;
        case 2: _t->back(); break;
        case 3: _t->startread(); break;
        case 4: _t->tableclicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->delete_pf(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData profortosi_progress_1::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject profortosi_progress_1::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_profortosi_progress_1,
      qt_meta_data_profortosi_progress_1, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &profortosi_progress_1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *profortosi_progress_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *profortosi_progress_1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_profortosi_progress_1))
        return static_cast<void*>(const_cast< profortosi_progress_1*>(this));
    return QDialog::qt_metacast(_clname);
}

int profortosi_progress_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
