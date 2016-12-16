//
// Created by maria on 12.12.16.
//

#include <iostream>
#include <limits>
#include "SegmentTree.h"

SegmentTree::SegmentTree() {}

SegmentTree::SegmentTree(long sizeOfSegmentTree, std::vector<int>& init):
    initArray(init),
    segmentTree((int) sizeOfSegmentTree, std::make_pair(std::numeric_limits<int>::max(), std::numeric_limits<int>::max())) {}

void SegmentTree::build() {
  long doubleSize = FindPowerOfTwo((int) initArray.size());
  for (int index = 0; index < initArray.size(); index++) {
    segmentTree[doubleSize - 1 + index] = std::make_pair(initArray[index], std::numeric_limits<int>::max());
  }
  for (int index = (int) (doubleSize - 2); index >= 0; index--) {
    segmentTree[index] = segmentTree[2 * index + 1];
    ResolveFourNumbers(segmentTree[index].first, segmentTree[index].second, segmentTree[2 * index + 2].first,
                       segmentTree[2 * index + 2].second);
  }
}

void SegmentTree::Process(std::istream& in, std::ostream& out) {
  int size, numOfRequests;
  in >> size >> numOfRequests;

  long doubleSize = FindPowerOfTwo(size);
  std::vector<int> inputArray(0);
  for (int index = 0; index < size; index++) {
    int key;
    in >> key;
    inputArray.push_back(key);
  }

  SegmentTree tree(doubleSize * 2, inputArray);
  tree.build();

  for (int request = 0; request < numOfRequests; request++) {
    int left, right;
    in >> left >> right;
    int stat = tree.GetMinimum(left - 1, right - 1);
    out << stat << "\n";
  }
}

int SegmentTree::GetMinimum(int left, int right) {
  long doubleSize = FindPowerOfTwo((int) initArray.size());
  left += doubleSize - 1;
  right += doubleSize - 1;
  int leftResFirst = std::numeric_limits<int>::max();
  int leftResSecond = std::numeric_limits<int>::max();
  int rightResFirst = std::numeric_limits<int>::max();
  int rightResSecond = std::numeric_limits<int>::max();
  while (left < right) {
    if (left % 2 == 0) {
      ResolveFourNumbers(leftResFirst, leftResSecond, segmentTree[left].first, segmentTree[left].second);
    }
    left = left / 2;
    if (right % 2 == 1) {
      ResolveFourNumbers(rightResFirst, rightResSecond, segmentTree[right].first, segmentTree[right].second);
    }
    right = right / 2 - 1;
  }
  if (right == left) {
    ResolveFourNumbers(leftResFirst, leftResSecond, segmentTree[left].first, segmentTree[left].second);
  }
  ResolveFourNumbers(leftResFirst, leftResSecond, rightResFirst, rightResSecond);
  return leftResSecond;
}