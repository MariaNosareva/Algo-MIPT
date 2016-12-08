//
// Created by maria on 07.12.16.
//

#ifndef PROJECT_AKHOSTATEMACHINE_H
#define PROJECT_AKHOSTATEMACHINE_H

#include <vector>
#include <string>

struct Vertex {
  int out[52]; //[a-zA-Z]
  int goes[52];
  int suffLink;
  int parent;
  char symbolIn;
  bool isTerminal;
  std::vector<int> indicesOfSubpattern;
};

class AkhoStateMachine {
 private:
  std::string pattern;
  std::string text;
  std::vector<Vertex> nodes;
 public:
  AkhoStateMachine();
  static AkhoStateMachine FromStream(std::istream&);
  std::vector<int> getEndIndicesOfNonMaskSubpatterns();
  std::vector<int> getStartIndicesOfNonMaskSubpatterns();
  void addSubPattern(int, int, int);
  void BuildBor();
  int getSuffLink(int);
  int getLink(int, char);
  std::vector<int> process();
};

#endif //PROJECT_AKHOSTATEMACHINE_H
