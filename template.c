#include <Python.h>
#include "template_impl.h"

static PyObject *template_error;

static PyObject* hello(PyObject *self, PyObject *args)
{
    (void)self;
    const char *command = "Unnamed";
    int len = 7;
    (void)len;

    if (!PyArg_ParseTuple(args, "|s#:name", &command, &len)) {
        PyErr_SetString(template_error, "wrong func args");
        return NULL;
    }
    char buff[0x0100];
    len = get_hello_str(buff, command);
    //return Py_BuildValue("s", buff);
    return Py_BuildValue("s#", buff, len);
}

static PyObject* get_int(PyObject *self, PyObject *args) {
    (void)self;
    int number = get_rand_int();
    return Py_BuildValue("i", number);
    // if we want to return None value
    //Py_RETURN_NONE
}

static PyMethodDef template_methods[] = {
    {"hello", hello, METH_VARARGS,
     "Get hello string."},
    {"get_int", get_int, METH_VARARGS,
     "Get random int number."},
    {NULL, NULL, 0, NULL} /* Sentinel */
};

PyMODINIT_FUNC init_template_module(void)
{
    PyObject *m;
    m = Py_InitModule("_template_module", template_methods);
    if (m == NULL)
        return;
    template_error = PyErr_NewException("template_module.error", NULL, NULL);
    Py_INCREF(template_error);
    PyModule_AddObject(m, "error", template_error);
}

