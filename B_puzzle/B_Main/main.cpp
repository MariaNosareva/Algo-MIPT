#include <iostream>
#include <vector>
#include <fstream>
#include "../SolverLib/Field.h"
#include "../SolverLib/PuzzleSolver.h"

int main() {
  unsigned long field_size = 3;
 // std::cin >> field_size;
  std::vector<int> game_field(field_size * field_size);
  std::ifstream fin("puzzle.in");
  for (int i = 0; i < field_size * field_size; i++){
    std::cin >> game_field[i];
  }
  fin.close();

  PuzzleSolver solver(field_size, game_field);
  solver.solveIt();
  std::string solution = solver.getSolution();
  std::ofstream fout("puzzle.out");
  if (solution != "-1")
    std::cout << solver.getMoves() << std::endl;
  std::cout << solution << std::endl;
  fout.close();
  return 0;
}