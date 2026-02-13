// #define PY_SSIZE_T_CLEAN
// #include <Python.h> // Need to make sure pythons path is defined in tasks.json


// // Python wrapper function
// static PyObject* py_add(PyObject* self, PyObject* args) {
//     int a, b;

//     // Parse arguments from Python
//     if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
//         return NULL;  // Python will raise TypeError automatically
//     }

//     int result = add(a, b);

//     // Convert C++ int back to Python int
//     return PyLong_FromLong(result);
// }

// // Method Table
// static PyMethodDef MyMethods[] = {
//     {"add", py_add, METH_VARARGS, "Add two integers"},
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
