/****************************************************************************
** Meta object code from reading C++ file 'commentedimage.h'
**
** Created: Mon May 28 21:33:06 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../commentedimage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commentedimage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CommentedImage[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      26,   15,   15,   15, 0x05,
      39,   36,   15,   15, 0x05,
      67,   36,   15,   15, 0x05,
      97,   36,   15,   15, 0x05,
     144,  135,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     167,   15,   15,   15, 0x08,
     177,   15,   15,   15, 0x08,
     197,   15,   15,   15, 0x08,
     206,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CommentedImage[] = {
    "CommentedImage\0\0clicked()\0cleared()\0"
    "ci\0referenced(CommentedImage*)\0"
    "dereferenced(CommentedImage*)\0"
    "removeCommentedImage(CommentedImage*)\0"
    "fileName\0displayPixmap(QString)\0"
    "display()\0selectAsReference()\0remove()\0"
    "showProperty()\0"
};

const QMetaObject CommentedImage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CommentedImage,
      qt_meta_data_CommentedImage, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CommentedImage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CommentedImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CommentedImage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CommentedImage))
        return static_cast<void*>(const_cast< CommentedImage*>(this));
    return QWidget::qt_metacast(_clname);
}

int CommentedImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clicked(); break;
        case 1: cleared(); break;
        case 2: referenced((*reinterpret_cast< CommentedImage*(*)>(_a[1]))); break;
        case 3: dereferenced((*reinterpret_cast< CommentedImage*(*)>(_a[1]))); break;
        case 4: removeCommentedImage((*reinterpret_cast< CommentedImage*(*)>(_a[1]))); break;
        case 5: displayPixmap((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: display(); break;
        case 7: selectAsReference(); break;
        case 8: remove(); break;
        case 9: showProperty(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void CommentedImage::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CommentedImage::cleared()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void CommentedImage::referenced(CommentedImage * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CommentedImage::dereferenced(CommentedImage * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CommentedImage::removeCommentedImage(CommentedImage * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CommentedImage::displayPixmap(const QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
