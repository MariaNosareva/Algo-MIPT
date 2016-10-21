  #include <iostream>
  #include <fstream>
  #include "Graph.h"

  int main() {
    std::ifstream in("kruskal.in");
    Graph graph = Graph::FromStream(in);
    in.close();

    std::ofstream out("kruskal.out");
    out << graph.MST();
    out.close();
    return 0;
  }