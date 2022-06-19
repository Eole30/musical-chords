import ctypes
import ctypes as ct
import sys

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

#testing the lib
print(_lib)
_lib.hello()
print(_lib.returns_int())
print(_lib.returns_double())
print(_lib.get_random())
# _lib.test_gsl()
