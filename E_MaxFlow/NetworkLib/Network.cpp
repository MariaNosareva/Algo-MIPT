//
// Created by maria on 05.11.16.
//

#include <queue>
#include <climits>
#include "Network.h"

Network::Network(long numberOfVertices):
    residualNetwork(numberOfVertices + 1, std::vector<long>(numberOfVertices + 1, 0)){}

Network Network::FromStream(std::istream& input) {
  long numberOfVertices = 0;
  input >> numberOfVertices;
  Network network(numberOfVertices);

  if (numberOfVertices == 0) {
    return network;
  }

  long source, drain, numberOfEdges;
  input >> source >> drain >> numberOfEdges;

  network.source = source;
  network.drain = drain;

  for (int edge = 0; edge < numberOfEdges; edge++) {
    long from, to, capacity;
    input >> from >> to >> capacity;

    network.residualNetwork[from][to] += capacity;
    network.residualNetwork[to][from] += capacity;
  }

  return network;
}

bool Network::BFS(std::vector<long>& parents) {
  long networkSize = residualNetwork.size();
  std::vector<bool> visited(networkSize);

  std::queue<long> verticesQueue;
  verticesQueue.push(source);
  visited[source] = true;
  parents[source] = -1;

  long current = -1;
  while (!verticesQueue.empty() && !visited[drain]) {
    current = verticesQueue.front();
    verticesQueue.pop();

    for (long vertex = 0; vertex < networkSize; vertex++) {
      if (visited[vertex] == false && residualNetwork[current][vertex] > 0) {
        verticesQueue.push(vertex);
        parents[vertex] = current;
        visited[vertex] = true;
      }
    }
  }

  return visited[drain];
}

long Network::MaxFlow() {
  long maxFlow = 0;
  long networkSize = residualNetwork.size();
  std::vector<long> parents(networkSize + 1);

  while (BFS(parents)) {
    long minPathFlow = LONG_MAX;

    for (long vertex = drain; vertex != source; vertex = parents[vertex]) {
      long anotherVertex = parents[vertex];
      minPathFlow = std::min(minPathFlow, residualNetwork[anotherVertex][vertex]);
    }

    maxFlow += minPathFlow;

    for (long vertex = drain; vertex != source; vertex = parents[vertex]) {
      long anotherVertex = parents[vertex];
      residualNetwork[anotherVertex][vertex] -= minPathFlow;
      residualNetwork[vertex][anotherVertex] += minPathFlow;
    }
  }

  return maxFlow;
}

long Network::getNumberOfVertices() {
  return residualNetwork.size();
}