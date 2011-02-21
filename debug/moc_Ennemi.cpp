/****************************************************************************
** Meta object code from reading C++ file 'Ennemi.h'
**
** Created: Sun 30. Jan 15:07:25 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Ennemi.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Ennemi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Ennemi[] = {

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
       8,    7,    7,    7, 0x0a,
      22,    7,    7,    7, 0x0a,
      37,    7,    7,    7, 0x0a,
      54,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Ennemi[] = {
    "Ennemi\0\0updateFroid()\0updatePoison()\0"
    "clignotePoison()\0animationFini()\0"
};

const QMetaObject Ennemi::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Ennemi,
      qt_meta_data_Ennemi, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Ennemi::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Ennemi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Ennemi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Ennemi))
        return static_cast<void*>(const_cast< Ennemi*>(this));
    if (!strcmp(_clname, "Constante"))
        return static_cast< Constante*>(const_cast< Ennemi*>(this));
    return QWidget::qt_metacast(_clname);
}

int Ennemi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateFroid(); break;
        case 1: updatePoison(); break;
        case 2: clignotePoison(); break;
        case 3: animationFini(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
