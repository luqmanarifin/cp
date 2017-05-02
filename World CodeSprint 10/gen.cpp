#include <bits/stdc++.h>

using namespace std;

const int N = 11;

int a[N], par[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  for (int i = 0; i < N; i++) par[i] = i;
  
  int n = 10;
  printf("%d\n", n);
  srand(time(0));
  for (int i = 0; i < n; i++) printf("%d ", rand() % 20 - 10); printf("\n");
  int k = n - 1;
  while (k) {
    int u = rand() % n;
    int v = rand() % n;
    if (find(u) != find(v)) {
      merge(u, v);
      printf("%d %d\n", u + 1, v + 1);
      k--;
    }
  }
  return 0;
}
