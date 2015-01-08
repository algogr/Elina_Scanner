/****************************************************************************
** Meta object code from reading C++ file 'read_label.h'
**
** Created: Thu Jan 8 12:59:47 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "read_label.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'read_label.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_read_label[] = {

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

const QMetaObject read_label::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_read_label,
      qt_meta_data_read_label, 0 }
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
        switch (_id) {
        case 0: send_code(); break;
        case 1: startread(); break;
        case 2: clear_edit(); break;
        case 3: end_it(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
