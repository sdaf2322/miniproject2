/****************************************************************************
** Meta object code from reading C++ file 'productmanagerform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CSApp3/productmanagerform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'productmanagerform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProductManagerForm_t {
    uint offsetsAndSizes[26];
    char stringdata0[19];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[26];
    char stringdata5[17];
    char stringdata6[5];
    char stringdata7[7];
    char stringdata8[16];
    char stringdata9[11];
    char stringdata10[25];
    char stringdata11[28];
    char stringdata12[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ProductManagerForm_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_ProductManagerForm_t qt_meta_stringdata_ProductManagerForm = {
    {
        QT_MOC_LITERAL(0, 18),  // "ProductManagerForm"
        QT_MOC_LITERAL(19, 12),  // "productAdded"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 15),  // "sendProductInfo"
        QT_MOC_LITERAL(49, 25),  // "on_treeWidget_itemClicked"
        QT_MOC_LITERAL(75, 16),  // "QTreeWidgetItem*"
        QT_MOC_LITERAL(92, 4),  // "item"
        QT_MOC_LITERAL(97, 6),  // "column"
        QT_MOC_LITERAL(104, 15),  // "showContextMenu"
        QT_MOC_LITERAL(120, 10),  // "removeItem"
        QT_MOC_LITERAL(131, 24),  // "on_addPushButton_clicked"
        QT_MOC_LITERAL(156, 27),  // "on_modifyPushButton_clicked"
        QT_MOC_LITERAL(184, 27)   // "on_searchPushButton_clicked"
    },
    "ProductManagerForm",
    "productAdded",
    "",
    "sendProductInfo",
    "on_treeWidget_itemClicked",
    "QTreeWidgetItem*",
    "item",
    "column",
    "showContextMenu",
    "removeItem",
    "on_addPushButton_clicked",
    "on_modifyPushButton_clicked",
    "on_searchPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProductManagerForm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   62,    2, 0x06,    1 /* Public */,
       3,    3,   67,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    2,   74,    2, 0x08,    8 /* Private */,
       8,    1,   79,    2, 0x08,   11 /* Private */,
       9,    0,   82,    2, 0x08,   13 /* Private */,
      10,    0,   83,    2, 0x08,   14 /* Private */,
      11,    0,   84,    2, 0x08,   15 /* Private */,
      12,    0,   85,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ProductManagerForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ProductManagerForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->productAdded((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->sendProductInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->on_treeWidget_itemClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->showContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 4: _t->removeItem(); break;
        case 5: _t->on_addPushButton_clicked(); break;
        case 6: _t->on_modifyPushButton_clicked(); break;
        case 7: _t->on_searchPushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ProductManagerForm::*)(int , QString );
            if (_t _q_method = &ProductManagerForm::productAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ProductManagerForm::*)(QString , QString , QString );
            if (_t _q_method = &ProductManagerForm::sendProductInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ProductManagerForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ProductManagerForm.offsetsAndSizes,
    qt_meta_data_ProductManagerForm,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ProductManagerForm_t
, QtPrivate::TypeAndForceComplete<ProductManagerForm, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ProductManagerForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProductManagerForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProductManagerForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ProductManagerForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ProductManagerForm::productAdded(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProductManagerForm::sendProductInfo(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
