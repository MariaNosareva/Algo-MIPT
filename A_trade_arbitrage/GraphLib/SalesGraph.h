//
// Created by Maria on 9/25/2016.
//

#ifndef TRADE_ARBITRAGE_SALES_GRAPH_H
#define TRADE_ARBITRAGE_SALES_GRAPH_H

#include <iostream>
#include <vector>

class SalesGraph {
 private:
  unsigned long number_of_vertices;
  std::vector<std::vector<double>> vertices_matrix;

 public:
  explicit SalesGraph(unsigned long);
  bool NoCircleHere();
  bool ArbitrageExistence();
  static SalesGraph FromStream(std::istream&);
  unsigned long getNumberOfVertices() const;
  std::vector<std::vector<double>> getVerticesMatrix() const;
};

#endif //TRADE_ARBITRAGE_SALES_GRAPH_H
