#ifndef Py_DICTOBJECT_H
#define Py_DICTOBJECT_H

typedef struct _dictobject
{
    PyObject_HEAD;
    // map<long, PyObject *> dict;
} PyDictObject;

extern PyTypeObject PyDict_Type;

PyDictObject *PyDict_Create();

#endif
