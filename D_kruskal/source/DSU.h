//
// Created by maria on 20.10.16.
//

#ifndef KRUSKAL_DSU_H
#define KRUSKAL_DSU_H

#include <vector>
class DSU {
 private:
  std::vector<int> parents;
  std::vector<int> heights;

 public:
  explicit DSU(unsigned long);
  int Find(int);
  void Unite(int, int);
};

#endif //KRUSKAL_DSU_H
