/****************************************************************************
** Meta object code from reading C++ file 'multiimagewidget.h'
**
** Created: Mon May 28 21:33:05 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../multiimagewidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiimagewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MultiImageWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      27,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      74,   50,   17,   17, 0x0a,
     121,  106,   17,   17, 0x2a,
     152,  145,   17,   17, 0x2a,
     171,  168,   17,   17, 0x0a,
     198,  168,   17,   17, 0x0a,
     227,   17,   17,   17, 0x08,
     235,  168,   17,   17, 0x08,
     259,   18,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MultiImageWidget[] = {
    "MultiImageWidget\0\0fileName\0"
    "displayPixmap(QString)\0pixmap,comment,fileName\0"
    "append(QPixmap,QString,QString)\0"
    "pixmap,comment\0append(QPixmap,QString)\0"
    "pixmap\0append(QPixmap)\0ci\0"
    "reference(CommentedImage*)\0"
    "dereference(CommentedImage*)\0clear()\0"
    "remove(CommentedImage*)\0display(QString)\0"
};

const QMetaObject MultiImageWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MultiImageWidget,
      qt_meta_data_MultiImageWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MultiImageWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MultiImageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MultiImageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MultiImageWidget))
        return static_cast<void*>(const_cast< MultiImageWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MultiImageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: displayPixmap((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: append((*reinterpret_cast< const QPixmap(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: append((*reinterpret_cast< const QPixmap(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: append((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 4: reference((*reinterpret_cast< CommentedImage*(*)>(_a[1]))); break;
        case 5: dereference((*reinterpret_cast< CommentedImage*(*)>(_a[1]))); break;
        case 6: clear(); break;
        case 7: remove((*reinterpret_cast< CommentedImage*(*)>(_a[1]))); break;
        case 8: display((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MultiImageWidget::displayPixmap(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
