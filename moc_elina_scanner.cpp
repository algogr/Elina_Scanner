/****************************************************************************
** Meta object code from reading C++ file 'elina_scanner.h'
**
** Created: Wed Mar 13 13:36:57 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "elina_scanner.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elina_scanner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Elina_Scanner[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      25,   14,   14,   14, 0x08,
      38,   14,   14,   14, 0x08,
      51,   14,   14,   14, 0x08,
      66,   14,   14,   14, 0x08,
      83,   14,   14,   14, 0x08,
      98,   14,   14,   14, 0x08,
     113,   14,   14,   14, 0x08,
     121,   14,   14,   14, 0x08,
     137,   14,   14,   14, 0x08,
     149,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Elina_Scanner[] = {
    "Elina_Scanner\0\0fortosi()\0profortosi()\0"
    "apografi_s()\0katastrofi_s()\0"
    "change_label_s()\0read_label_s()\0"
    "rewrap_label()\0error()\0transmit_data()\0"
    "startread()\0returnroll()\0"
};

void Elina_Scanner::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Elina_Scanner *_t = static_cast<Elina_Scanner *>(_o);
        switch (_id) {
        case 0: _t->fortosi(); break;
        case 1: _t->profortosi(); break;
        case 2: _t->apografi_s(); break;
        case 3: _t->katastrofi_s(); break;
        case 4: _t->change_label_s(); break;
        case 5: _t->read_label_s(); break;
        case 6: _t->rewrap_label(); break;
        case 7: _t->error(); break;
        case 8: _t->transmit_data(); break;
        case 9: _t->startread(); break;
        case 10: _t->returnroll(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Elina_Scanner::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Elina_Scanner::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Elina_Scanner,
      qt_meta_data_Elina_Scanner, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Elina_Scanner::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Elina_Scanner::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Elina_Scanner::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Elina_Scanner))
        return static_cast<void*>(const_cast< Elina_Scanner*>(this));
    return QDialog::qt_metacast(_clname);
}

int Elina_Scanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
