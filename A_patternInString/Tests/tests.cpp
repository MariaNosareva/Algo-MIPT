#include <gtest/gtest.h>
#include "../KMP/KMP.h"
#include <vector>

TEST(InputTest, Pattern) {
  std::stringstream in;
  in << "yqtwreerwtqy\n"
      "qwertyqwerty";
  KMP kmp = KMP::FromStream(in);
  ASSERT_EQ("yqtwreerwtqy", kmp.getPattern());
}

TEST(InputTest, Str) {
  std::stringstream in;
  in << "yqtwre\n"
      "qwerty";
  KMP kmp = KMP::FromStream(in);
  ASSERT_EQ("qwerty", kmp.getStr());
}

TEST(CalculatingTest, PrefixF) {
  std::stringstream in;
  in << "abracadabra\n"
      "abcrcbarcbdrccdcra";
  KMP kmp = KMP::FromStream(in);
  std::vector<int> answer = {0, 0, 0, 1, 0, 1, 0, 1, 2, 3, 4};
  ASSERT_EQ(answer, kmp.getPatternPrefixFunc());
}

TEST(KMPTest, Example) {
  std::vector<int> answer = {0, 1, 2};
  std::stringstream in;
  in << "a\n"
        "aaa";
  KMP kmp = KMP::FromStream(in);
  ASSERT_EQ(answer, kmp.getIndices());
}

TEST(KMPTest, ThreeIncludes) {
  std::vector<int> answer = {0, 5, 7};
  std::stringstream in;
  in << "aba\n"
      "ababbababa";
  KMP kmp = KMP::FromStream(in);
  ASSERT_EQ(answer, kmp.getIndices());
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}