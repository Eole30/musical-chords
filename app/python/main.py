import ctypes
import ctypes as ct
import sys
import numpy as np

lib_path_linux = "../../lib/library.so"
lib_path_windows = "../../lib/library.dll"

#loading lib according to os used
if(sys.platform == "linux"):
    _lib = ct.cdll.LoadLibrary(lib_path_linux)
if(sys.platform == "win32"):
    _lib = ct.cdll.LoadLibrary(lib_path_windows)

# declaring types with ctypes
_lib.returns_int.argtypes = []
_lib.returns_int.restype = ctypes.c_int

_lib.returns_double.argtypes = []
_lib.returns_double.restype = ctypes.c_double

_lib.get_random.argtypes = []
_lib.get_random.restype = ctypes.c_double

X = [[1., 1.], [2., 3.], [3., 3.]]
Y = [1, -1, -1]

arr_type_X = ctypes.c_double * len(X)
arr_type_y = ctypes.c_int * len(Y)
arr_type_inputs = ctypes.c_double * len(X[0])

W = [0.15288633, -0.16578226, -0.14927692]
arr_type_W = ctypes.POINTER(ctypes.c_double)

# _lib.predict_linear_classification.argtypes = [arr_type_W, arr_type_inputs, ctypes.c_int]
# for inputs in X:
#     print(_lib.predict_linear_classification(W, inputs, len(W)))


#testing the lib
print(_lib)
_lib.hello()
print(_lib.returns_int())
print(_lib.returns_double())
print(_lib.get_random())
# _lib.test_gsl()
