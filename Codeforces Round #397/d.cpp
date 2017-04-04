#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int par[N], f[N], g[N], h[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int main() {
  for (int i = 0; i < N; i++) par[i] = i;

  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", f + i);
    merge(i, f[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (f[i] != f[find(i)]) {
      puts("-1");
      return 0;
    }
  }
  map<int, int> par_to_g;
  int m = 0;
  for (int i = 1; i <= n; i++) {
    int root = par[i];
    if (par_to_g.count(root)) {
      g[i] = par_to_g[root];
    } else {
      par_to_g[root] = ++m;
      g[i] = m;
      h[g[i]] = f[i];
    }
  }
  printf("%d\n", m);
  for (int i = 1; i <= n; i++) printf("%d ", g[i]); printf("\n");
  for (int i = 1; i <= m; i++) printf("%d ", h[i]); printf("\n");


  return 0;
}
