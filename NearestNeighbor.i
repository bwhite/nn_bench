%module NearestNeighbor
%{
#include "NearestNeighbor.hpp"
%}
%include std_list.i
%include stl.i
%include std_string.i
%template(StringList) std::list<std::string>;
%include "NearestNeighbor.hpp"