#include <gtest/gtest.h>
#include "../GraphLib/SalesGraph.h"
#include <fstream>

TEST(InputTest, Size) {
  std::stringstream in;
  in << "2\n"
      "9.0\n"
      "1.34";
  SalesGraph graph = SalesGraph::FromStream(in);
  ASSERT_EQ(2, graph.getNumberOfVertices());
}

TEST(InputTest, Matrix) {
  std::stringstream in;
  in << "2\n"
      "9.0\n"
      "1.34"; const
  SalesGraph graph = SalesGraph::FromStream(in);
  std::vector<std::vector<double>> answer = {{1, 9.0}, {1.34, 1}};
  ASSERT_EQ(answer, graph.getVerticesMatrix());
}

TEST(ArbTest, NoArbitrage) {
  std::stringstream in;
  in << "2\n"
        "10.0\n"
        "0.09";
  SalesGraph graph = SalesGraph::FromStream(in);
  ASSERT_EQ(false, graph.ArbitrageExistence());
}

TEST(ArbTest, ArbitrageExists) {
  std::stringstream in;
  in << "4\n"
        "32.1 1.50 78.66\n"
        "0.03 0.04 2.43\n"
        "0.67 21.22 51.89\n"
        "0.01 -1 0.02";
  SalesGraph graph = SalesGraph::FromStream(in);
  ASSERT_EQ(true, graph.ArbitrageExistence());
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}