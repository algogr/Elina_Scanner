/****************************************************************************
** Meta object code from reading C++ file 'sxpf.h'
**
** Created: Tue Sep 4 10:38:23 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sxpf.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sxpf.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_sxpf[] = {

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
       6,    5,    5,    5, 0x08,
      18,    5,    5,    5, 0x08,
      30,   26,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_sxpf[] = {
    "sxpf\0\0startread()\0close()\0x,y\0"
    "row_selected(int,int)\0"
};

const QMetaObject sxpf::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_sxpf,
      qt_meta_data_sxpf, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &sxpf::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *sxpf::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *sxpf::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_sxpf))
        return static_cast<void*>(const_cast< sxpf*>(this));
    return QDialog::qt_metacast(_clname);
}

int sxpf::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startread(); break;
        case 1: close(); break;
        case 2: row_selected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE