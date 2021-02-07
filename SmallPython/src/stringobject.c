#include "Python.h"

static void string_print(PyStringObject *v)
{
    printf("%s\n", v->str);
}

static PyStringObject *string_add(PyStringObject *a, PyStringObject *b)
{
    register PyStringObject *x;
    x = PyString_Create(NULL);
    if (x)
    {
        strcpy(x->str, a->str);
        strcat(x->str, b->str);
    }
    return x;
}

static long string_hash(PyStringObject *v)
{
    register unsigned char *p;
    register long x;
    register int len;
    if (v->ob_shash != -1)
        return v->ob_shash;

    p = (unsigned char *)v->str;
    x = *p << 7;
    len = v->length;
    while (--len >= 0)
        x = (1000003 * x) ^ *p++;
    x ^= v->length;
    if (x == -1)
        x = -2;
    v->ob_shash = x;
    return x;
}

PyTypeObject PyString_Type = {
    PyObject_HEAD_INIT(&PyType_Type),   //未定义标识符 "PyType_Type"C/C++(20)
    "string",
    string_print,
    string_add,
    string_hash,
};

PyStringObject *PyString_Create(const char *str)
{
    register PyStringObject *object;
    object->ob_refcnt = 1;
    object->ob_type = &PyString_Type;
    object->ob_shash = -1;
    if (str == NULL)
    {
        object->length = 0;
        memset(object->str, 0, STR_SIZE);
    }
    else
    {
        object->length = strlen(str);
        strcpy(object->str, str);
    }
    return object;
};
