/****************************************************************************
** Meta object code from reading C++ file 'imagewidget.h'
**
** Created: Mon May 28 21:33:09 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../imagewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   13,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,   41,   12,   12, 0x0a,
      64,   13,   12,   12, 0x0a,
      88,   12,   12,   12, 0x08,
      97,   12,   12,   12, 0x08,
     107,   12,   12,   12, 0x08,
     120,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ImageWidget[] = {
    "ImageWidget\0\0fitToWindow\0displayed(bool)\0"
    "fileName\0load(QString)\0fitToWindowChange(bool)\0"
    "zoomIn()\0zoomOut()\0normalSize()\0"
    "fitToWindow()\0"
};

const QMetaObject ImageWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ImageWidget,
      qt_meta_data_ImageWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageWidget))
        return static_cast<void*>(const_cast< ImageWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ImageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: displayed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: load((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: fitToWindowChange((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: zoomIn(); break;
        case 4: zoomOut(); break;
        case 5: normalSize(); break;
        case 6: fitToWindow(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ImageWidget::displayed(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
