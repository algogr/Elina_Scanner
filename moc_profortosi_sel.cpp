/****************************************************************************
** Meta object code from reading C++ file 'profortosi_sel.h'
**
** Created: Tue Mar 12 18:51:15 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "profortosi_sel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profortosi_sel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_profortosi_sel[] = {

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
      16,   15,   15,   15, 0x08,
      33,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_profortosi_sel[] = {
    "profortosi_sel\0\0new_profortosi()\0"
    "progress_profortosi()\0"
};

void profortosi_sel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        profortosi_sel *_t = static_cast<profortosi_sel *>(_o);
        switch (_id) {
        case 0: _t->new_profortosi(); break;
        case 1: _t->progress_profortosi(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData profortosi_sel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject profortosi_sel::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_profortosi_sel,
      qt_meta_data_profortosi_sel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &profortosi_sel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *profortosi_sel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *profortosi_sel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_profortosi_sel))
        return static_cast<void*>(const_cast< profortosi_sel*>(this));
    return QDialog::qt_metacast(_clname);
}

int profortosi_sel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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