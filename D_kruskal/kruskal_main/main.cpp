#include <iostream>
#include <fstream>
#include "../source/Graph.h"


int main(int argc, char ** argv) {
  std::ifstream in("kruskal.in");
  Graph graph = Graph::FromStream(in);
  in.close();

  std::ofstream out("kruskal.out");
  out << graph.MST();
  out.close();
  return 0;
}