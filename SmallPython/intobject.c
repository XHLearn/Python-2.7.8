#include "Python.h"

static void int_print(PyIntObject *v)
{
    printf("%d\n", v->ob_ival);
}

static PyIntObject *int_add(PyIntObject *a, PyIntObject *b)
{
    // register PyIntObject *x;
    // x = a->ob_ival + b->ob_ival;
    // return x;
    return PyInt_Create(a->ob_ival + b->ob_ival);
}

static long int_hash(PyIntObject *v)
{
    long x = v->ob_ival;
    if (x == -1)
        x = -2;
    return x;
}

PyTypeObject PyInt_Type = {
    PyObject_HEAD_INIT(&PyType_Type),
    "int",
    int_print,
    int_add,
    int_hash,
};

PyIntObject *PyInt_Create(int value)
{
    register PyIntObject *object;
    object->ob_refcnt = 1;
    object->ob_ival = value;
    object->ob_type = &PyInt_Type;
    return object;
};
