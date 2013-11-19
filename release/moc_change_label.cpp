/****************************************************************************
** Meta object code from reading C++ file 'change_label.h'
**
** Created: Tue Sep 4 10:13:35 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../change_label.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'change_label.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_change_label[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      28,   13,   13,   13, 0x08,
      39,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_change_label[] = {
    "change_label\0\0send_change()\0scan_old()\0"
    "scan_new()\0"
};

const QMetaObject change_label::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_change_label,
      qt_meta_data_change_label, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &change_label::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *change_label::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *change_label::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_change_label))
        return static_cast<void*>(const_cast< change_label*>(this));
    return QDialog::qt_metacast(_clname);
}

int change_label::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: send_change(); break;
        case 1: scan_old(); break;
        case 2: scan_new(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
