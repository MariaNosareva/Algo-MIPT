//
// Created by maria on 05.12.16.
//

#include "../SuffArray/SuffArray.h"

int main() {
  SuffArray array = SuffArray::FromStream(std::cin);
  std::vector<int> suff = array.MakeSuffArray();
  for (int i = 0; i < 7; i++) {
    std::cout << suff[i] << ' ';
  }
  return 0;
}