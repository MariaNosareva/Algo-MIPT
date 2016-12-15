//
// Created by maria on 12.12.16.
//

#include <gtest/gtest.h>
#include "../SegmentTree/SegmentTree.h"

TEST(PowerOfTwo, Test) {
  ASSERT_EQ(8, FindPowerOfTwo(5));
  ASSERT_EQ(1024, FindPowerOfTwo(897));
  ASSERT_EQ(262144, FindPowerOfTwo(168087));
  ASSERT_EQ(536870912, FindPowerOfTwo(356482167));
}

TEST(Statistics, First) {
  std::vector<int> temp = {0, 4, 1, 2};
  SegmentTree tree(8, temp);
  tree.build();
  ASSERT_EQ(4, tree.GetMinimum(1, 2));
  ASSERT_EQ(1, tree.GetMinimum(0, 3));
  ASSERT_EQ(2, tree.GetMinimum(2, 3));
  ASSERT_EQ(2, tree.GetMinimum(1, 3));
}

TEST(Statistics, Second) {
  std::vector<int> temp = {0, 4, 0, 2, 1, 1, 9};
  SegmentTree tree(36, temp);
  tree.build();
  ASSERT_EQ(4, tree.GetMinimum(1, 2));
  ASSERT_EQ(0, tree.GetMinimum(0, 3));
  ASSERT_EQ(1, tree.GetMinimum(2, 5));
  ASSERT_EQ(1, tree.GetMinimum(4, 6));
}


TEST(Statistics, Third) {
  std::vector<int> temp = {1, 4, 0, 2, 8, 5, 9};
  SegmentTree tree(36, temp);
  tree.build();
  ASSERT_EQ(1, tree.GetMinimum(0, 6));
  ASSERT_EQ(2, tree.GetMinimum(2, 5));
  ASSERT_EQ(4, tree.GetMinimum(1, 2));
}

TEST(Statistics, Fourth) {
  std::vector<int> temp = {0, 4, 5, 2, 8, 5, 9};
  SegmentTree tree(36, temp);
  tree.build();
  ASSERT_EQ(2, tree.GetMinimum(0, 6));
}

TEST(Statistics, Fifth) {
  std::vector<int> temp = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  SegmentTree tree(136, temp);
  tree.build();
  ASSERT_EQ(2, tree.GetMinimum(0, 1));
  ASSERT_EQ(2, tree.GetMinimum(0, 9));
  ASSERT_EQ(3, tree.GetMinimum(1, 6));
}

TEST(Process, First) {
  std::stringstream in;
  std::stringstream out;
  in << "9 3\n"
      "0 5 8 13 6 25 3 10 1\n"
      "1 2\n"
      "1 9\n"
      "2 7";
  SegmentTree tree;
  tree.Process(in, out);
  int second;
  out >> second;
  ASSERT_EQ(5, second);
  out >> second;
  ASSERT_EQ(1, second);
  out >> second;
  ASSERT_EQ(5, second);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}