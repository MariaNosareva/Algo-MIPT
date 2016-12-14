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
  unsigned long field_size;
  Field* parent;
  unsigned long zero_position;
  unsigned long pr_function;
  unsigned long steps_from_start;
  char move;

 public:
  Field(unsigned long, std::vector<int>&, Field* = nullptr);
  unsigned long hammingHeuristic() const;
  bool operator==(const Field&) const;
  bool operator!=(const Field&) const;
  bool operator<(const Field&) const;
  bool isSolvable()const;
  bool isWinPosition() const;
  void setParent(Field*);
  void setPrFunction(unsigned long);
  void getNeighbors(std::vector<std::unique_ptr<Field>> &) const;
  unsigned long getPrFunction() const;
  char getMove()const;
  Field* getParent() const;
  int getSize();
};

#endif //PYATNASHKI_FIELD_H
