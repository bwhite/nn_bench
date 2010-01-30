#include "nn.h"

void nn(double *test_points, int num_test_points, double *train_points, int num_train_points, int num_dims, int *indeces) {
  int i, j, k;
  for (i = 0; i < num_test_points; i++) {
    double min_dist = 100000000000000.0; /* ~Inf */
    int min_dist_ind = -1;
    for (j = 0; j < num_train_points; j++) {
      double cur_dist = 0.0;
      for (k = 0; k < num_dims; k++) {
	double diff = test_points[i * num_dims + k] - train_points[j * num_dims + k];
	cur_dist += diff * diff;
      }
      if (cur_dist < min_dist) {
	min_dist = cur_dist;
	min_dist_ind = j;
      }
    }
    indeces[i] = min_dist_ind;
  }
}
