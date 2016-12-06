//
// Created by maria on 05.12.16.
//

#include "SuffArray.h"

SuffArray::SuffArray(): text(""), suffArray(0), lcpArray(0), textLen(0) {}

SuffArray SuffArray::FromStream(std::istream& in) {
  SuffArray array;
  in >> array.text;
  array.text = array.text + '\0';
  array.textLen = (int)array.text.length();
  array.suffArray.resize(array.text.length() - 1);
  array.lcpArray.resize(array.text.length() - 1);

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
  for (int index = 1; index < suffIndices.size(); index++) {
    suffArray[index - 1] = suffIndices[index];
  }
  return suffArray;
}

int SuffArray::ArraySize() {
  return (int)suffArray.size();
}

std::vector<int> SuffArray::MakeLCP() {
  MakeSuffArray();
  std::vector<int> reversedSuffArray(text.length() - 1);
  for (int index = 0; index < suffArray.size(); index++) {
    reversedSuffArray[suffArray[index]] = index;
  }

  int lcpLength = 0;
  for (int curSuffPos = 0; curSuffPos < text.length() - 1; curSuffPos++) {
    if (lcpLength > 0) {
      --lcpLength;
    }
    if (reversedSuffArray[curSuffPos] == text.length() - 2) {
      lcpArray[text.length() - 2] = 0;
      lcpLength = 0;
    } else {
      int nextSuffPos = suffArray[reversedSuffArray[curSuffPos] + 1];
      while ((std::max(curSuffPos + lcpLength, nextSuffPos + lcpLength) < text.length() - 1) &&
          text[curSuffPos + lcpLength] == text[nextSuffPos + lcpLength]) {
        ++lcpLength;
      }
      lcpArray[reversedSuffArray[curSuffPos]] = lcpLength;
    }
  }
  return lcpArray;
}

int SuffArray::NumberOfDifferentSubstrings() {
  MakeLCP();
  int str = (int)(((1 + (text.length() - 1)) * (text.length() - 1))/ 2 );
  int sumLCPs = 0;
  for (int i = 0; i < lcpArray.size(); i++) {
    sumLCPs += lcpArray[i];
  }
  return str - sumLCPs;
}