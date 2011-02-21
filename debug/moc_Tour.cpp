/****************************************************************************
** Meta object code from reading C++ file 'Tour.h'
**
** Created: Fri 28. Jan 16:18:13 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Tour.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Tour.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tour[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tour[] = {
    "Tour\0\0update()\0"
};

const QMetaObject Tour::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tour,
      qt_meta_data_Tour, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tour::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tour::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tour::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tour))
        return static_cast<void*>(const_cast< Tour*>(this));
    if (!strcmp(_clname, "Constante"))
        return static_cast< Constante*>(const_cast< Tour*>(this));
    return QWidget::qt_metacast(_clname);
}

int Tour::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: update(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
