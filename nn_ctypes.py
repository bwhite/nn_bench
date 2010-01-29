import numpy as np
import ctypes

# Required Types
_double_ptr = ctypes.POINTER(ctypes.c_double)
_int_ptr = ctypes.POINTER(ctypes.c_int)
_int = ctypes.c_int
# Load library
_nn = np.ctypeslib.load_library('libnn', '.')
_nn.nn.restype = ctypes.c_int
_nn.nn.argtypes = [_double_ptr, _int, _double_ptr, _int, _int, _int_ptr]


def nn(test_points, train_points):
    indeces = np.zeros(len(test_points), dtype=np.int)
    _nn.nn(test_points.ctypes.data_as(_double_ptr), len(test_points),
           train_points.ctypes.data_as(_double_ptr), len(train_points),
           len(train_points[0]),
           indeces.ctypes.data_as(_int_ptr))
    return indeces.tolist()
