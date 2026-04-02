#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <vector>
#include <cstddef>

#include "cubicSpline.h"

// Python wrapper function
static PyObject* py_cubicSpline(PyObject* self, PyObject* args) {
    PyObject *list_x, *list_y;
    Py_ssize_t n_arg;

    // Parse arguments: two list objects + one integer (n)
    if (!PyArg_ParseTuple(args, "OOn", &list_x, &list_y, &n_arg)) {
        return NULL;
    }

    // Validate that both arguments are sequences
    if (!PySequence_Check(list_x) || !PySequence_Check(list_y)) {
        PyErr_SetString(PyExc_TypeError, "First two arguments must be sequences");
        return NULL;
    }

    Py_ssize_t len_x = PySequence_Length(list_x);
    Py_ssize_t len_y = PySequence_Length(list_y);

    if (len_x != len_y) {
        PyErr_SetString(PyExc_ValueError, "x and y vectors must have the same length");
        return NULL;
    }

    // Convert Python lists to C++ vectors
    std::vector<double> vec_x, vec_y;
    vec_x.reserve(len_x);
    vec_y.reserve(len_y);

    for (Py_ssize_t i = 0; i < len_x; ++i) {
        PyObject* item_x = PySequence_GetItem(list_x, i);
        PyObject* item_y = PySequence_GetItem(list_y, i);

        if (!item_x || !item_y) {
            Py_XDECREF(item_x);
            Py_XDECREF(item_y);
            return NULL;
        }

        double val_x = PyFloat_AsDouble(item_x);
        double val_y = PyFloat_AsDouble(item_y);

        Py_DECREF(item_x);
        Py_DECREF(item_y);

        if (PyErr_Occurred()) {
            return NULL;
        }

        vec_x.push_back(val_x);
        vec_y.push_back(val_y);
    }

    std::size_t n = static_cast<std::size_t>(n_arg);

    // Call your cubicSpline function
    // Returns std::vector<std::vector<double>>
    std::vector<std::vector<double>> result = cubicSpline(vec_x, vec_y, n);

    // --- Convert std::vector<std::vector<double>> back to a Python list of lists ---

    // Outer list: one entry per inner vector
    PyObject* py_outer = PyList_New(result.size());
    if (!py_outer) {
        return NULL;
    }

    for (size_t i = 0; i < result.size(); ++i) {
        const std::vector<double>& inner = result[i];

        // Inner list for this sub-vector
        PyObject* py_inner = PyList_New(inner.size());
        if (!py_inner) {
            Py_DECREF(py_outer);
            return NULL;
        }

        for (size_t j = 0; j < inner.size(); ++j) {
            PyObject* item = PyFloat_FromDouble(inner[j]);
            if (!item) {
                Py_DECREF(py_inner);
                Py_DECREF(py_outer);
                return NULL;
            }
            PyList_SetItem(py_inner, j, item);  // Steals reference to item
        }

        PyList_SetItem(py_outer, i, py_inner);  // Steals reference to py_inner
    }

    return py_outer;
}

// Method table
static PyMethodDef SplineMethods[] = {
    {"cubicSpline", py_cubicSpline, METH_VARARGS,
     "Perform cubic spline interpolation.\n\n"
     "Args:\n"
     "    x (list[float]): Knot positions\n"
     "    y (list[float]): Data values\n"
     "    n (int):         Number of points\n\n"
     "Returns:\n"
     "    list[list[float]]: Interpolated vectors"},
    {NULL, NULL, 0, NULL}  // Sentinel
};

// Module definition
static struct PyModuleDef splinemodule = {
    PyModuleDef_HEAD_INIT,
    "cubicspline",                     // Module name (must match filename!)
    "Cubic spline interpolation module",
    -1,
    SplineMethods
};

// Module init — name must be PyInit_<module_name>
extern "C" PyMODINIT_FUNC PyInit_cubicspline(void) {
    return PyModule_Create(&splinemodule);
}