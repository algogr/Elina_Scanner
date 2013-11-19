/****************************************************************************
** Meta object code from reading C++ file 'fortosi_new_1.h'
**
** Created: Tue Sep 4 10:14:30 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fortosi_new_1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fortosi_new_1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_fortosi_new_1[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      27,   14,   14,   14, 0x08,
      46,   14,   14,   14, 0x08,
      53,   14,   14,   14, 0x08,
      68,   60,   14,   14, 0x08,
      90,   14,   14,   14, 0x08,
      97,   14,   14,   14, 0x08,
     116,  110,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_fortosi_new_1[] = {
    "fortosi_new_1\0\0startread()\0"
    "requestCustomers()\0next()\0back()\0"
    "row,col\0tableclicked(int,int)\0prof()\0"
    "onTypeChar()\0state\0change_language(int)\0"
};

const QMetaObject fortosi_new_1::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fortosi_new_1,
      qt_meta_data_fortosi_new_1, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &fortosi_new_1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *fortosi_new_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *fortosi_new_1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fortosi_new_1))
        return static_cast<void*>(const_cast< fortosi_new_1*>(this));
    return QDialog::qt_metacast(_clname);
}

int fortosi_new_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startread(); break;
        case 1: requestCustomers(); break;
        case 2: next(); break;
        case 3: back(); break;
        case 4: tableclicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: prof(); break;
        case 6: onTypeChar(); break;
        case 7: change_language((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
