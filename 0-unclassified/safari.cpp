#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int par[N], size[N], a[N];
vector<tuple<int, int, int>> edges;

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  size[v] += size[u];
  par[u] = v;
}

int main() {
  for(int i = 0; i < N; i++) {
    par[i] = i;
    size[i] = 1;
  }
  
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    edges.emplace_back(min(a[u], a[v]), u, v);
  }
  sort(edges.begin(), edges.end());
  reverse(edges.begin(), edges.end());
  long long ans = 0;
  for(auto it : edges) {
    int c, u, v;
    tie(c, u, v) = it;
    u = find(u);
    v = find(v);
    if(u != v) {
      ans += 1LL * c * size[u] * size[v];
      merge(u, v);
    }
  }
  long long tot = 1LL * n * (n - 1) / 2;
  printf("%.15f\n", 1. * ans / tot);
  return 0;
}
