/****************************************************************************
** Meta object code from reading C++ file 'shopmanagerform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CSApp3/shopmanagerform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shopmanagerform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ShopManagerForm_t {
    uint offsetsAndSizes[20];
    char stringdata0[16];
    char stringdata1[26];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[5];
    char stringdata5[7];
    char stringdata6[16];
    char stringdata7[11];
    char stringdata8[25];
    char stringdata9[28];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ShopManagerForm_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_ShopManagerForm_t qt_meta_stringdata_ShopManagerForm = {
    {
        QT_MOC_LITERAL(0, 15),  // "ShopManagerForm"
        QT_MOC_LITERAL(16, 25),  // "on_treeWidget_itemClicked"
        QT_MOC_LITERAL(42, 0),  // ""
        QT_MOC_LITERAL(43, 16),  // "QTreeWidgetItem*"
        QT_MOC_LITERAL(60, 4),  // "item"
        QT_MOC_LITERAL(65, 6),  // "column"
        QT_MOC_LITERAL(72, 15),  // "showContextMenu"
        QT_MOC_LITERAL(88, 10),  // "removeItem"
        QT_MOC_LITERAL(99, 24),  // "on_addPushButton_clicked"
        QT_MOC_LITERAL(124, 27)   // "on_searchPushButton_clicked"
    },
    "ShopManagerForm",
    "on_treeWidget_itemClicked",
    "",
    "QTreeWidgetItem*",
    "item",
    "column",
    "showContextMenu",
    "removeItem",
    "on_addPushButton_clicked",
    "on_searchPushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShopManagerForm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   44,    2, 0x08,    1 /* Private */,
       6,    1,   49,    2, 0x08,    4 /* Private */,
       7,    0,   52,    2, 0x08,    6 /* Private */,
       8,    0,   53,    2, 0x08,    7 /* Private */,
       9,    0,   54,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ShopManagerForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShopManagerForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_treeWidget_itemClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->showContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 2: _t->removeItem(); break;
        case 3: _t->on_addPushButton_clicked(); break;
        case 4: _t->on_searchPushButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ShopManagerForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ShopManagerForm.offsetsAndSizes,
    qt_meta_data_ShopManagerForm,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ShopManagerForm_t
, QtPrivate::TypeAndForceComplete<ShopManagerForm, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *ShopManagerForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShopManagerForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShopManagerForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ShopManagerForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
