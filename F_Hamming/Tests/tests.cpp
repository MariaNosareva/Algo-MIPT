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

TEST(HammingTest, First) {
  std::string pattern = "10?1", str = "1??001";
  Network net = Network::BuildNetwork(pattern, str);
  net.MinCut();

  ASSERT_EQ(4, net.GetHammingDistance());
  ASSERT_EQ("1001", net.GetPattern());
  ASSERT_EQ("110001", net.GetString());
}


TEST(HammingTest, Second) {
  std::string pattern = "?1?", str = "00?1";
  Network net = Network::BuildNetwork(pattern, str);
  net.MinCut();

  ASSERT_EQ(1, net.GetHammingDistance());
  ASSERT_EQ("011", net.GetPattern());
  ASSERT_EQ("0011", net.GetString());
}

TEST(HammingTest, Third) {
  std::string pattern = "???", str = "1?00?";
  Network net = Network::BuildNetwork(pattern, str);
  net.MinCut();

  ASSERT_EQ(1, net.GetHammingDistance());
  ASSERT_EQ("000", net.GetPattern());
  ASSERT_EQ("10000", net.GetString());
}

TEST(HammingTest, Fourth) {
  std::string pattern = "?01?0", str = "00?10?1";
  Network net = Network::BuildNetwork(pattern, str);
  net.MinCut();

  ASSERT_EQ(5, net.GetHammingDistance());
  ASSERT_EQ("00100", net.GetPattern());
  ASSERT_EQ("0001001", net.GetString());
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}