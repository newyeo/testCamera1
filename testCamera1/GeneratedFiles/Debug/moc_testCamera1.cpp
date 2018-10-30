/****************************************************************************
** Meta object code from reading C++ file 'testCamera1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../testCamera1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testCamera1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_testCamera1_t {
    QByteArrayData data[21];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_testCamera1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_testCamera1_t qt_meta_stringdata_testCamera1 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "testCamera1"
QT_MOC_LITERAL(1, 12, 15), // "sendCloseSignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "shwoSrcSigal"
QT_MOC_LITERAL(4, 42, 12), // "shwoDstSigal"
QT_MOC_LITERAL(5, 55, 8), // "sendPara"
QT_MOC_LITERAL(6, 64, 15), // "sendStartSignal"
QT_MOC_LITERAL(7, 80, 9), // "slotStart"
QT_MOC_LITERAL(8, 90, 8), // "slotStop"
QT_MOC_LITERAL(9, 99, 12), // "showSrcImage"
QT_MOC_LITERAL(10, 112, 7), // "cv::Mat"
QT_MOC_LITERAL(11, 120, 3), // "img"
QT_MOC_LITERAL(12, 124, 8), // "showInfo"
QT_MOC_LITERAL(13, 133, 11), // "std::string"
QT_MOC_LITERAL(14, 145, 4), // "info"
QT_MOC_LITERAL(15, 150, 10), // "showResult"
QT_MOC_LITERAL(16, 161, 3), // "res"
QT_MOC_LITERAL(17, 165, 10), // "showSrcBtn"
QT_MOC_LITERAL(18, 176, 10), // "showDstBtn"
QT_MOC_LITERAL(19, 187, 10), // "getParaBtn"
QT_MOC_LITERAL(20, 198, 14) // "getTotalPixBtn"

    },
    "testCamera1\0sendCloseSignal\0\0shwoSrcSigal\0"
    "shwoDstSigal\0sendPara\0sendStartSignal\0"
    "slotStart\0slotStop\0showSrcImage\0cv::Mat\0"
    "img\0showInfo\0std::string\0info\0showResult\0"
    "res\0showSrcBtn\0showDstBtn\0getParaBtn\0"
    "getTotalPixBtn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_testCamera1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    3,   87,    2, 0x06 /* Public */,
       6,    0,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   95,    2, 0x08 /* Private */,
       8,    0,   96,    2, 0x08 /* Private */,
       9,    1,   97,    2, 0x08 /* Private */,
      12,    1,  100,    2, 0x08 /* Private */,
      15,    1,  103,    2, 0x08 /* Private */,
      17,    0,  106,    2, 0x08 /* Private */,
      18,    0,  107,    2, 0x08 /* Private */,
      19,    0,  108,    2, 0x08 /* Private */,
      20,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Float,    2,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void testCamera1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        testCamera1 *_t = static_cast<testCamera1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendCloseSignal(); break;
        case 1: _t->shwoSrcSigal(); break;
        case 2: _t->shwoDstSigal(); break;
        case 3: _t->sendPara((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 4: _t->sendStartSignal(); break;
        case 5: _t->slotStart(); break;
        case 6: _t->slotStop(); break;
        case 7: _t->showSrcImage((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 8: _t->showInfo((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 9: _t->showResult((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 10: _t->showSrcBtn(); break;
        case 11: _t->showDstBtn(); break;
        case 12: _t->getParaBtn(); break;
        case 13: _t->getTotalPixBtn(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (testCamera1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&testCamera1::sendCloseSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (testCamera1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&testCamera1::shwoSrcSigal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (testCamera1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&testCamera1::shwoDstSigal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (testCamera1::*_t)(int , int , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&testCamera1::sendPara)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (testCamera1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&testCamera1::sendStartSignal)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject testCamera1::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_testCamera1.data,
      qt_meta_data_testCamera1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *testCamera1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *testCamera1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_testCamera1.stringdata0))
        return static_cast<void*>(const_cast< testCamera1*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int testCamera1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void testCamera1::sendCloseSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void testCamera1::shwoSrcSigal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void testCamera1::shwoDstSigal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void testCamera1::sendPara(int _t1, int _t2, float _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void testCamera1::sendStartSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
