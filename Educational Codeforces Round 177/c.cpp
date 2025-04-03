#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int par[N], sz[N];
bool done[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u != v) {
    sz[u] += sz[v];
    par[v] = u;
  }
}

int p[N], d[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", p + i);
    for (int i = 1; i <= n; i++) scanf("%d", d + i);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      sz[i] = 1;
      done[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      merge(i, p[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int u = find(d[i]);
      if (!done[u]) {
        done[u] = 1;
        ans += sz[u];
      }
      printf("%d%c", ans, i == n? '\n' : ' ');
    }
  }

  return 0;
}
