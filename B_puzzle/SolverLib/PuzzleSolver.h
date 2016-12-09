//
// Created by Maria on 9/27/2016.
//

#ifndef PYATNASHKI_PUZZLE_SOLVER_H
#define PYATNASHKI_PUZZLE_SOLVER_H

#include "Field.h"
#include <string>
#include <iostream>
#include <queue>
#include <vector>


class PuzzleSolver {
 private:
  int moves_to_solve;
  std::string solution;
  Field init_field;

 public:
  PuzzleSolver(unsigned long, std::vector<int>&);
  void solveIt();
  int getMoves();
  std::string getSolution();
  int getSize();
};

#endif //PYATNASHKI_PUZZLE_SOLVER_H
