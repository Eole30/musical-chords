import ctypes as ct
import sys

lib_path_linux = "../../lib/library.so"
lib_path_windows = "../../lib/library.dll"

if(sys.platform == "linux"):
    _lib = ct.cdll.LoadLibrary(lib_path_linux)
if(sys.platform == "win32"):
    _lib = ct.cdll.LoadLibrary(lib_path_windows)

##testing if the lib works
print(_lib)
_lib.hello()
print(_lib.returns_int())
print(_lib.returns_double)
print(_lib.get_random())
_lib.test_gsl()
