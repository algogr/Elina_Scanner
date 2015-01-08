/****************************************************************************
** Meta object code from reading C++ file 'apografi.h'
**
** Created: Thu Jan 8 12:59:50 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "apografi.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'apografi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_apografi[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      17,    9,    9,    9, 0x08,
      24,    9,    9,    9, 0x08,
      35,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_apografi[] = {
    "apografi\0\0scan()\0lock()\0comments()\0"
    "info()\0"
};

const QMetaObject apografi::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_apografi,
      qt_meta_data_apografi, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &apografi::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *apografi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *apografi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_apografi))
        return static_cast<void*>(const_cast< apografi*>(this));
    return QDialog::qt_metacast(_clname);
}

int apografi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: scan(); break;
        case 1: lock(); break;
        case 2: comments(); break;
        case 3: info(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
