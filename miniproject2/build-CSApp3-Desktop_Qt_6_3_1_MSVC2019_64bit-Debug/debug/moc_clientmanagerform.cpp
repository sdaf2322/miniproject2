/****************************************************************************
** Meta object code from reading C++ file 'clientmanagerform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CSApp3/clientmanagerform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientmanagerform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientManagerForm_t {
    const uint offsetsAndSize[28];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_ClientManagerForm_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_ClientManagerForm_t qt_meta_stringdata_ClientManagerForm = {
    {
QT_MOC_LITERAL(0, 17), // "ClientManagerForm"
QT_MOC_LITERAL(18, 11), // "clientAdded"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 14), // "sendClientInfo"
QT_MOC_LITERAL(46, 25), // "on_treeWidget_itemClicked"
QT_MOC_LITERAL(72, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(89, 4), // "item"
QT_MOC_LITERAL(94, 6), // "column"
QT_MOC_LITERAL(101, 15), // "showContextMenu"
QT_MOC_LITERAL(117, 10), // "removeItem"
QT_MOC_LITERAL(128, 24), // "on_addPushButton_clicked"
QT_MOC_LITERAL(153, 27), // "on_modifyPushButton_clicked"
QT_MOC_LITERAL(181, 27), // "on_searchPushButton_clicked"
QT_MOC_LITERAL(209, 16) // "acceptClientInfo"

    },
    "ClientManagerForm\0clientAdded\0\0"
    "sendClientInfo\0on_treeWidget_itemClicked\0"
    "QTreeWidgetItem*\0item\0column\0"
    "showContextMenu\0removeItem\0"
    "on_addPushButton_clicked\0"
    "on_modifyPushButton_clicked\0"
    "on_searchPushButton_clicked\0"
    "acceptClientInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientManagerForm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   68,    2, 0x06,    1 /* Public */,
       3,    3,   73,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    2,   80,    2, 0x08,    8 /* Private */,
       8,    1,   85,    2, 0x08,   11 /* Private */,
       9,    0,   88,    2, 0x08,   13 /* Private */,
      10,    0,   89,    2, 0x08,   14 /* Private */,
      11,    0,   90,    2, 0x08,   15 /* Private */,
      12,    0,   91,    2, 0x08,   16 /* Private */,
      13,    1,   92,    2, 0x08,   17 /* Private */,

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
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void ClientManagerForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientManagerForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clientAdded((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->sendClientInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->on_treeWidget_itemClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->showContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 4: _t->removeItem(); break;
        case 5: _t->on_addPushButton_clicked(); break;
        case 6: _t->on_modifyPushButton_clicked(); break;
        case 7: _t->on_searchPushButton_clicked(); break;
        case 8: _t->acceptClientInfo((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClientManagerForm::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManagerForm::clientAdded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClientManagerForm::*)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManagerForm::sendClientInfo)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject ClientManagerForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ClientManagerForm.offsetsAndSize,
    qt_meta_data_ClientManagerForm,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ClientManagerForm_t
, QtPrivate::TypeAndForceComplete<ClientManagerForm, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *ClientManagerForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientManagerForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientManagerForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ClientManagerForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ClientManagerForm::clientAdded(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientManagerForm::sendClientInfo(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
