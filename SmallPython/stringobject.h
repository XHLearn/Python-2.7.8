#ifndef Py_STRINGOBJECT_H
#define Py_STRINGOBJECT_H

#define STR_SIZE 50

typedef struct _stringobject
{
    PyObject_HEAD int length;
    long ob_shash;
    char str[STR_SIZE];
} PyStringObject;

#endif
