//
// Created by Maria on 9/27/2016.
//

#include <map>
#include <memory>
#include "PuzzleSolver.h"

struct cmp{
  bool operator()(std::shared_ptr<Field> a, std::shared_ptr<Field> b) {
      return (*b) < (*a);
  }
};


PuzzleSolver::PuzzleSolver(int field_s, std::vector<int>& layout_):
    init_field(field_s, layout_), moves_to_solve(0), solution("") {}

void PuzzleSolver::SolveIt() {
  solution.clear();
  if (!init_field.IsSolvable()){
    solution = "-1";
    return;
  }

  std::priority_queue<std::shared_ptr<Field>, std::vector<std::shared_ptr<Field>>, cmp> queue;
  queue.push(std::make_shared<Field>(init_field));
  std::map<Field, int> map_for_search;
  int hamm_h = init_field.hamming_heuristic();
  init_field.set_pr_function(hamm_h);

  while(!queue.empty()) {
    std::shared_ptr<Field> cur_board = queue.top();
    queue.pop();

    if (cur_board->is_win_position()) {
      while(cur_board->get_parent() != nullptr) {
        solution = cur_board->get_move() + solution;
        cur_board = cur_board->get_parent();
        moves_to_solve++;
      }
      return;
    }

    std::vector<std::shared_ptr<Field>> neighbors;
    cur_board->GetNeighbors(neighbors);
    for (int item = 0; item < neighbors.size(); item++) {
      if ((cur_board->get_parent() != nullptr) && *(neighbors[item]) == *(cur_board->get_parent()))
        continue;
      if (map_for_search.find(*(neighbors[item])) == map_for_search.end()) {
        map_for_search.insert(map_for_search.begin(),
                              std::make_pair(*(neighbors[item]), neighbors[item]->get_pr_function()));
        neighbors[item]->set_parent(cur_board);
        queue.push(neighbors[item]);
      }
    }
  }
}

int PuzzleSolver::get_moves() {
  return moves_to_solve;
}

std::string PuzzleSolver::get_solution() {
  return solution;
}

int PuzzleSolver::getSize() {
  return init_field.getSize();
}