//
// Created by maria on 08.12.16.
//

#include <iostream>
#include "../AkhoStateMachine/AkhoStateMachine.h"

int main() {
  AkhoStateMachine fsm = AkhoStateMachine::FromStream(std::cin);
  std::vector<int> temp = fsm.process();
  for (int i = 0; i < temp.size(); i++) {
    std::cout << temp[i] << " ";
  }
  return 0;
}