/****************************************************************************
** Meta object code from reading C++ file 'fortosi_new_1a.h'
**
** Created: Tue Sep 4 10:38:41 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../fortosi_new_1a.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fortosi_new_1a.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_fortosi_new_1a[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      23,   15,   15,   15, 0x08,
      32,   15,   15,   15, 0x08,
      39,   15,   15,   15, 0x08,
      59,   51,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_fortosi_new_1a[] = {
    "fortosi_new_1a\0\0next()\0review()\0back()\0"
    "startread()\0row,col\0tableclicked(int,int)\0"
};

const QMetaObject fortosi_new_1a::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_fortosi_new_1a,
      qt_meta_data_fortosi_new_1a, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &fortosi_new_1a::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *fortosi_new_1a::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *fortosi_new_1a::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fortosi_new_1a))
        return static_cast<void*>(const_cast< fortosi_new_1a*>(this));
    return QWidget::qt_metacast(_clname);
}

int fortosi_new_1a::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: next(); break;
        case 1: review(); break;
        case 2: back(); break;
        case 3: startread(); break;
        case 4: tableclicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE