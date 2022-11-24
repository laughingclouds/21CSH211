#include <iostream>
#include <list>

class Graph {
  int numVertices;
  std::list<int> *linkedList;
  bool *visited;

public:
  Graph(int v) {
    numVertices = v;
    linkedList = new std::list<int>[v];
    visited = new bool[v];
  };
  void addEdge(int src, int dest) { linkedList[src].push_front(dest); };
  void DFS(int vertex);
};

void Graph::DFS(int V) {
  visited[V] = true;
  std::list<int> List = linkedList[V];
  std::cout << V << " ";
  std::list<int>::iterator i;
  for (i = List.begin(); i != List.end(); ++i)
    if (!visited[*i])
      DFS(*i);
}
int main() {
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 3);
  g.DFS(0);
  return 0;
}