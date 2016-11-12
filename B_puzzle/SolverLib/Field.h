//
// Created by Maria on 9/27/2016.
//

#ifndef PYATNASHKI_FIELD_H
#define PYATNASHKI_FIELD_H

#include <vector>
#include <memory>

class Field {
 private:
  std::vector<int> layout;
  int field_size;
  std::shared_ptr<Field> parent;
  int zero_position;
  int pr_function;
  int steps_from_start;
  char move;

 public:
  Field(int, std::vector<int>&, std::shared_ptr<Field> = nullptr);
  int hamming_heuristic();
  bool operator==(const Field&) const;
  bool operator<(const Field&) const;
  bool IsSolvable();
  bool is_win_position();
  void set_parent(std::shared_ptr<Field>);
  void set_pr_function(int);
  void GetNeighbors(std::vector<std::shared_ptr<Field>> &);
  int get_pr_function();
  char get_move();
  std::shared_ptr<Field> get_parent();
  int getSize();
};

#endif //PYATNASHKI_FIELD_H
