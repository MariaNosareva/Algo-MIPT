//
// Created by maria on 07.12.16.
//

#include "AkhoStateMachine.h"
#include <cstdlib>
#include <cctype>

AkhoStateMachine::AkhoStateMachine(): nodes(1), pattern(""), text("") {
  nodes[0].parent = 0;
  for (int ind = 0; ind < 52; ind++) {
    nodes[0].out[ind] = -1;
    nodes[0].goes[ind] = -1;
  }
  nodes[0].isTerminal = false;
  nodes[0].symbolIn = -1;
  nodes[0].suffLink = 0;
}

AkhoStateMachine AkhoStateMachine::FromStream(std::istream & in) {
  AkhoStateMachine fsm;
  in >> fsm.pattern;
  in >> fsm.text;
  return fsm;
}

std::vector<int> AkhoStateMachine::getEndIndicesOfNonMaskSubpatterns() {
  std::vector<int> ends;
  for (int pos = 0; pos < pattern.length() - 1; pos++) {
    if (pattern[pos + 1] == '?' && isalpha(pattern[pos])) {
      ends.push_back(pos);
    }
  }
  if (isalpha(pattern[pattern.length() - 1])) {
    ends.push_back((int)pattern.length() - 1);
  }
  return ends;
}

std::vector<int> AkhoStateMachine::getStartIndicesOfNonMaskSubpatterns() {
  std::vector<int> starts;
  if (isalpha(pattern[0])) {
    starts.push_back(0);
  }
  for (int pos = 1; pos < pattern.length(); pos++) {
    if (pattern[pos - 1] == '?' && isalpha(pattern[pos])) {
      starts.push_back(pos);
    }
  }
  return starts;
}

void AkhoStateMachine::addSubPattern(int start, int end, int index) {
  int vert = 0;
  for (int pos = start; pos <= end; pos++) {
    char character = pattern[pos] - 'a';
    if (nodes[vert].out[character] == -1) {
      Vertex temp;
      temp.suffLink = -1;
      temp.symbolIn = character;
      temp.isTerminal = false;
      temp.parent = vert;
      for (int ind = 0; ind < 52; ind++) {
        temp.out[ind] = -1;
        temp.goes[ind] = -1;
      }
      nodes.push_back(temp);
      nodes[vert].out[character] = (int) nodes.size() - 1;
    }
    vert = nodes[vert].out[character];
  }
  nodes[vert].isTerminal = true;
  nodes[vert].indicesOfSubpattern.push_back(index);
}

void AkhoStateMachine::BuildBor() {
  std::vector<int> starts = getStartIndicesOfNonMaskSubpatterns();
  std::vector<int> ends = getEndIndicesOfNonMaskSubpatterns();

  for (int patt = 0; patt < starts.size(); patt++) {
    addSubPattern(starts[patt], ends[patt], patt);
  }
}

int AkhoStateMachine::getSuffLink(int node) {
  if (nodes[node].suffLink == -1) {
    if (nodes[node].parent == 0) {
      nodes[node].suffLink = 0;
    } else {
      nodes[node].suffLink = getLink(getSuffLink(nodes[node].parent), nodes[node].symbolIn);
    }
  }
  return nodes[node].suffLink;
}

int AkhoStateMachine::getLink(int node, char character) {
  if (nodes[node].goes[character] == -1) {
    if (nodes[node].out[character] != -1) {
      nodes[node].goes[character] = nodes[node].out[character];
    } else if (node == 0) {
      nodes[node].goes[character] = 0;
    } else {
      nodes[node].goes[character] = getLink(getSuffLink(node), character);
    }
  }
  return nodes[node].goes[character];
}

std::vector<int> AkhoStateMachine::process() {
  BuildBor();
  std::vector<int> ends = getEndIndicesOfNonMaskSubpatterns();
  std::vector<int> starts = getStartIndicesOfNonMaskSubpatterns();
  std::vector<int> enters(text.length());
  int node = 0;
  for (int pos = 0; pos < text.length(); pos++) {
    node = getLink(node, text[pos] - 'a');
    int temp = node;
    do {
      if (nodes[temp].isTerminal) {
        for (int index = 0; index < nodes[temp].indicesOfSubpattern.size(); index++) {
          int startIndex = pos - ends[nodes[temp].indicesOfSubpattern[index]] +
              starts[nodes[temp].indicesOfSubpattern[index]];
          if ((startIndex - starts[nodes[temp].indicesOfSubpattern[index]] >= 0) &&
              (startIndex - starts[nodes[temp].indicesOfSubpattern[index]] + pattern.length() - 1 < text.length())) {
            ++enters[startIndex - starts[nodes[temp].indicesOfSubpattern[index]]];
          }
        }
      }
      temp = getSuffLink(temp);
    } while (temp != 0);
  }
  std::vector<int> answer;
  for (int index = 0; index < enters.size(); index++) {
    if (enters[index] == starts.size()) {
      answer.push_back(index);
    }
  }
  return answer;
}

int AkhoStateMachine::getFSMStates() {
  return (int) nodes.size();
}