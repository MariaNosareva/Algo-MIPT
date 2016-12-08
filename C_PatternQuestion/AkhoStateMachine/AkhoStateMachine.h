//
// Created by maria on 07.12.16.
//

#ifndef PROJECT_AKHOSTATEMACHINE_H
#define PROJECT_AKHOSTATEMACHINE_H

#include <vector>
#include <string>

struct Vertex {
  Vertex out[52]; //[a-zA-Z]
  Vertex suffLink;
  Vertex parent;
  char symbolIn;
  bool isTerminal;
};

class AkhoStateMachine {
 private:
  std::string pattern;
  std::vector<Vertex> nodes;
 public:
  AkhoStateMachine();
  std::vector<int> getEndIndicesOfNonMaskSubpatterns();
  void BuildBor();
};

#endif //PROJECT_AKHOSTATEMACHINE_H
