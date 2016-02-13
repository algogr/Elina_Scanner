/****************************************************************************
** Meta object code from reading C++ file 'fortosi_sel.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fortosi_sel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fortosi_sel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_fortosi_sel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      27,   12,   12,   12, 0x08,
      46,   12,   12,   12, 0x08,
      67,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_fortosi_sel[] = {
    "fortosi_sel\0\0new_fortosi()\0"
    "progress_fortosi()\0retransmit_fortosi()\0"
    "ready_read()\0"
};

void fortosi_sel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        fortosi_sel *_t = static_cast<fortosi_sel *>(_o);
        switch (_id) {
        case 0: _t->new_fortosi(); break;
        case 1: _t->progress_fortosi(); break;
        case 2: _t->retransmit_fortosi(); break;
        case 3: _t->ready_read(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData fortosi_sel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject fortosi_sel::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fortosi_sel,
      qt_meta_data_fortosi_sel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &fortosi_sel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *fortosi_sel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *fortosi_sel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fortosi_sel))
        return static_cast<void*>(const_cast< fortosi_sel*>(this));
    return QDialog::qt_metacast(_clname);
}

int fortosi_sel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
