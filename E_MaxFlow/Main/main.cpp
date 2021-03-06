#include <iostream>
#include "../NetworkLib/Network.h"
int main() {
  Network network = Network::FromStream(std::cin);

  while (network.getNumberOfVertices() != 1) {
    std::cout << network.MaxFlow() << std::endl;
    network = Network::FromStream(std::cin);
  }

  return 0;
}