#include <gtest/gtest.h>
#include <fstream>
#include "../GraphLib/GraphForFloyd.h"


TEST(GraphTest, FirstInputTest) {
  std::stringstream in;
  in << "5\n"
      "0 1 2 3 7\n"
      "4 9 6 7 12\n"
      "8 9 10 11 16\n"
      "12 1 14 5 8\n"
      "5 1 9 5 2";
  GraphForFloyd graph = GraphForFloyd::FromStream(in);
  EXPECT_EQ(5, graph.GetSize());
}

TEST(GraphTest, SecondInputTest) {
  std::stringstream in;
  in << "4\n"
      "0 1 2 3\n"
      "4 5 6 7\n"
      "8 9 10 11\n"
      "12 13 14 15";
  GraphForFloyd graph = GraphForFloyd::FromStream(in);
  std::vector<std::vector<int>> testVector(4);
  for (int fPos = 0; fPos < 4; fPos++) {
    for (int sPos = 0; sPos < 4; sPos++) {
      testVector[fPos].push_back(fPos * 4 + sPos);
    }
  }
  ASSERT_EQ(testVector, graph.GetMatrix());
}

TEST(FloydMatrixTest, ExampleTest) {
  std::stringstream in;
  in << "4\n"
      "0 5 9 100\n"
      "100 0 2 8\n"
      "100 100 0 7\n"
      "4 100 100 0\n"
      "4\n"
      "0 5 7 13\n"
      "12 0 2 8\n"
      "11 16 0 7\n"
      "4 9 11 0";
  GraphForFloyd graph = GraphForFloyd::FromStream(in);
  graph.Floyd();
  GraphForFloyd answer = GraphForFloyd::FromStream(in);
  ASSERT_EQ(answer.GetMatrix(), graph.GetFloydMatrix());
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}