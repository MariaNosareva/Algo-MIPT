//
// Created by maria on 11.12.16.
//

#include <iostream>
#include <vector>
#include "BST.h"

BST::BST(): root(nullptr), size(0) {}

BST BST::FromStream(std::istream& in) {
  BST tree;
  int numOfNodes;
  in >> numOfNodes;

  for (int node = 0; node < numOfNodes; node++) {
    int tempKey;
    in >> tempKey;
    tree.Insert(tempKey);
  }
  return tree;
}

void BST::Insert(int key) {
  std::shared_ptr<BSTNode> parent(nullptr), temp(this->root);

  while (temp != nullptr) {
    parent = temp;
    if (key >= temp->key) {
      temp = temp->right;
    } else {
      temp = temp->left;
    }
  }

  BSTNode node(key);
  std::shared_ptr<BSTNode> newNode(std::make_shared<BSTNode>(node));
  newNode->parent = parent;

  if (parent == nullptr) {
    this->root = newNode;
  } else {
    if (newNode->key < parent->key) {
      parent->left = newNode;
    } else {
      parent->right = newNode;
    }
  }
  ++size;
}

int BST::height(std::shared_ptr<BSTNode> currNode) {
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

int BST::GetHeight() {
  return height(root);
}

int BST::GetRootValue() {
  return root->key;
}

int BST::GetWidth() {
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

void BST::width(std::shared_ptr<BSTNode> curNode, int lay, std::vector<int>& laysInfo) {
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