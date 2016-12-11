//
// Created by maria on 10.12.16.
//

#include <iostream>
#include "../TreapLib/Treap.h"
#include "../TreapLib/BST.h"
#include <sstream>

int main() {
  std::stringstream inTreap, inBST;
  int number;
  std::string inputTreap = "", inputBST = "";
  std::cin >> number;
  inputTreap += std::to_string(number) + "\n";
  inputBST += std::to_string(number) + "\n";
  for (int i = 0; i < number; ++i) {
    std::string tempKey, tempPriority;
    std::cin >> tempKey >> tempPriority;
    inputTreap += tempKey + " " + tempPriority + "\n";
    inputBST += tempKey + "\n";
  }
  inTreap << inputTreap;
  inBST << inputBST;

  Treap treap = Treap::BuildTreap(inTreap);
  BST tree = BST::FromStream(inBST);
  std::cout << treap.GetWidth() - tree.GetWidth() << std::endl;
  return 0;
}
