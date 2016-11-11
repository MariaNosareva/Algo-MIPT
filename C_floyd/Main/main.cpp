// Полный ориентированный граф задан матрицей смежности. Постройте матрицу кратчайших вершим между его вершинами.
// Гарантируется, что в графе нет циклов отрицательного веса.

#include <iostream>
#include <vector>
#include <fstream>
#include "../GraphLib/GraphForFloyd.h"

int main() {
  std::ifstream in("floyd.in");
  GraphForFloyd graph = GraphForFloyd::FromStream(in);
  in.close();

  graph.Floyd();
  std::ofstream out("floyd.out");
  graph.PrintShortestPathsMatrix(out);
  out.close();
  return 0;
}