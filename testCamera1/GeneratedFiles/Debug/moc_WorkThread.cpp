/****************************************************************************
** Meta object code from reading C++ file 'WorkThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../WorkThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WorkThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_WorkThread_t {
    QByteArrayData data[15];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WorkThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WorkThread_t qt_meta_stringdata_WorkThread = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WorkThread"
QT_MOC_LITERAL(1, 11, 9), // "sendImage"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "cv::Mat"
QT_MOC_LITERAL(4, 30, 5), // "image"
QT_MOC_LITERAL(5, 36, 10), // "returnInfo"
QT_MOC_LITERAL(6, 47, 11), // "std::string"
QT_MOC_LITERAL(7, 59, 4), // "info"
QT_MOC_LITERAL(8, 64, 9), // "returnRes"
QT_MOC_LITERAL(9, 74, 3), // "res"
QT_MOC_LITERAL(10, 78, 14), // "closeDeviceBtn"
QT_MOC_LITERAL(11, 93, 13), // "showSourceImg"
QT_MOC_LITERAL(12, 107, 10), // "showDstImg"
QT_MOC_LITERAL(13, 118, 7), // "getPara"
QT_MOC_LITERAL(14, 126, 14) // "recv_startSlot"

    },
    "WorkThread\0sendImage\0\0cv::Mat\0image\0"
    "returnInfo\0std::string\0info\0returnRes\0"
    "res\0closeDeviceBtn\0showSourceImg\0"
    "showDstImg\0getPara\0recv_startSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WorkThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       8,    1,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   63,    2, 0x0a /* Public */,
      11,    0,   64,    2, 0x0a /* Public */,
      12,    0,   65,    2, 0x0a /* Public */,
      13,    3,   66,    2, 0x0a /* Public */,
      14,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Float,    2,    2,    2,
    QMetaType::Void,

       0        // eod
};

void WorkThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        WorkThread *_t = static_cast<WorkThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendImage((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 1: _t->returnInfo((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 2: _t->returnRes((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 3: _t->closeDeviceBtn(); break;
        case 4: _t->showSourceImg(); break;
        case 5: _t->showDstImg(); break;
        case 6: _t->getPara((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 7: _t->recv_startSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (WorkThread::*_t)(cv::Mat );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkThread::sendImage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (WorkThread::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkThread::returnInfo)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (WorkThread::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&WorkThread::returnRes)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject WorkThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_WorkThread.data,
      qt_meta_data_WorkThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *WorkThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_WorkThread.stringdata0))
        return static_cast<void*>(const_cast< WorkThread*>(this));
    return QThread::qt_metacast(_clname);
}

int WorkThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void WorkThread::sendImage(cv::Mat _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WorkThread::returnInfo(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WorkThread::returnRes(std::string _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
