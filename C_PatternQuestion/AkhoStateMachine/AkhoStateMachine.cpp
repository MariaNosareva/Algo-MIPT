//
// Created by maria on 07.12.16.
//

#include "AkhoStateMachine.h"

AkhoStateMachine::AkhoStateMachine(): nodes(1) {
  nodes[0].parent = nodes[0];
}

std::vector<int> AkhoStateMachine::getEndIndicesOfNonMaskSubpatterns() {
  std::vector<int> ends;
  for (int pos = 0; pos < pattern.length() - 1; pos++) {
    if (pattern[pos + 1] == '?' && pattern[pos] >= 'a' && pattern[pos] <= 'Z')
  }
}