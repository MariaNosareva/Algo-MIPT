#include <gtest/gtest.h>
#include <fstream>
#include "../source/Graph.h"

TEST(TestingKruskal, SimpleGraph) {
  std::stringstream in;
  in << "2 1 1 2 1";
  Graph graph = Graph::FromStream(in);
  ASSERT_EQ(1, graph.MST());
}

TEST(TestingKruskal, EqualEdgesTest) {
  std::stringstream in;
  in << "5 5\n"
      "1 2 1\n"
      "2 4 1\n"
      "1 3 1\n"
      "3 4 1\n"
      "4 5 1";
  Graph graph = Graph::FromStream(in);
  ASSERT_EQ(4, graph.MST());
}

TEST(TestingKruskal, DifficultGraph) {
  std::stringstream in;
  in << "6 8\n"
      "1 2 1\n"
      "2 3 2\n"
      "1 4 2\n"
      "3 4 5\n"
      "3 5 -3\n"
      "4 5 8\n"
      "4 6 3\n"
      "5 6 9";
  Graph graph = Graph::FromStream(in);
  ASSERT_EQ(5, graph.MST());
}

TEST(TestingKruskal, MoreCycles) {
  std::stringstream in;
  in << "6 10\n"
      "1 2 5\n"
      "2 4 9\n"
      "1 6 8\n"
      "1 3 1\n"
      "1 5 3\n"
      "3 5 7\n"
      "5 6 20\n"
      "4 6 11\n"
      "2 6 6\n"
      "3 4 8";
  Graph graph = Graph::FromStream(in);
  ASSERT_EQ(23, graph.MST());
}

TEST(TestingKruskal, FullGraph) {
  std::stringstream in;
  in << "5 10\n"
      "1 2 1000\n"
      "1 3 6000\n"
      "1 4 4000\n"
      "1 5 3000\n"
      "2 3 3000\n"
      "2 4 7000\n"
      "2 5 1000\n"
      "3 4 2000\n"
      "3 5 5000\n"
      "4 5 2000";
  Graph graph = Graph::FromStream(in);
  ASSERT_EQ(6000, graph.MST());
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
