/****************************************************************************
** Meta object code from reading C++ file 'BundlerImportDlg.h'
**
** Created: Sun Mar 10 15:48:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../qCC/fileIO/BundlerImportDlg.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BundlerImportDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BundlerImportDlg[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x09,
      44,   17,   17,   17, 0x09,
      73,   17,   17,   17, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_BundlerImportDlg[] = {
    "BundlerImportDlg\0\0browseImageListFilename()\0"
    "browseAltKeypointsFilename()\0"
    "acceptAndSaveSettings()\0"
};

void BundlerImportDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BundlerImportDlg *_t = static_cast<BundlerImportDlg *>(_o);
        switch (_id) {
        case 0: _t->browseImageListFilename(); break;
        case 1: _t->browseAltKeypointsFilename(); break;
        case 2: _t->acceptAndSaveSettings(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData BundlerImportDlg::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BundlerImportDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BundlerImportDlg,
      qt_meta_data_BundlerImportDlg, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BundlerImportDlg::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BundlerImportDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BundlerImportDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BundlerImportDlg))
        return static_cast<void*>(const_cast< BundlerImportDlg*>(this));
    if (!strcmp(_clname, "Ui::BundlerImportDlg"))
        return static_cast< Ui::BundlerImportDlg*>(const_cast< BundlerImportDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int BundlerImportDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
