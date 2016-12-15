//
// Created by maria on 20.10.16.
//

#include "DSU.h"

DSU::DSU(unsigned long number_of_elements):
    parents(number_of_elements + 1),
    heights(number_of_elements + 1, 1) {
  for (int i = 0; i < number_of_elements; ++i) {
    parents[i] = i;
  }
}

int DSU::Find(int element) {
  if (parents[element] == element)
    return element;
  return parents[element] = Find(parents[element]);
}

void DSU::Unite(int first, int second) {
  int first_parent = Find(first);
  int second_parent = Find(second);
  if (first_parent == second_parent)
    return;
  if (heights[first_parent] < heights[second_parent])
    parents[first_parent] = second_parent;
  else {
    parents[second_parent] = first_parent;
    if (heights[first_parent] == heights[second_parent])
      heights[second_parent]++;
  }
}