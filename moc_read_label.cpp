/****************************************************************************
** Meta object code from reading C++ file 'read_label.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "read_label.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'read_label.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_read_label[] = {

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
      12,   11,   11,   11, 0x08,
      24,   11,   11,   11, 0x08,
      36,   11,   11,   11, 0x08,
      49,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_read_label[] = {
    "read_label\0\0send_code()\0startread()\0"
    "clear_edit()\0end_it()\0"
};

void read_label::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        read_label *_t = static_cast<read_label *>(_o);
        switch (_id) {
        case 0: _t->send_code(); break;
        case 1: _t->startread(); break;
        case 2: _t->clear_edit(); break;
        case 3: _t->end_it(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData read_label::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject read_label::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_read_label,
      qt_meta_data_read_label, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &read_label::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *read_label::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *read_label::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_read_label))
        return static_cast<void*>(const_cast< read_label*>(this));
    return QDialog::qt_metacast(_clname);
}

int read_label::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
