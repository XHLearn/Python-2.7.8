#ifndef Py_OBJECT_H
#define Py_OBJECT_H

#define PyObject_HEAD \
    int ob_refcnt;    \
    struct _typeobject *ob_type;

#define PyObject_HEAD_INIT(type) 1, type

typedef struct _object
{
    PyObject_HEAD
} PyObject;

typedef int (*printfunc)(PyObject *);
typedef PyObject *(*addfunc)(PyObject *, PyObject *);
typedef long (*hashfunc)(PyObject *);

typedef struct _typeobject
{
    PyObject_HEAD const char *tp_name; /* For printing, in format "<module>.<name>" */
    // 三个简单的函数，print、add、hash
    printfunc tp_print;
    addfunc tp_add;
    hashfunc tp_hash;
} PyTypeObject;

#endif
