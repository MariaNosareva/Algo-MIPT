#include "KMP.h"

KMP::KMP(): str(""), pattern(""), patternPrefixFunc(0) {}

KMP KMP::FromStream(std::istream& in) {
  KMP kmp;
  std::string pattern_, str_;
  in >> pattern_;
  in >> str_;

  kmp.pattern = pattern_;
  kmp.str = str_;
  kmp.patternPrefixFunc = std::vector<int>(kmp.pattern.length());
  kmp.calculatePrefixFunc();

  return kmp;
}

void KMP::calculatePrefixFunc() {
  int maxIndex = 0;
  for (int index = 1; index < pattern.length(); index++) {
    maxIndex = patternPrefixFunc[index - 1];

    while (maxIndex != 0 && pattern[maxIndex] != pattern[index]) {
      maxIndex = patternPrefixFunc[maxIndex - 1];
    }
    if (pattern[maxIndex] == pattern[index]) {
      maxIndex++;
    }
    patternPrefixFunc[index] = maxIndex;
  }
}

std::vector<int> KMP::getIndices() {
  std::vector<int> indices;

  int prev = 0;
  for (int index = 0; index < str.length(); index++) {
    while (prev != 0 && str[index] != pattern[prev]) {
      prev = patternPrefixFunc[prev - 1];
    }

    if (str[index] == pattern[prev]) {
      prev++;
      if (prev == pattern.length()) {
        indices.push_back(index - prev + 1);
      }
    }
  }
  return indices;
}

std::string KMP::getPattern() {
  return pattern;
}

std::string KMP::getStr() {
  return str;
}
std::vector<int> KMP::getPatternPrefixFunc() {
  return patternPrefixFunc;
}
