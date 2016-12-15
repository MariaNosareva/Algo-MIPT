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
  static PrefixFunc FromStream(std::istream &, char);

 public:
  PrefixFunc();
  static PrefixFunc PrFromStream(std::istream&);
  static PrefixFunc ZFromStream(std::istream&);
  void FromZToP();
  void MakeString();
  std::string getString();
  std::vector<int> getFunc();
};

#endif //PROJECT_PREFIXFUNC_H
