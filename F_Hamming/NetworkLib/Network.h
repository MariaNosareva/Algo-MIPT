//
// Created by maria on 09.11.16.
//

#ifndef F_HAMMING_NETWORK_H
#define F_HAMMING_NETWORK_H

#include <vector>
#include <map>
struct Edge {
  int from;
  int to;
  int capacity;
  int flow;
  int reverseIndex;
};

struct VertexInfo {
  int pattOrStr; //0 if pattern, 1 if str
  int index;

  friend bool operator<(const VertexInfo& first, const VertexInfo& second) {
    return (first.pattOrStr < second.pattOrStr) || ((first.pattOrStr == second.pattOrStr) &&
        (first.index < second.index));
  }
};


class Network {
 private:
  std::vector<std::vector<Edge>> edgesMatrix;
  std::vector<std::vector<int>> questionsInfo;
  std::vector<VertexInfo> numberOfQuestion;
  int hammingDistance;
  int numberOfVertices;
  int numberOfEdges;
  int source;
  int drain;
  std::string pattern;
  std::string str;

 public:
  Network();
  void AddEdge(int, int);
  static Network BuildNetwork(std::string&, std::string&);
  bool BFS(std::vector<int>&);
  int DFS(std::vector<int>&, std::vector<int>&, int, int);
  int FindMaxFlow();
  void MinCutDFS(std::vector<int>&, int);
  void MinCut();
  std::string GetPattern();
  std::string GetString();
  int GetHammingDistance();
};

#endif //F_HAMMING_NETWORK_H
