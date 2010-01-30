#include <cstring>
#include "NearestNeighbor.hpp"
NearestNeighbor::NearestNeighbor(int dims, std::list<std::string> char_data) {
  this->dims = dims;
  this->vecs = (int)char_data.size();

  this->data = new double[this->vecs * dims];
  double * data_iter = this->data;
  for (std::list<std::string>::iterator i = char_data.begin(); i != char_data.end(); ++i, data_iter += dims)
    memcpy(data_iter, i->c_str(), dims * sizeof(double));
}

NearestNeighbor::~NearestNeighbor() {
  delete [] this->data;
}

int NearestNeighbor::nn(char *pointc) {
  double *point = (double *)pointc;
  int min_vec = 0;
  double min_dist = 1000000.0; // TODO Make this max double
  double * data_iter = data;

  for (int i = 0; i < vecs; i++, data_iter += dims) {
    double cur_dist = 0;

    for (int j = 0; j < dims; j++) {
      double diff = data_iter[j] - point[j];
      cur_dist += diff * diff;
    }

    if (cur_dist < min_dist) {
      min_vec = i;
      min_dist = cur_dist;
    }
  }

  return min_vec;
}
