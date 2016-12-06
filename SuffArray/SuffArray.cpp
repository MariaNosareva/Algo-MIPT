//
// Created by maria on 05.12.16.
//

#include "SuffArray.h"

SuffArray::SuffArray(): text(""), suffArray(0), LCP(0), textLen(0) {}

SuffArray SuffArray::FromStream(std::istream& in) {
  SuffArray array;
  in >> array.text;
  array.text = array.text + '\0';
  array.textLen = (int)array.text.length();
  array.suffArray.resize(array.text.length());
  //TODO resize LCP

  return array;
}

std::vector<int> SuffArray::MakeSuffArray() {
  int numOfClasses = 0;
  int alphabetLen = 256;
  std::vector<int> counter((unsigned long)alphabetLen, 0);
  std::vector<int> suffIndices(text.length());
  std::vector<int> classes(text.length());

  for (int index = 0; index < text.length(); index++) {
    ++counter[text[index]];
  }
  for (int index = 1; index < alphabetLen; index++) {
    counter[index] += counter[index - 1];
  }
  for (int index = (int)text.length() - 1; index >= 0; index--) {
    suffIndices[--counter[text[index]]] = index;
  }

  classes[suffIndices[0]] = 0;
  numOfClasses++;
  for (int index = 1; index < text.length(); index++) {
    if (text[suffIndices[index]] != text[suffIndices[index - 1]]) {
      ++numOfClasses;
    }
    classes[suffIndices[index]] = numOfClasses - 1;
  }

  int length = 1;
  while (length < text.length()) {
    std::vector<int> suffIndices2(text.length());
    std::vector<int> classes2(text.length());

    counter.assign(numOfClasses, 0);
    for (int index = 0; index < text.length(); index++) {
      ++counter[classes[index]];
    }
    for (int index = 1; index < numOfClasses; index++) {
      counter[index] += counter[index - 1];
    }
    for (int index = textLen - 1; index >= 0; index--) {
      suffIndices2[--counter[classes[(suffIndices[index] - length + textLen) % textLen]]] =
                                        (suffIndices[index] - length + textLen) % textLen;
    }
    suffIndices = suffIndices2;
    classes2[suffIndices[0]] = 0;
    numOfClasses = 1;
    for (int index = 1; index < text.length(); index++) {
      if (classes[suffIndices[index]] != classes[suffIndices[index - 1]] ||
          classes[(suffIndices[index] + length) % textLen] != classes[(suffIndices[index - 1] + length) % textLen]) {
        ++numOfClasses;
      }
      classes2[suffIndices[index]] = numOfClasses - 1;
    }
    classes = classes2;

    length *= 2;
  }
  suffArray = suffIndices;
  return suffArray;
}