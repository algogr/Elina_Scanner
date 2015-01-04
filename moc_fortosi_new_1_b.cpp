/****************************************************************************
** Meta object code from reading C++ file 'fortosi_new_1_b.h'
**
** Created: Sat Jan 3 15:11:15 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fortosi_new_1_b.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fortosi_new_1_b.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_fortosi_new_1_b[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      24,   16,   16,   16, 0x08,
      31,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_fortosi_new_1_b[] = {
    "fortosi_new_1_b\0\0back()\0loop()\0code()\0"
};

const QMetaObject fortosi_new_1_b::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fortosi_new_1_b,
      qt_meta_data_fortosi_new_1_b, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &fortosi_new_1_b::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *fortosi_new_1_b::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *fortosi_new_1_b::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fortosi_new_1_b))
        return static_cast<void*>(const_cast< fortosi_new_1_b*>(this));
    return QDialog::qt_metacast(_clname);
}

int fortosi_new_1_b::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: back(); break;
        case 1: loop(); break;
        case 2: code(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
