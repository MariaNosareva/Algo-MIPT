//
// Created by maria on 22.11.16.
//

#include "PrefixFunc.h"
#include <sstream>
#include <set>

PrefixFunc::PrefixFunc(): zFunction(0), prFunction(0), String("") {}


PrefixFunc PrefixFunc::FromStream(std::istream &in, char character) {
  PrefixFunc prF;
  std::string input = "";
  std::getline(in, input);
  std::stringstream stream(input);

  std::string temp;
  if (character == 'p') {
    while (std::getline(stream, temp, ' ')) {
      prF.prFunction.push_back(std::stoi(temp));
    }
  }
  if (character == 'z') {
    while (std::getline(stream, temp, ' ')) {
      prF.zFunction.push_back(std::stoi(temp));
    }
  }
  return prF;
}

void PrefixFunc::FromZToP() {
  prFunction = std::vector<int>(zFunction.size(), 0);

  for (int index = 1; index < prFunction.size(); index++) {
    if (zFunction[index]) {
      for (int pos = zFunction[index] - 1; pos >= 0 && !prFunction[index + pos]; pos--) {
        prFunction[index + pos] = pos + 1;
      }
    }
  }
}

void PrefixFunc::MakeString() {
  String = "a";

  for (int position = 1; position < prFunction.size(); position++) {
    if (prFunction[position] == 0) {
      if (prFunction[position - 1] != 0) {
        std::set<char> illegal;

        for (int i = prFunction[position - 1] - 1; i > -1; i--) {
          bool prefixEqualsToSuffix = true;

          for (int pos = 0; pos < i + 1; pos++) {
            if (String[pos] != String[position - 1 - i + pos]) {
              prefixEqualsToSuffix = false;
            }
          }

          if (prefixEqualsToSuffix) {
            illegal.insert(String[i + 1]);
          }
        }

        for (char character = 'b'; character <= 'z'; character++) {
          if (illegal.find(character) == illegal.end()) {
            String += character;
            break;
          }
        }
      } else {
        String += 'b';
      }
    } else {
      String += String[prFunction[position] - 1];
    }
  }
}

std::string PrefixFunc::getString() {
  return String;
}

std::vector<int> PrefixFunc::getFunc() {
  return prFunction;
}