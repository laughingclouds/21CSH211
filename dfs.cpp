#include <stdio.h>
#include <stdlib.h>
void dfs(int v);
int a[50][50], n, visited[50];
int s[20], top = -1, count = 0;

void creategraph() {
  int i, j;
  printf("\nEnter the number of vertices in graph:  ");
  scanf("%d", &n);
  printf("\nEnter the adjacency matrix:\n");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      scanf("%d", &a[i][j]);
}

void dfs(int v) {
  int i;
  visited[v] = 1;
  s[++top] = v;
  for (i = 1; i <= n; i++) {
    if (a[v][i] == 1 && visited[i] == 0) {
      dfs(i);
      count++;
    }
  }
}

int main() {
  int ch, start, i, j;
  creategraph();
  for (i = 1; i <= n; i++)
    visited[i] = 0;
  printf("\n Enter the starting vertex:\t");
  scanf("%d", &start);
  dfs(start);
  printf("\nNodes reachable from starting vertex %d are:\n", start);
  for (i = 1; i <= count; i++)
    printf("%d\t", s[i]);
}