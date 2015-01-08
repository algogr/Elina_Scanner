/****************************************************************************
** Meta object code from reading C++ file 'profortosi_progress_1_2.h'
**
** Created: Thu Jan 8 12:59:52 2015
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "profortosi_progress_1_2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profortosi_progress_1_2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_profortosi_progress_1_2[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      25,   24,   24,   24, 0x08,
      37,   24,   24,   24, 0x08,
      44,   24,   24,   24, 0x08,
      55,   24,   24,   24, 0x08,
      67,   24,   24,   24, 0x08,
      74,   24,   24,   24, 0x08,
      83,   24,   24,   24, 0x08,
      97,   24,   24,   24, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_profortosi_progress_1_2[] = {
    "profortosi_progress_1_2\0\0startread()\0"
    "scan()\0finalize()\0temporary()\0back()\0"
    "delrow()\0cellclicked()\0check()\0"
};

const QMetaObject profortosi_progress_1_2::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_profortosi_progress_1_2,
      qt_meta_data_profortosi_progress_1_2, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &profortosi_progress_1_2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *profortosi_progress_1_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *profortosi_progress_1_2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_profortosi_progress_1_2))
        return static_cast<void*>(const_cast< profortosi_progress_1_2*>(this));
    return QDialog::qt_metacast(_clname);
}

int profortosi_progress_1_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: startread(); break;
        case 1: scan(); break;
        case 2: finalize(); break;
        case 3: temporary(); break;
        case 4: back(); break;
        case 5: delrow(); break;
        case 6: cellclicked(); break;
        case 7: check(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
