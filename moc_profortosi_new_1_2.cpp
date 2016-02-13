/****************************************************************************
** Meta object code from reading C++ file 'profortosi_new_1_2.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "profortosi_new_1_2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profortosi_new_1_2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_profortosi_new_1_2[] = {

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
      20,   19,   19,   19, 0x08,
      37,   19,   19,   19, 0x08,
      44,   19,   19,   19, 0x08,
      55,   19,   19,   19, 0x08,
      67,   19,   19,   19, 0x08,
      74,   19,   19,   19, 0x08,
      83,   19,   19,   19, 0x08,
      98,   19,   19,   19, 0x08,
     134,  123,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_profortosi_new_1_2[] = {
    "profortosi_new_1_2\0\0startreadItems()\0"
    "scan()\0finalize()\0temporary()\0back()\0"
    "delrow()\0requestItems()\0"
    "cellclicked(QModelIndex)\0row,column\0"
    "tableclicked(int,int)\0"
};

void profortosi_new_1_2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        profortosi_new_1_2 *_t = static_cast<profortosi_new_1_2 *>(_o);
        switch (_id) {
        case 0: _t->startreadItems(); break;
        case 1: _t->scan(); break;
        case 2: _t->finalize(); break;
        case 3: _t->temporary(); break;
        case 4: _t->back(); break;
        case 5: _t->delrow(); break;
        case 6: _t->requestItems(); break;
        case 7: _t->cellclicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->tableclicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData profortosi_new_1_2::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject profortosi_new_1_2::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_profortosi_new_1_2,
      qt_meta_data_profortosi_new_1_2, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &profortosi_new_1_2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *profortosi_new_1_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *profortosi_new_1_2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_profortosi_new_1_2))
        return static_cast<void*>(const_cast< profortosi_new_1_2*>(this));
    return QDialog::qt_metacast(_clname);
}

int profortosi_new_1_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
