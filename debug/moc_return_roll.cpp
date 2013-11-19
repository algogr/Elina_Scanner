/****************************************************************************
** Meta object code from reading C++ file 'return_roll.h'
**
** Created: Wed Aug 22 13:28:12 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../return_roll.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'return_roll.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_return_roll[] = {

 // content:
       4,       // revision
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
      20,   12,   12,   12, 0x08,
      32,   12,   12,   12, 0x08,
      39,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_return_roll[] = {
    "return_roll\0\0scan()\0insert_db()\0lock()\0"
    "close_now()\0"
};

const QMetaObject return_roll::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_return_roll,
      qt_meta_data_return_roll, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &return_roll::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *return_roll::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *return_roll::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_return_roll))
        return static_cast<void*>(const_cast< return_roll*>(this));
    return QDialog::qt_metacast(_clname);
}

int return_roll::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: scan(); break;
        case 1: insert_db(); break;
        case 2: lock(); break;
        case 3: close_now(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
