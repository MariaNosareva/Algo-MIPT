#include <iostream>
#include "../PrefixFunc/PrefixFunc.h"

int main() {
  PrefixFunc func = PrefixFunc::FromStream(std::cin, 'z');
  func.FromZToP();
  func.MakeString();
  std::cout << func.getString();
  return 0;
}