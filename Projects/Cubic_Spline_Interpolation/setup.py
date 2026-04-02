from setuptools import setup, Extension

cubicspline_module = Extension(
    name="cubicspline",          # Must match PyInit_cubicspline in your wrapper
    sources=[
        "Wrapper.cpp",    # Your Python wrapper
        "cubicSpline.cpp",           # The actual spline implementation
        "operators.cpp",
        "tridiag.cpp",
        "vector_features.cpp",
        # Add any other .cpp files that cubicSpline.cpp depends on, e.g.:
        # "someHelper.cpp",
    ],
    include_dirs=[
        ".",                     # Look for headers in the current directory
        # Add other paths here if your headers live elsewhere, e.g.:
        # "include/",
        # "C:/path/to/some/library/include",
    ],
    language="c++",
    extra_compile_args=[
        "/std:c++17",            # Use C++17 — change to "-std=c++17" on Mac/Linux
        # "/O2",                 # Optional: optimisation flag (Windows)
        # "-O2",                 # Optional: optimisation flag (Mac/Linux)
    ],
)

setup(
    name="cubicspline",
    version="1.0",
    description="Cubic spline interpolation exposed to Python",
    ext_modules=[cubicspline_module],
)