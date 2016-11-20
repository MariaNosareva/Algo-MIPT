//
// Created by maria on 05.11.16.
//

#ifndef E_FINDINGMAXFLOW_NETWORK_H
#define E_FINDINGMAXFLOW_NETWORK_H

#include <vector>
#include <fstream>

struct Edge {
  long from;
  long to;
  long capacity;
  long flow;
};

class Network {
 private:
  std::vector<std::vector<long>> capacityMatrix;
  std::vector<std::vector<long>> residualNetwork;
  long source;
  long drain;

 public:
  explicit Network(long);
  static Network FromStream(std::istream&);
  long getNumberOfVertices();
  bool BFS(std::vector<long>&);
  long MaxFlow();
};

#endif //E_FINDINGMAXFLOW_NETWORK_H
