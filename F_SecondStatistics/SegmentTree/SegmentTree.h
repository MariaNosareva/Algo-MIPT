//
// Created by maria on 12.12.16.
//

#ifndef PROJECT_SEGMENTTREE_H
#define PROJECT_SEGMENTTREE_H

#include <vector>
#include <istream>



class SegmentTree {
 private:
  std::vector<int> initArray;
  std::vector<std::pair<int, int>> segmentTree; //хранит два минимума на отрезке
 public:
  void build();
  SegmentTree();
  SegmentTree(long, std::vector<int>&);
  static void Process(std::istream&, std::ostream&);
  int GetMinimum(int, int);
};

inline long FindPowerOfTwo(int value) {
  int answer = 1;
  while (answer < value) {
    answer *= 2;
  }
  return answer;
}

inline void ResolveFourNumbers(int& firstFirst, int& firstSecond, int& secondFirst, int& secondSecond) {
  if (firstFirst > secondFirst) {
    firstSecond = firstFirst;
    firstFirst = secondFirst;
    if (firstSecond > secondSecond) {
      firstSecond = secondSecond;
    }
  } else if (firstSecond > secondFirst) {
    firstSecond = secondFirst;
  }
}

#endif //PROJECT_SEGMENTTREE_H
