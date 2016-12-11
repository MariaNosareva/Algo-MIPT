//
// Created by maria on 11.12.16.
//

#ifndef PROJECT_BST_H
#define PROJECT_BST_H

#include <memory>
#include <istream>
#include <vector>

struct BSTNode {
  int key;
  std::shared_ptr<BSTNode> left;
  std::shared_ptr<BSTNode> right;
  std::shared_ptr<BSTNode> parent;

  BSTNode(int key_): key(key_), parent(nullptr), left(nullptr), right(nullptr) {}
  BSTNode(): key(0), parent(nullptr), left(nullptr), right(nullptr) {}
};

class BST {
 private:
  std::shared_ptr<BSTNode> root;
  int size;
  int height(std::shared_ptr<BSTNode>);
  void width(std::shared_ptr<BSTNode>, int, std::vector<int>&);
 public:
  BST();
  static BST FromStream(std::istream&);
  void Insert(int);
  int GetHeight();
  int GetRootValue();
  int GetWidth();
};

#endif //PROJECT_BST_H
