//
// Created by maria on 20.10.16.
//

#ifndef KRUSKAL_GRAPH_H
#define KRUSKAL_GRAPH_H

#include <vector>
#include <istream>

class Graph {
 private:
  unsigned long number_of_vertices;
  unsigned long number_of_edges;
  //edge, weigh
  std::vector<std::pair<std::pair<int, int>, int>> edges_matrix;
 public:
  explicit Graph(unsigned long, unsigned long);
  static Graph FromStream(std::istream&);
  int MST();
};

#endif //KRUSKAL_GRAPH_H
