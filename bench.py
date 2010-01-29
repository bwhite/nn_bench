import numpy as np
import time

import nn_np
import nn_ctypes


def bench(name, module, test_points, train_points):
    st = time.time()
    out = module.nn(test_points, train_points)
    print('%s: %f' % (name, time.time() - st))
    return out


def make_points(num_points, num_dims):
    return np.random.random((num_points, num_dims))


def main(num_train_points=10000, num_test_points=20, num_dims=1024):
    test_points = make_points(num_test_points, num_dims)
    train_points = make_points(num_train_points, num_dims)
    methods = [('Numpy', nn_np), ('Ctypes', nn_ctypes)]
    for x, y in methods:
        print(bench(x, y, test_points, train_points))


if __name__ == '__main__':
    main()
