#include <gtest/gtest.h>
#include "../NetworkLib/Network.h"
#include <fstream>

TEST(HammingTest, Example) {
  std::string pattern = "1?", str = "00?";
  Network net = Network::BuildNetwork(pattern, str);
  net.MinCut();

  ASSERT_EQ(2, net.GetHammingDistance());
  ASSERT_EQ("10", net.GetPattern());
  ASSERT_EQ("000", net.GetString());
}

//TODO more tests

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}