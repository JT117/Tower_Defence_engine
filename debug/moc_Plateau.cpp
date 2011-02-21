/****************************************************************************
** Meta object code from reading C++ file 'Plateau.h'
**
** Created: Sun 30. Jan 15:07:29 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Plateau.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Plateau.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Plateau[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      18,    8,    8,    8, 0x0a,
      27,    8,    8,    8, 0x0a,
      40,    8,    8,    8, 0x0a,
      56,    8,    8,    8, 0x0a,
      66,    8,    8,    8, 0x0a,
      92,    8,    8,    8, 0x0a,
     118,    8,    8,    8, 0x0a,
     144,    8,    8,    8, 0x0a,
     170,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Plateau[] = {
    "Plateau\0\0update()\0forbid()\0gainArgent()\0"
    "vagueSuivante()\0interet()\0"
    "constructionTourEnable1()\0"
    "constructionTourEnable2()\0"
    "constructionTourEnable3()\0"
    "constructionTourEnable4()\0"
    "constructionTourEnable5()\0"
};

const QMetaObject Plateau::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Plateau,
      qt_meta_data_Plateau, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Plateau::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Plateau::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Plateau::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Plateau))
        return static_cast<void*>(const_cast< Plateau*>(this));
    if (!strcmp(_clname, "Constante"))
        return static_cast< Constante*>(const_cast< Plateau*>(this));
    return QDialog::qt_metacast(_clname);
}

int Plateau::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: update(); break;
        case 1: forbid(); break;
        case 2: gainArgent(); break;
        case 3: vagueSuivante(); break;
        case 4: interet(); break;
        case 5: constructionTourEnable1(); break;
        case 6: constructionTourEnable2(); break;
        case 7: constructionTourEnable3(); break;
        case 8: constructionTourEnable4(); break;
        case 9: constructionTourEnable5(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
