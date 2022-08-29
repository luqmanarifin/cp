#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int par[N], c[N];
vector<int> e[N];
int a[N][N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v, int col) {
  int seed = c[u] ^ c[v] ^ col;
  u = find(u);
  v = find(v);
  if (e[u].size() > e[v].size()) {
    swap(u, v);
  }
  for (auto it : e[u]) {
    e[v].push_back(it);
    c[it] ^= seed;
  }
  par[u] = v;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    // init
    for (int i = 0; i < n; i++) {
      par[i] = i;
      c[i] = 0;
      e[i] = {i};
    }
    // puts("init done");
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i][j] == a[j][i]) continue;
        if (a[j][i] < a[i][j]) {
          // need to swap
          if (find(i) != find(j)) {
            merge(i, j, 1);
          }
        } else {
          // shouldn't swap
          if (find(i) != find(j)) {
            merge(i, j, 0);
          }
        }
      }
    }
    // puts("algo done");
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (c[i] != c[j]) {
          swap(a[i][j], a[j][i]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d%c", a[i][j], j == n - 1? '\n' : ' ');
      }
    }

    // reset
    for (int i = 0; i < n; i++) e[i].clear();
  }

  return 0;
}
