//
// Created by maria on 05.12.16.
//

#include "../SuffArray/SuffArray.h"

int main() {
  SuffArray array = SuffArray::FromStream(std::cin);
  std::cout << array.NumberOfDifferentSubstrings() << std::endl;
  return 0;
}