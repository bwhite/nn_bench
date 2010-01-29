#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "nn.h"

double rand_double() {
  return rand() / (double) RAND_MAX;
}

void random_array(double *arr, int len) {
  int i;
  for (i = 0; i < len; i++)
    arr[i] = rand_double();
}

int main() {
  int num_train_points=10000, num_test_points=20, num_dims=1024;
  double *train_points, *test_points;
  int *indeces;
  int i;
  srand(time(NULL));
  indeces = malloc(sizeof *indeces * num_test_points);
  train_points = malloc(sizeof *train_points * num_train_points * num_dims);
  test_points = malloc(sizeof *test_points * num_test_points * num_dims);

  for (i = 0; i < num_train_points; i++)
    random_array(&train_points[i * num_dims], num_dims);

  for (i = 0; i < num_test_points; i++)
    random_array(&test_points[i * num_dims], num_dims);

  nn(test_points, num_test_points, train_points, num_train_points, num_dims, indeces);
  for (i = 0; i < num_test_points; i++)
    printf("%d ", indeces[i]);
  printf("\n");

  free(test_points);
  free(train_points);
  free(indeces);

  return 0;
}
