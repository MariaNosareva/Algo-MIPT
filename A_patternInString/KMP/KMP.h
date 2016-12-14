//
// Created by maria on 21.11.16.
//

#ifndef PROJECT_KMP_H
#define PROJECT_KMP_H

#include <vector>
#include <string>
#include <iostream>

class KMP {
 private:
  std::string pattern;
  std::string str;
  std::vector<int> patternPrefixFunc;
 public:
  KMP();
  static KMP FromStream(std::istream&);
  void calculatePrefixFunc();
  std::vector<int> getIndices();
  std::string getPattern();
  std::string getStr();
  std::vector<int> getPatternPrefixFunc();
};

#endif //PROJECT_KMP_H
