/****************************************************************************
** Meta object code from reading C++ file 'network_test.h'
**
** Created: Thu Jan 8 12:59:50 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "network_test.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'network_test.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_network_test[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      27,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_network_test[] = {
    "network_test\0\0check_conn()\0error()\0"
};

const QMetaObject network_test::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_network_test,
      qt_meta_data_network_test, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &network_test::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *network_test::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *network_test::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_network_test))
        return static_cast<void*>(const_cast< network_test*>(this));
    return QObject::qt_metacast(_clname);
}

int network_test::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: check_conn(); break;
        case 1: error(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
