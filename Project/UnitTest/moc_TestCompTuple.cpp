/****************************************************************************
** Meta object code from reading C++ file 'TestCompTuple.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "TestCompTuple.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TestCompTuple.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestCompTuple_t {
    const uint offsetsAndSize[26];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TestCompTuple_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TestCompTuple_t qt_meta_stringdata_TestCompTuple = {
    {
QT_MOC_LITERAL(0, 13), // "TestCompTuple"
QT_MOC_LITERAL(14, 12), // "initTestCase"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 15), // "cleanupTestCase"
QT_MOC_LITERAL(44, 5), // "test1"
QT_MOC_LITERAL(50, 5), // "test2"
QT_MOC_LITERAL(56, 5), // "test3"
QT_MOC_LITERAL(62, 5), // "test4"
QT_MOC_LITERAL(68, 5), // "test5"
QT_MOC_LITERAL(74, 5), // "test6"
QT_MOC_LITERAL(80, 5), // "test7"
QT_MOC_LITERAL(86, 5), // "test8"
QT_MOC_LITERAL(92, 5) // "test9"

    },
    "TestCompTuple\0initTestCase\0\0cleanupTestCase\0"
    "test1\0test2\0test3\0test4\0test5\0test6\0"
    "test7\0test8\0test9"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestCompTuple[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x08,    0 /* Private */,
       3,    0,   81,    2, 0x08,    1 /* Private */,
       4,    0,   82,    2, 0x08,    2 /* Private */,
       5,    0,   83,    2, 0x08,    3 /* Private */,
       6,    0,   84,    2, 0x08,    4 /* Private */,
       7,    0,   85,    2, 0x08,    5 /* Private */,
       8,    0,   86,    2, 0x08,    6 /* Private */,
       9,    0,   87,    2, 0x08,    7 /* Private */,
      10,    0,   88,    2, 0x08,    8 /* Private */,
      11,    0,   89,    2, 0x08,    9 /* Private */,
      12,    0,   90,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TestCompTuple::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestCompTuple *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->initTestCase(); break;
        case 1: _t->cleanupTestCase(); break;
        case 2: _t->test1(); break;
        case 3: _t->test2(); break;
        case 4: _t->test3(); break;
        case 5: _t->test4(); break;
        case 6: _t->test5(); break;
        case 7: _t->test6(); break;
        case 8: _t->test7(); break;
        case 9: _t->test8(); break;
        case 10: _t->test9(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject TestCompTuple::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_TestCompTuple.offsetsAndSize,
    qt_meta_data_TestCompTuple,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TestCompTuple_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TestCompTuple::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestCompTuple::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestCompTuple.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TestCompTuple::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
