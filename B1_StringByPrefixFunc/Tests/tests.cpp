#include <gtest/gtest.h>
#include "../PrefixFunc/PrefixFunc.h"

TEST(InputTest, Function) {
  std::stringstream in;
  in << "0 1 2 3 0 1 0 0 0 1 2 0 1";
  PrefixFunc func = PrefixFunc::PrFromStream(in);
  std::vector<int> answer = {0, 1, 2, 3, 0, 1, 0, 0, 0, 1, 2, 0, 1};
  ASSERT_EQ(answer, func.getFunc());
}

TEST(AlgoTest, MakeString) {
  std::stringstream in;
  in << "0 1 0 1 2 0 0 0 1";
  PrefixFunc func = PrefixFunc::PrFromStream(in);
  func.MakeString();
  std::string answer = "aabaacbba";
  ASSERT_EQ(answer, func.getString());
}

TEST(AlgoTest, Example) {
  std::stringstream in;
  in << "0 1 2 3 0";
  PrefixFunc func = PrefixFunc::PrFromStream(in);
  func.MakeString();
  std::string answer = "aaaab";
  ASSERT_EQ(answer, func.getString());
}

TEST(AlgoTest, Zeros) {
  std::stringstream in;
  in << "0 0 0 0";
  PrefixFunc func = PrefixFunc::PrFromStream(in);
  func.MakeString();
  std::string answer = "abbb";
  ASSERT_EQ(answer, func.getString());
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}