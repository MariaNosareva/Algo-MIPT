//
// Created by Maria on 9/25/2016.
//

#include "SalesGraph.h"

SalesGraph::SalesGraph(unsigned long n = 0): number_of_vertices(n), vertices_matrix(n) {
  for (int i = 0; i < number_of_vertices; i++)
    vertices_matrix[i].resize(number_of_vertices);
}

SalesGraph SalesGraph::FromStream(std::istream& in) {
  unsigned long num_of_vert;
  in >> num_of_vert;
  SalesGraph graph(num_of_vert);
  for (int vertex1 = 0; vertex1 < num_of_vert; vertex1++) {
    for (int vertex2 = 0; vertex2 < num_of_vert; vertex2++) {
      if (vertex1 != vertex2) {
        double temp = 0;
        in >> temp;
        graph.vertices_matrix[vertex1][vertex2] = temp;
      } else
        graph.vertices_matrix[vertex1][vertex2] = 1;
    }
  }
  return graph;
}

bool SalesGraph::NoCircleHere() {
  std::vector<double> distances(number_of_vertices);
  for (int vertex = 0; vertex < number_of_vertices; vertex++){
    for (int i = 0; i < number_of_vertices; i++)
      distances[i] = -1;
    distances[vertex] = 1;

    bool relaxed = false;
    for (int step = 0; step < number_of_vertices - 1; step++){
      for (int first_vertex = 0; first_vertex < number_of_vertices; first_vertex++)
        for (int second_vertex = 0; second_vertex < number_of_vertices; second_vertex++){
          if ((distances[second_vertex] < distances[first_vertex] * vertices_matrix[first_vertex][second_vertex]) &&
              (vertices_matrix[first_vertex][second_vertex] != -1)) {
            distances[second_vertex] = distances[first_vertex] * vertices_matrix[first_vertex][second_vertex];
            relaxed = true;
          }
        }
      if (!relaxed)
        break;
    }
    if (distances[vertex] > 1)
      return false;
  }
  return true;
}

bool SalesGraph::ArbitrageExistence(){
  return !NoCircleHere();
}


