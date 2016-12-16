#include <iostream>
#include <vector>
#include "../KMP/KMP.h"

int main() {
  KMP kmp = KMP::FromStream(std::cin);
  std::vector<int> indices = kmp.getIndices();
  for (int i = 0; i < indices.size(); i++) {
    std::cout << indices[i] << " ";
  }

  return 0;
}
