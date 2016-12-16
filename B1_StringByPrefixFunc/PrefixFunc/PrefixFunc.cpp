//
// Created by maria on 22.11.16.
//

#include "PrefixFunc.h"
#include <sstream>
#include <set>

PrefixFunc::PrefixFunc(): zFunction(0), prFunction(0), String("") {}

PrefixFunc PrefixFunc::PrFromStream(std::istream& in) {
  return FromStream(in, 'p');
}

PrefixFunc PrefixFunc::ZFromStream(std::istream& in) {
  return FromStream(in, 'z');
}

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
  prFunction.resize(zFunction.size(), 0);

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

        int length = prFunction[position - 1];
        while (length > 0) {
          illegal.insert(String[length]);
          length = prFunction[length - 1];
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