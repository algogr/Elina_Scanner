/****************************************************************************
** Meta object code from reading C++ file 'fortosi_progress_1.h'
**
** Created: Tue Mar 12 18:51:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "fortosi_progress_1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fortosi_progress_1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_fortosi_progress_1[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      33,   19,   19,   19, 0x08,
      42,   19,   19,   19, 0x08,
      49,   19,   19,   19, 0x08,
      69,   61,   19,   19, 0x08,
      91,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_fortosi_progress_1[] = {
    "fortosi_progress_1\0\0continious()\0"
    "review()\0back()\0startread()\0row,col\0"
    "tableclicked(int,int)\0delete_f()\0"
};

void fortosi_progress_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        fortosi_progress_1 *_t = static_cast<fortosi_progress_1 *>(_o);
        switch (_id) {
        case 0: _t->continious(); break;
        case 1: _t->review(); break;
        case 2: _t->back(); break;
        case 3: _t->startread(); break;
        case 4: _t->tableclicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->delete_f(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData fortosi_progress_1::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject fortosi_progress_1::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_fortosi_progress_1,
      qt_meta_data_fortosi_progress_1, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &fortosi_progress_1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *fortosi_progress_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *fortosi_progress_1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_fortosi_progress_1))
        return static_cast<void*>(const_cast< fortosi_progress_1*>(this));
    return QDialog::qt_metacast(_clname);
}

int fortosi_progress_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
