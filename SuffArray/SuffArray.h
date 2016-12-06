//
// Created by maria on 05.12.16.
//

#ifndef PROJECT_SUFFARRAY_H
#define PROJECT_SUFFARRAY_H

#include <string>
#include <vector>
#include <iostream>

class SuffArray {
 private:
  std::string text;
  int textLen;
  std::vector<int> suffArray;
  std::vector<int> LCP;
 public:
  SuffArray();
  static SuffArray FromStream(std::istream&);
  std::vector<int> MakeSuffArray();
};

#endif //PROJECT_SUFFARRAY_H
