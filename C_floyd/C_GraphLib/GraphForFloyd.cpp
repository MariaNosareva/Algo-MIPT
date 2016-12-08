//
// Created by Maria on 9/25/2016.
//

#include "GraphForFloyd.h"

GraphForFloyd::GraphForFloyd(unsigned long number_of_vertices_ = 0):
    number_of_vertices(number_of_vertices_),
    vertices_matrix(number_of_vertices_, std::move(std::vector<int>(number_of_vertices_))),
    shortest_paths(number_of_vertices_, std::move(std::vector<int>(number_of_vertices_))) {}

GraphForFloyd::GraphForFloyd() {}

GraphForFloyd GraphForFloyd::FromStream(std::istream& in) {
  unsigned long num_of_vert;
  in >> num_of_vert;
  GraphForFloyd graph(num_of_vert);
  for (int vertex1 = 0; vertex1 < num_of_vert; vertex1++) {
    for (int vertex2 = 0; vertex2 < num_of_vert; vertex2++) {
      int temp = 0;
      in >> temp;
      graph.vertices_matrix[vertex1][vertex2] = temp;
    }
  }
  graph.shortest_paths = graph.vertices_matrix;
  return graph;
}

void GraphForFloyd::Floyd(){
  for (int some_vertex = 0; some_vertex < number_of_vertices; some_vertex++)
    for (int vertex1 = 0; vertex1 < number_of_vertices; vertex1++)
      for (int vertex2 = 0; vertex2 < number_of_vertices; vertex2++)
        shortest_paths[vertex1][vertex2] = std::min(shortest_paths[vertex1][vertex2],
                                                    shortest_paths[vertex1][some_vertex] +
                                                        shortest_paths[some_vertex][vertex2]);
}

void GraphForFloyd::PrintShortestPathsMatrix(std::ostream &fout) {
  for (int vertex1 = 0; vertex1 < number_of_vertices; vertex1++) {
    for (int vertex2 = 0; vertex2 < number_of_vertices; vertex2++)
      fout << shortest_paths[vertex1][vertex2] << " ";
    fout << std::endl;
  }
}

std::vector<std::vector<int>> GraphForFloyd::GetMatrix() {
  return vertices_matrix;
}

std::vector<std::vector<int>> GraphForFloyd::GetFloydMatrix() {
  return shortest_paths;
}

int GraphForFloyd::GetSize() {
  return (int) number_of_vertices;
}