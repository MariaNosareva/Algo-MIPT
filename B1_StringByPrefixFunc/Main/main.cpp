#include <iostream>
#include "../PrefixFunc/PrefixFunc.h"

int main() {
  PrefixFunc func = PrefixFunc::ZFromStream(std::cin);
  func.FromZToP();
  func.MakeString();
  std::cout << func.getString();
  return 0;
}