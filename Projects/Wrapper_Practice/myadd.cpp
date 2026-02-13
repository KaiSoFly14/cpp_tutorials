#define PY_SSIZE_T_CLEAN
#include <Python.h>

// -------------------------------
// 1️⃣ Your actual C++ function
// -------------------------------
int add(int a, int b) {
    return a + b;
}

// ------------------------------------
// 2️⃣ Python wrapper function
// ------------------------------------
static PyObject* py_add(PyObject* self, PyObject* args) {
    int a, b;

    // Parse arguments from Python
    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;  // Python will raise TypeError automatically
    }

    int result = add(a, b);

    // Convert C++ int back to Python int
    return PyLong_FromLong(result);
}

// ------------------------------------
// 3️⃣ Method table
// ------------------------------------
static PyMethodDef MyMethods[] = {
    {"add", py_add, METH_VARARGS, "Add two integers"},
    {NULL, NULL, 0, NULL}  // Sentinel
};

// ------------------------------------
// 4️⃣ Module definition
// ------------------------------------
static struct PyModuleDef mymodule = {
    PyModuleDef_HEAD_INIT,
    "myadd",              // Module name (must match filename!)
    "Simple addition module",
    -1,
    MyMethods
};

// ------------------------------------
// 5️⃣ Module initialization
// ------------------------------------
extern "C" PyMODINIT_FUNC PyInit_myadd(void) {
    return PyModule_Create(&mymodule);
}
