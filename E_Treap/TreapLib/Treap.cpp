//
// Created by maria on 10.12.16.
//

#include "Treap.h"

Treap::Treap(): root(nullptr),
                size(0) {}

Treap Treap::BuildTreap(std::istream& in) {
  Treap treap;
  int size_;
  in >> size_;

  for (int currNode = 0; currNode < size_; currNode++) {
    int key, prior;
    in >> key >> prior;
    treap.Insert(key, prior);
  }
  return treap;
}

void Treap::Split(std::shared_ptr<Node> current, int key, std::shared_ptr<Node>& left,
                  std::shared_ptr<Node>&  right) {

  if (!current) {
    left = nullptr;
    right = nullptr;
  } else if (current->key <= key) {
    Split((current->right), key, (current->right), right);
    left = current;
  } else {
    Split((current->left), key, left, (current->left));
    right = current;
  }
}

std::shared_ptr<Node> Treap::Merge(std::shared_ptr<Node> left, std::shared_ptr<Node> right) {
  if (!left || !right) {
    return (!left) ? right : left;
  }
  if (left->priority > right->priority) {
    left->right = Merge(left->right, right);
    return left;
  }

  right->left = Merge(left, right->left);
  return right;
}

void Treap::Insert(int key, int priority) {
  std::shared_ptr<Node> parent(nullptr), temp(root);
  while (temp != nullptr && temp->priority >= priority) {
    parent = temp;
    temp = (key >= temp->key) ? temp->right : temp->left;
  }

  std::shared_ptr<Node> left(nullptr), right(nullptr);
  Split(temp, key, left, right);

  Node tempNode(key, priority, left, right, parent);
  std::shared_ptr<Node> newNode(std::make_shared<Node>(tempNode));

  ++size;
  if (parent == nullptr) {
    root = newNode;
  } else if (parent->key <= newNode->key) {
    parent->right = newNode;
  } else {
    parent->left = newNode;
  }
}

int Treap::height(std::shared_ptr<Node> currNode) {
  if (currNode == nullptr) {
    return 0;
  }
  int leftHeight = 0, rightHeight = 0;

  if (currNode->left != nullptr) {
    leftHeight = height(currNode->left);
  }
  if (currNode->right != nullptr) {
    rightHeight = height(currNode->right);
  }
  int maxHeight = std::max(leftHeight, rightHeight);
  return maxHeight + 1;
}

int Treap::GetHeight() {
  return height(root);
}

int Treap::GetRootKey() {
  return root->key;
}

int Treap::GetRootPriority() {
  return root->priority;
}

int Treap::GetWidth() {
  std::vector<int> laySize(size, 0);
  width(root, 0, laySize);
  int max = 0;
  for (int pos = 0; pos < size; ++pos) {
    if (laySize[pos] > max) {
      max = laySize[pos];
    }
  }
  return max;
}

void Treap::width(std::shared_ptr<Node> curNode, int lay, std::vector<int>& laysInfo) {
  if (curNode == nullptr) {
    return;
  }

  ++laysInfo[lay];
  if (curNode->left != nullptr) {
    width(curNode->left, lay + 1, laysInfo);
  }
  if (curNode->right != nullptr) {
    width(curNode->right, lay + 1, laysInfo);
  }
}