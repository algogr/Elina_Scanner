/****************************************************************************
** Meta object code from reading C++ file 'profortosi_new_1.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "profortosi_new_1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profortosi_new_1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_profortosi_new_1[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      30,   17,   17,   17, 0x08,
      49,   17,   17,   17, 0x08,
      56,   17,   17,   17, 0x08,
      71,   63,   17,   17, 0x08,
      99,   93,   17,   17, 0x08,
     120,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_profortosi_new_1[] = {
    "profortosi_new_1\0\0startread()\0"
    "requestCustomers()\0next()\0back()\0"
    "row,col\0tableclicked(int,int)\0state\0"
    "change_language(int)\0onTypeChar()\0"
};

void profortosi_new_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        profortosi_new_1 *_t = static_cast<profortosi_new_1 *>(_o);
        switch (_id) {
        case 0: _t->startread(); break;
        case 1: _t->requestCustomers(); break;
        case 2: _t->next(); break;
        case 3: _t->back(); break;
        case 4: _t->tableclicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->change_language((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onTypeChar(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData profortosi_new_1::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject profortosi_new_1::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_profortosi_new_1,
      qt_meta_data_profortosi_new_1, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &profortosi_new_1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *profortosi_new_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *profortosi_new_1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_profortosi_new_1))
        return static_cast<void*>(const_cast< profortosi_new_1*>(this));
    return QDialog::qt_metacast(_clname);
}

int profortosi_new_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
