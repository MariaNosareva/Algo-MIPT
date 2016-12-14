//
// Created by maria on 05.11.16.
//

#ifndef E_FINDINGMAXFLOW_NETWORK_H
#define E_FINDINGMAXFLOW_NETWORK_H

#include <vector>
#include <fstream>


class Network {
 private:
  std::vector<std::vector<long>> residualNetwork;
  long source;
  long drain;
  explicit Network(long);

 public:
  static Network FromStream(std::istream&);
  long getNumberOfVertices();
  bool BFS(std::vector<long>&);
  long MaxFlow();
};

#endif //E_FINDINGMAXFLOW_NETWORK_H
