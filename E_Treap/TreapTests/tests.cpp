//
// Created by maria on 10.12.16.
//

#include <gtest/gtest.h>
#include "../TreapLib/BST.h"
#include "../TreapLib/Treap.h"

TEST(BST, First) {
  std::stringstream in;
  in << "5\n"
        "3\n"
        "1\n"
        "7\n"
        "4\n"
        "2";
  BST tree = BST::FromStream(in);
  ASSERT_EQ(tree.GetRootValue(), 3);
  ASSERT_EQ(tree.GetHeight(), 3);
  ASSERT_EQ(tree.GetWidth(), 2);
}

TEST(BST, Second) {
  std::stringstream in;
  in << "8\n"
      "1\n"
      "9\n"
      "5\n"
      "13\n"
      "66\n"
      "12\n"
      "7\n"
      "3";
  BST tree = BST::FromStream(in);
  ASSERT_EQ(tree.GetRootValue(), 1);
  ASSERT_EQ(tree.GetHeight(), 4);
  ASSERT_EQ(tree.GetWidth(), 4);
}


TEST(Treap, First) {
  std::stringstream in;
  in << "7\n"
      "1 2\n"
      "3 5\n"
      "10 3\n"
      "5 12\n"
      "6 8\n"
      "2 9\n"
      "4 6";
  Treap treap = Treap::BuildTreap(in);
  ASSERT_EQ(treap.GetRootKey(), 5);
  ASSERT_EQ(treap.GetRootPriority(), 12);
  ASSERT_EQ(treap.GetHeight(), 4);
  ASSERT_EQ(treap.GetWidth(), 3);
}

TEST(Treap, Second) {
  std::stringstream in;
  in << "13\n"
      "2 11\n"
      "4 1\n"
      "0 6\n"
      "5 14\n"
      "3 8\n"
      "19 10\n"
      "7 9\n"
      "15 7\n"
      "13 12\n"
      "17 0\n"
      "20 5\n"
      "14 2\n"
      "18 3";
  Treap treap = Treap::BuildTreap(in);
  ASSERT_EQ(treap.GetRootKey(), 5);
  ASSERT_EQ(treap.GetRootPriority(), 14);
  ASSERT_EQ(treap.GetHeight(), 6);
  ASSERT_EQ(treap.GetWidth(), 4);
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}