//
// Created by maria on 20.10.16.
//

#include "Graph.h"
#include <algorithm>
#include "DSU.h"

Graph::Graph(unsigned long vert, unsigned long edges): number_of_vertices(vert), number_of_edges(edges) {
}

Graph Graph::FromStream(std::istream& in) {
  unsigned long num_of_vert, num_of_edges;
  in >> num_of_vert >> num_of_edges;
  Graph graph(num_of_vert, num_of_edges);
  for (int m = 0; m < num_of_edges; m++) {
    int first, second, weigh;
    in >> first >> second >> weigh;
    graph.edges_matrix.push_back(std::make_pair(std::make_pair(first, second), weigh));
  }
  return graph;
}

int Graph::MST() {
  int weigh = 0;
  std::sort(edges_matrix.begin(), edges_matrix.end(),
            [this](std::pair<std::pair<int, int>, int> first, std::pair<std::pair<int, int>, int> second)->bool {
              return first.second < second.second; });
  DSU connected_components(number_of_vertices);
  for (int position = 0; position < number_of_edges; position++) {
    int first_component = connected_components.Find(edges_matrix[position].first.first);
    int second_component = connected_components.Find(edges_matrix[position].first.second);
    if (first_component != second_component) {
      connected_components.Unite(first_component, second_component);
      weigh += edges_matrix[position].second;
    }
  }
  return weigh;
}