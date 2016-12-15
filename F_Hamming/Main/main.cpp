#include <iostream>
#include <string>
#include "../NetworkLib/Network.h"
#include <ctime>

int main() {
  std::string pattern = "", str = "";
  std::cin >> str;
  std::cin >> pattern;

  Network net = Network::BuildNetwork(pattern, str);
  net.MinCut();

  std::cout << net.GetHammingDistance() << std::endl;
  std::cout << net.GetString() << std::endl;
  std::cout << net.GetPattern() << std::endl;
  return 0;
}