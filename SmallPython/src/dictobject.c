#include "Python.h"

static void dict_print(PyDictObject *v)
{
}

PyTypeObject PyDict_Type = {
    PyObject_HEAD_INIT(&PyType_Type),
    "int",
    dict_print,
    0,
    0,
};

PyDictObject *PyDict_Create()
{
    register PyDictObject *x;
    x->ob_refcnt = 1;
    x->ob_type = &PyDict_Type;
    return x;
}

PyObject *PyDict_GetItem(PyDictObject *mp, PyObject *key)
{
    long hash = (key->ob_type)->tp_hash(key);
    // map<long, PyObject*>::iterator it;
}