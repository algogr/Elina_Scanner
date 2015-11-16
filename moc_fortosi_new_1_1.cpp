/****************************************************************************
** Meta object code from reading C++ file 'fortosi_new_1_1.h'
**
** Created: Fri Aug 28 21:28:56 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fortosi_new_1_1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fortosi_new_1_1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_fortosi_new_1_1[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      24,   16,   16,   16, 0x08,
      35,   16,   16,   16, 0x08,
      47,   16,   16,   16, 0x08,
      54,   16,   16,   16, 0x08,
      79,   16,   16,   16, 0x08,
      88,   16,   16,   16, 0x08,
      96,   16,   16,   16, 0x08,
     106,   16,   16,   16, 0x08,
     118,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_fortosi_new_1_1[] = {
    "fortosi_new_1_1\0\0scan()\0finalize()\0"
    "temporary()\0back()\0cellclicked(QModelIndex)\0"
    "delrow()\0check()\0compare()\0startread()\0"
    "lineeditclicked()\0"
};

const QMetaObject fortosi_new_1_1::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fortosi_new_1_1,
      qt_meta_data_fortosi_new_1_1, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &fortosi_new_1_1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *fortosi_new_1_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *fortosi_new_1_1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fortosi_new_1_1))
        return static_cast<void*>(const_cast< fortosi_new_1_1*>(this));
    return QDialog::qt_metacast(_clname);
}

int fortosi_new_1_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: scan(); break;
        case 1: finalize(); break;
        case 2: temporary(); break;
        case 3: back(); break;
        case 4: cellclicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: delrow(); break;
        case 6: check(); break;
        case 7: compare(); break;
        case 8: startread(); break;
        case 9: lineeditclicked(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
