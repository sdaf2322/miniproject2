/****************************************************************************
** Meta object code from reading C++ file 'serverform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CSApp3/serverform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ServerForm_t {
    uint offsetsAndSizes[20];
    char stringdata0[11];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[13];
    char stringdata5[10];
    char stringdata6[13];
    char stringdata7[8];
    char stringdata8[47];
    char stringdata9[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ServerForm_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_ServerForm_t qt_meta_stringdata_ServerForm = {
    {
        QT_MOC_LITERAL(0, 10),  // "ServerForm"
        QT_MOC_LITERAL(11, 13),  // "clientConnect"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 11),  // "receiveData"
        QT_MOC_LITERAL(38, 12),  // "removeClient"
        QT_MOC_LITERAL(51, 9),  // "addClient"
        QT_MOC_LITERAL(61, 12),  // "inviteClient"
        QT_MOC_LITERAL(74, 7),  // "kickOut"
        QT_MOC_LITERAL(82, 46),  // "on_clientTreeWidget_customCon..."
        QT_MOC_LITERAL(129, 3)   // "pos"
    },
    "ServerForm",
    "clientConnect",
    "",
    "receiveData",
    "removeClient",
    "addClient",
    "inviteClient",
    "kickOut",
    "on_clientTreeWidget_customContextMenuRequested",
    "pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerForm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    2,   59,    2, 0x08,    4 /* Private */,
       6,    0,   64,    2, 0x08,    7 /* Private */,
       7,    0,   65,    2, 0x08,    8 /* Private */,
       8,    1,   66,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    9,

       0        // eod
};

void ServerForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ServerForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clientConnect(); break;
        case 1: _t->receiveData(); break;
        case 2: _t->removeClient(); break;
        case 3: _t->addClient((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->inviteClient(); break;
        case 5: _t->kickOut(); break;
        case 6: _t->on_clientTreeWidget_customContextMenuRequested((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ServerForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ServerForm.offsetsAndSizes,
    qt_meta_data_ServerForm,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_ServerForm_t
, QtPrivate::TypeAndForceComplete<ServerForm, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>


>,
    nullptr
} };


const QMetaObject *ServerForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ServerForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ServerForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
