//
// Created by Maria on 9/27/2016.
//

#include "Field.h"

Field::Field(unsigned long field_s, std::vector<int>& layout_, Field* parent_):
  layout(layout_), field_size(field_s), parent(parent_), pr_function(0), move(' '), steps_from_start(0) {
  for (unsigned long i = 0; i < field_size * field_size; i++)
    if (!layout[i]) {
      zero_position = i;
      break;
    }
}


unsigned long Field::hammingHeuristic() const {
  unsigned long answer = 0;
  for (int i = 0; i < field_size * field_size; i++)
    if ((layout[i] != i + 1) && (layout[i]))
      answer++;
  return answer;
}

bool Field::operator==(const Field& second) const {
  if (field_size != second.field_size)
    return false;
  for (int i = 0; i < field_size * field_size; i++)
    if (layout[i] != second.layout[i])
      return false;
  return true;
}

bool Field::operator<(const Field& another) const{
  return this->pr_function < another.pr_function || (this->pr_function == another.pr_function &&
      this->layout < another.layout);
}

bool Field::isSolvable() const {
  unsigned long test = 0;
  for (int i = 0; i < field_size * field_size; i++)
    if (layout[i])
      for (int j = 0; j < i; j++)
        if (layout[i] < layout[j])
          test++;
  if (field_size % 2){
    return test % 2 == 0;
  }
  for (int i = 0; i < field_size * field_size; i++)
    if (!layout[i]){
      test = i / field_size + 1;
      break;
    }
  return test % 2 != 0;
}

bool Field::isWinPosition() const {
  unsigned long hamming = hammingHeuristic();
  return (hamming == 0);
}

void Field::setParent(Field* parent_) {
  parent = parent_;
}

void Field::setPrFunction(unsigned long x) {
  pr_function = x;
}


void Field::getNeighbors(std::vector<std::unique_ptr<Field>> &neigh_storage) const {
  unsigned long x_side, y_side;
  x_side = zero_position / field_size;
  y_side = zero_position % field_size;

  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      unsigned long new_x_side = x_side + i;
      unsigned long new_y_side = y_side + j;

      if ((new_x_side >= 0 && new_x_side < field_size) && (new_y_side >= 0 && new_y_side < field_size) &&
          ((i == 0 && (j == -1 || j == 1)) || (j == 0 && (i == -1 || i == 1)))) {
        std::vector<int> new_layout(layout);
        std::swap(new_layout[zero_position], new_layout[new_x_side * field_size + new_y_side]);
        std::unique_ptr<Field> new_field(new Field(field_size, new_layout));
        new_field->steps_from_start = steps_from_start + 1;
        unsigned long new_pr_function = new_field->steps_from_start + new_field->hammingHeuristic();
        new_field->setPrFunction(new_pr_function);
        if (i == 1)
          new_field->move = 'D';
        if (i == -1)
          new_field->move = 'U';
        if (j == 1)
          new_field->move = 'R';
        if (j == -1)
          new_field->move = 'L';
        neigh_storage.push_back(std::move(new_field));
      }
    }
  }
}

unsigned long Field::getPrFunction() const {
  return pr_function;
}

char Field::getMove() const {
  return move;
}

Field* Field::getParent() const {
  return parent;
}

int Field::getSize() {
  return field_size;
}

bool Field::operator!=(const Field& another) const {
  return !(*this == another);
}