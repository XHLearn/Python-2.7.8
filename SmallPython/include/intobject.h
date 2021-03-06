#ifndef Py_INTOBJECT_H
#define Py_INTOBJECT_H

typedef struct _intobject
{
    PyObject_HEAD;
    int ob_ival;
} PyIntObject;

extern PyTypeObject PyInt_Type;

PyIntObject* PyInt_Create(int value);

#endif
