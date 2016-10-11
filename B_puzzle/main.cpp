#include <iostream>
#include <vector>
#include <fstream>
#include "Field.h"
#include "PuzzleSolver.h"

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
  solver.SolveIt();
  std::string solution = solver.get_solution();
  std::ofstream fout("puzzle.out");
  if (solution != "-1")
    std::cout << solver.get_moves() << std::endl;
  std::cout << solution << std::endl;
  fout.close();
  return 0;
}