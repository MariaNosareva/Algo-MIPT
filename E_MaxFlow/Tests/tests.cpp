#include <gtest/gtest.h>
#include "../NetworkLib/Network.h"

TEST(MaxFlowTest, Simple) {
  std::stringstream in;
  in << "2\n"
        "1 2 1\n"
        "1 2 3";
  Network network = Network::FromStream(in);

  ASSERT_EQ(network.MaxFlow(), 3);
}

TEST(MaxFlowTest, Example) {
  std::stringstream in;
  in << "4\n"
      "1 4 5\n"
      "1 2 20\n"
      "1 3 10\n"
      "2 3 5\n"
      "2 4 10\n"
      "3 4 20";
  Network network = Network::FromStream(in);

  ASSERT_EQ(network.MaxFlow(), 25);
}

TEST(MaxFlowTest, First) {
  std::stringstream in;
  in << "6\n"
      "1 6 6\n"
      "1 2 2\n"
      "1 3 6\n"
      "2 4 7\n"
      "4 5 3\n"
      "3 5 1\n"
      "5 6 4";
  Network network = Network::FromStream(in);

  ASSERT_EQ(network.MaxFlow(), 3);
}

TEST(MaxFlowTest, Circle) {
  std::stringstream in;
  in << "8\n"
      "1 8 9\n"
      "1 2 2\n"
      "1 3 5\n"
      "2 4 7\n"
      "3 4 1\n"
      "4 5 4\n"
      "5 6 3\n"
      "6 7 1\n"
      "7 4 6\n"
      "6 8 10";
  Network network = Network::FromStream(in);

  ASSERT_EQ(network.MaxFlow(), 3);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}