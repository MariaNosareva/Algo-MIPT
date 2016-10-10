//Необходимо написать торгового работника для поиска арбитража.

#include <iostream>
#include <vector>
#include "SalesGraph.h"

int main() {
  SalesGraph graph = SalesGraph::FromStream(std::cin);

  bool arbitrage = graph.ArbitrageExistence();
  if (arbitrage)
    std::cout << "YES";
  else
    std::cout << "NO";

  return 0;
}
