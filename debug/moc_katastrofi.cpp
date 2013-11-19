/****************************************************************************
** Meta object code from reading C++ file 'katastrofi.h'
**
** Created: Tue Sep 4 10:38:28 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../katastrofi.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'katastrofi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_katastrofi[] = {

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
      12,   11,   11,   11, 0x08,
      19,   11,   11,   11, 0x08,
      31,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_katastrofi[] = {
    "katastrofi\0\0scan()\0insert_db()\0lock()\0"
    "close_now()\0"
};

const QMetaObject katastrofi::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_katastrofi,
      qt_meta_data_katastrofi, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &katastrofi::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *katastrofi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *katastrofi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_katastrofi))
        return static_cast<void*>(const_cast< katastrofi*>(this));
    return QDialog::qt_metacast(_clname);
}

int katastrofi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
