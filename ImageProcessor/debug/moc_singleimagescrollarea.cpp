/****************************************************************************
** Meta object code from reading C++ file 'singleimagescrollarea.h'
**
** Created: Sun May 27 11:35:08 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../singleimagescrollarea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'singleimagescrollarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SingleImageScrollArea[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   23,   22,   22, 0x0a,
      46,   22,   22,   22, 0x08,
      55,   22,   22,   22, 0x08,
      65,   22,   22,   22, 0x08,
      78,   22,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SingleImageScrollArea[] = {
    "SingleImageScrollArea\0\0fileName\0"
    "load(QString)\0zoomIn()\0zoomOut()\0"
    "normalSize()\0fitToWindow()\0"
};

const QMetaObject SingleImageScrollArea::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_SingleImageScrollArea,
      qt_meta_data_SingleImageScrollArea, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SingleImageScrollArea::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SingleImageScrollArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SingleImageScrollArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SingleImageScrollArea))
        return static_cast<void*>(const_cast< SingleImageScrollArea*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int SingleImageScrollArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: load((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: zoomIn(); break;
        case 2: zoomOut(); break;
        case 3: normalSize(); break;
        case 4: fitToWindow(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
