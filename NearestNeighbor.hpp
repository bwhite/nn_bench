#include <list>
#include <string>

class NearestNeighbor {
 public:
  NearestNeighbor(int dims, std::list<std::string> char_data);
  ~NearestNeighbor();
  int nn(char *point);
 private:
  int dims;
  int vecs;
  double *data;
};
