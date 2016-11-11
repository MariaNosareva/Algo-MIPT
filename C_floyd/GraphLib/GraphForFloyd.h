//
// Created by Maria on 9/25/2016.
//

#ifndef FLOYD_GRAPH_FOR_FLOYD_H
#define FLOYD_GRAPH_FOR_FLOYD_H

#include <vector>
#include <fstream>

class GraphForFloyd{

 private:
  unsigned long number_of_vertices;
  std::vector<std::vector<int>> vertices_matrix;
  std::vector<std::vector<int>> shortest_paths;

 public:
  static GraphForFloyd FromStream(std::istream&);
  GraphForFloyd(unsigned long);
  void Floyd();
  void PrintShortestPathsMatrix(std::ofstream &);
};

#endif //FLOYD_GRAPH_FOR_FLOYD_H
