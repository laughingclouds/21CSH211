#include <stdio.h>
#include <stdlib.h>
void bfs(int v);
int a[50][50], n, visited[50];
int q[20], front = -1, rear = -1;

void creategraph() {
  int i, j;
  printf("\nEnter the number of vertices in graph:  ");
  scanf("%d", &n);
  printf("\nEnter the adjacency matrix:\n");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      scanf("%d", &a[i][j]);
}

void bfs(int v) {
  int i, cur;
  visited[v] = 1;
  q[++rear] = v;
  printf("\nNodes reachable from starting vertex %d are: ", v);
  while (front != rear) {
    cur = q[++front];
    for (i = 1; i <= n; i++) {
      if ((a[cur][i] == 1) && (visited[i] == 0)) {
        q[++rear] = i;
        visited[i] = 1;
        printf("%d ", i);
      }
    }
  }
}

int main() {
  int ch, start, i, j;
  creategraph();

  for (i = 1; i <= n; i++)
    visited[i] = 0;
  printf("\nEnter the starting vertex: ");
  scanf("%d", &start);
  bfs(start);
  for (i = 1; i <= n; i++) {
    if (visited[i] == 0)
      printf("\nThe vertex that is not reachable is %d", i);
  }
}