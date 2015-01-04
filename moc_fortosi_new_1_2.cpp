/****************************************************************************
** Meta object code from reading C++ file 'fortosi_new_1_2.h'
**
** Created: Sat Jan 3 15:11:11 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fortosi_new_1_2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fortosi_new_1_2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_fortosi_new_1_2[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      34,   16,   16,   16, 0x08,
      41,   16,   16,   16, 0x08,
      52,   16,   16,   16, 0x08,
      64,   16,   16,   16, 0x08,
      71,   16,   16,   16, 0x08,
      80,   16,   16,   16, 0x08,
     116,  105,   16,   16, 0x08,
     138,   16,   16,   16, 0x08,
     153,   16,   16,   16, 0x08,
     161,   16,   16,   16, 0x08,
     171,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_fortosi_new_1_2[] = {
    "fortosi_new_1_2\0\0startreadItems()\0"
    "scan()\0finalize()\0temporary()\0back()\0"
    "delrow()\0cellclicked(QModelIndex)\0"
    "row,column\0tableclicked(int,int)\0"
    "requestItems()\0check()\0compare()\0"
    "startread()\0"
};

const QMetaObject fortosi_new_1_2::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fortosi_new_1_2,
      qt_meta_data_fortosi_new_1_2, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &fortosi_new_1_2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *fortosi_new_1_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *fortosi_new_1_2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fortosi_new_1_2))
        return static_cast<void*>(const_cast< fortosi_new_1_2*>(this));
    return QDialog::qt_metacast(_clname);
}

int fortosi_new_1_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startreadItems(); break;
        case 1: scan(); break;
        case 2: finalize(); break;
        case 3: temporary(); break;
        case 4: back(); break;
        case 5: delrow(); break;
        case 6: cellclicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 7: tableclicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: requestItems(); break;
        case 9: check(); break;
        case 10: compare(); break;
        case 11: startread(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
