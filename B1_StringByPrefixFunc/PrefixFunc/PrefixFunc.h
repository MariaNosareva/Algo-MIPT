//
// Created by maria on 22.11.16.
//

#ifndef PROJECT_PREFIXFUNC_H
#define PROJECT_PREFIXFUNC_H

#include <vector>
#include <iostream>
class PrefixFunc {
 private:
  std::vector<int> prFunction;
  std::vector<int> zFunction;
  std::string String;
 public:
  PrefixFunc();
  void FromZToP();
  static PrefixFunc FromStream(std::istream &, char);
  void MakeString();
  std::string getString();
  std::vector<int> getFunc();
};

#endif //PROJECT_PREFIXFUNC_H
