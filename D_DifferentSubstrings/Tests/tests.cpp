//
// Created by maria on 06.12.16.
//

#include <gtest/gtest.h>
#include "../SuffArray/SuffArray.h"

TEST(SuffixArrayTest, First) {
  std::stringstream in;
  in << "cbacba";
  SuffArray arr = SuffArray::FromStream(in);
  std::vector<int> answer = {5, 2, 4, 1, 3, 0};
  ASSERT_EQ(answer, arr.MakeSuffArray());
}

TEST(SuffixArrayTest, Abracadabra) {
  std::stringstream in;
  in << "abracadabra";
  SuffArray arr = SuffArray::FromStream(in);
  std::vector<int> answer = {10, 7, 0, 3, 5, 8, 1, 4, 6, 9, 2};
  ASSERT_EQ(answer, arr.MakeSuffArray());
}

TEST(SuffixArrayTest, AllA) {
  std::stringstream in;
  in << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  SuffArray arr = SuffArray::FromStream(in);
  std::vector<int> answer;
  for (int i = 31; i >= 0; i--) {
    answer.push_back(i);
  }
  ASSERT_EQ(answer, arr.MakeSuffArray());
}

TEST(LCPArrayTest, First) {
  std::stringstream in;
  in << "cbacba";
  SuffArray arr = SuffArray::FromStream(in);
  std::vector<int> answer = {1, 0, 2, 0, 3, 0};
  ASSERT_EQ(answer, arr.MakeLCP());
}

TEST(LCPArrayTest, Abracadabra) {
  std::stringstream in;
  in << "abracadabra";
  SuffArray arr = SuffArray::FromStream(in);
  std::vector<int> answer = {1, 4, 1, 1, 0, 3, 0, 0, 0, 2, 0};
  ASSERT_EQ(answer, arr.MakeLCP());
}

TEST(DiffersTest, Example) {
  std::stringstream in;
  in << "abab";
  SuffArray arr = SuffArray::FromStream(in);
  ASSERT_EQ(7, arr.NumberOfDifferentSubstrings());
}

TEST(DiffersTest, First) {
  std::stringstream in;
  in << "cbacba";
  SuffArray arr = SuffArray::FromStream(in);
  ASSERT_EQ(15, arr.NumberOfDifferentSubstrings());
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}