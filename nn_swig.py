import time

import numpy as np

from NearestNeighbor import NearestNeighbor

def nn(test_points, train_points):
    dims = len(test_points[0])
    train_points = [x.tostring() for x in train_points]
    test_points = [x.tostring() for x in test_points]
    nn = NearestNeighbor(dims, train_points)
    return [nn.nn(x) for x in test_points]
