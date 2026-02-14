// #define PY_SSIZE_T_CLEAN
// #include <Python.h> // Need to make sure pythons path is defined in tasks.json

// #include <iostream>
// #include "../operators.h"
// #include <vector>

// std::vector<double> add(std::vector<double> a, std::vector<double> b) {
//     return a + b;
// }

// // Python wrapper function
// static PyObject* py_add(PyObject* self, PyObject* args) {
//     PyObject *list_a, *list_b;

//     // Parse arguments from Python
//     if (!PyArg_ParseTuple(args, "OO", &list_a, &list_b)) { // OO tells us to look for two objects
//         return NULL;  // Python will raise TypeError automatically
//     }

//     // Check if both arguments are sequences
//     if (!PySequence_Check(list_a) || !PySequence_Check(list_b)) {
//         PyErr_SetString(PyExc_TypeError, "Both arguments must be sequences");
//         return NULL;
//     }

//     // Get lengths
//     Py_ssize_t len_a = PySequence_Length(list_a);
//     Py_ssize_t len_b = PySequence_Length(list_b);

//     // Check if lengths match
//     if (len_a != len_b) {
//         PyErr_SetString(PyExc_ValueError, "Vectors must have the same length");
//         return NULL;
//     }

//     // Convert Python lists to C++ vectors
//     std::vector<double> vec_a, vec_b;
//     vec_a.reserve(len_a);
//     vec_b.reserve(len_b);

//     for (Py_ssize_t i = 0; i < len_a; ++i) {
//         PyObject* item_a = PySequence_GetItem(list_a, i);
//         PyObject* item_b = PySequence_GetItem(list_b, i);

//         if (!item_a || !item_b) {
//             Py_XDECREF(item_a);
//             Py_XDECREF(item_b);
//             return NULL;
//         }

//         double val_a = PyFloat_AsDouble(item_a);
//         double val_b = PyFloat_AsDouble(item_b);

//         Py_DECREF(item_a);
//         Py_DECREF(item_b);

//         // Check for conversion errors
//         if (PyErr_Occurred()) {
//             return NULL;
//         }

//         vec_a.push_back(val_a);
//         vec_b.push_back(val_b);
//     }
        

//     // Perform vector addition using your overloaded operator
//     std::vector<double> result = add(vec_a, vec_b);

//     // Convert result back to Python list
//     PyObject* py_result = PyList_New(result.size());
//     if (!py_result) {
//         return NULL;
//     }

//     for (size_t i = 0; i < result.size(); ++i) {
//         PyObject* item = PyFloat_FromDouble(result[i]);
//         if (!item) {
//             Py_DECREF(py_result);
//             return NULL;
//         }
//         PyList_SetItem(py_result, i, item);  // Steals reference to item
//     }

//     return py_result;
// }

// // Method Table
// static PyMethodDef MyMethods[] = {
//     {"add", py_add, METH_VARARGS, "Add two vectors element-wise"},
//     {NULL, NULL, 0, NULL}  // Sentinel
// };

// // Module definition
// static struct PyModuleDef mymodule = {
//     PyModuleDef_HEAD_INIT,
//     "myadd",              // Module name (must match filename!)
//     "Simple addition module",
//     -1,
//     MyMethods
// };

// // Module init
// extern "C" PyMODINIT_FUNC PyInit_myadd(void) {
//     return PyModule_Create(&mymodule);
// }
