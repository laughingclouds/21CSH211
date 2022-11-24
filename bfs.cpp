#include <iostream>
#include <list>

class Graph {
  int numVertices;
  std::list<int> *adjLists;
  bool *visited;

public:
  Graph(int vertices) {
    numVertices = vertices;
    adjLists = new std::list<int>[vertices];
  };

  void addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
  };

  void BFS(int startVertex) {
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
      visited[i] = false;
    std::list<int> queue;
    visited[startVertex] = true;
    queue.push_back(startVertex);
    std::list<int>::iterator i;
    while (!queue.empty()) {
      int currVertex = queue.front();
      std::cout << "Visited " << currVertex << '\n';

      queue.pop_front();
      for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end();
           ++i) {
        int adjVertex = *i;
        if (!visited[adjVertex]) {
          visited[adjVertex] = true;
          queue.push_back(adjVertex);
        }
      }
    }
  };
};

int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  g.BFS(2);
  return 0;
}