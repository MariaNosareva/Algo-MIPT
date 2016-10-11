//
// Created by Maria on 9/27/2016.
//

#ifndef PYATNASHKI_PUZZLE_SOLVER_H
#define PYATNASHKI_PUZZLE_SOLVER_H

#include "Field.h"
#include <string>
#include <iostream>
#include <queue>

class PuzzleSolver {
 private:
  int moves_to_solve;
  std::string solution;
  Field init_field;
 public:
  PuzzleSolver(int, std::vector<int>&);
  void SolveIt();
  int get_moves();
  std::string get_solution();
};

#endif //PYATNASHKI_PUZZLE_SOLVER_H
