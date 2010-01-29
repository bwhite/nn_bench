import numpy as np


def nn(test_points, train_points):
    norm = lambda x: np.dot(x, x)
    return [np.argmin([norm(x - y) for y in train_points])
            for x in test_points]
