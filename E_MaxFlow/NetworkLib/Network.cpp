//
// Created by maria on 05.11.16.
//

#include <queue>
#include <climits>
#include "Network.h"

Network::Network(long numberOfVertices):
    capacityMatrix(numberOfVertices + 1, std::vector<long>(numberOfVertices + 1, 0)),
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

    network.capacityMatrix[from][to] += capacity;
    network.capacityMatrix[to][from] += capacity;
  }

  for (int vertex1 = 1; vertex1 <=numberOfVertices; vertex1++) {
    for (int vertex2 = 1; vertex2 <=numberOfVertices; vertex2++) {
      network.residualNetwork[vertex1][vertex2] = network.capacityMatrix[vertex1][vertex2];
    }
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

  while (!verticesQueue.empty() && !visited[drain]) {
    long current = verticesQueue.front();
    verticesQueue.pop();

    for (long vertex = 1; vertex <= networkSize; vertex++) {
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

    for (long vertex = 1; vertex <= networkSize; vertex++) {
      parents[vertex] = 0;
    }
  }

  return maxFlow;
}

long Network::getNumberOfVertices() {
  return capacityMatrix.size();
}