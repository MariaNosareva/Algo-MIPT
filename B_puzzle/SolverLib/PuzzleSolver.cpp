//
// Created by Maria on 9/27/2016.
//

#include <map>
#include <memory>
#include "PuzzleSolver.h"

struct cmp{
  bool operator()(Field* a, Field* b) {
    return (*b) < (*a);
  }
};

PuzzleSolver::PuzzleSolver(unsigned long field_s, std::vector<int>& layout_):
    init_field(field_s, layout_), moves_to_solve(0), solution("") {}

void PuzzleSolver::solveIt() {
  solution.clear();
  if (!init_field.isSolvable()){
    solution = "-1";
    return;
  }

  std::priority_queue<Field*, std::vector<Field*>, cmp> queue;
  queue.push(&init_field);
  std::map<std::unique_ptr<Field>, int> map_for_search;
  unsigned long hamm_h = init_field.hammingHeuristic();
  init_field.setPrFunction(hamm_h);

  while(!queue.empty()) {
    Field* cur_board = queue.top();
    queue.pop();

    if (cur_board->isWinPosition()) {
      while(cur_board->getParent() != nullptr) {
        solution = cur_board->getMove() + solution;
        cur_board = cur_board->getParent();
        moves_to_solve++;
      }
      return;
    }

    std::vector<std::unique_ptr<Field>> neighbors;
    cur_board->getNeighbors(neighbors);
    for (int item = 0; item < neighbors.size(); item++) {
      if ((cur_board->getParent() != nullptr) && *(neighbors[item]) == *(cur_board->getParent()))
        continue;
      if (map_for_search.find(neighbors[item]) == map_for_search.end()) {
        neighbors[item]->setParent(cur_board);
        queue.push(neighbors[item].get());
        map_for_search.insert(map_for_search.begin(),
                              std::make_pair(std::move(neighbors[item]), neighbors[item]->getPrFunction()));
      }
    }
  }
}

int PuzzleSolver::getMoves() {
  return moves_to_solve;
}

std::string PuzzleSolver::getSolution() {
  return solution;
}

int PuzzleSolver::getSize() {
  return init_field.getSize();
}