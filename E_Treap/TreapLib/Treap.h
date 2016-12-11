//
// Created by maria on 10.12.16.
//

#ifndef PROJECT_TREAP_H
#define PROJECT_TREAP_H

#include <iosfwd>
#include <memory>
#include <iostream>
#include <vector>

struct Node {
  int key;
  int priority;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
  std::shared_ptr<Node> parent;

  Node(int key_, int prior_, std::shared_ptr<Node> left_, std::shared_ptr<Node> right_, std::shared_ptr<Node> parent_):
      key(key_),
      priority(prior_),
      left(left_),
      right(right_),
      parent(parent_) {}
};

class Treap {
 public:
  std::shared_ptr<Node> root;
  int size;
  std::shared_ptr<Node> Merge(std::shared_ptr<Node>, std::shared_ptr<Node>);
  void Split(std::shared_ptr<Node>, int, std::shared_ptr<Node>&, std::shared_ptr<Node>&);
  int height(std::shared_ptr<Node>);
  void width(std::shared_ptr<Node>, int, std::vector<int>&);

 public:
  Treap();
  static Treap BuildTreap(std::istream&);
  void Insert(int, int);
  int GetHeight();
  int GetRootKey();
  int GetRootPriority();
  int GetWidth();
};

#endif //PROJECT_TREAP_H
