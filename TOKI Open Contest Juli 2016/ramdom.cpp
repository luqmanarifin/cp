#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
int now = 1;
int t[N], a[N], b[N], f[N];

int rmq[2 * N][20];
int h[N], l[N], r[N], cnt;

void dfs(int u) {
  for (auto it : edge[u]) {
    h[it] = h[u] + 1;
    dfs(it);
  }
}

void flatten(int u) {
  l[u] = cnt;
  rmq[cnt++][0] = u;
  for (auto it : edge[u]) {
    flatten(it);
    rmq[cnt++][0] = u;
  }
  r[u] = cnt - 1;
}

void build() {
  dfs(1);
  flatten(1);
  for (int j = 1; (1 << j) <= cnt; j++) {
    for (int i = 0; i + (1 << j) <= cnt; i++) {
      rmq[i][j] = (h[rmq[i][j - 1]] < h[rmq[i+(1<<(j-1))][j-1]]? rmq[i][j - 1] : rmq[i+(1<<(j-1))][j-1]);
    }
  }
}

int lca(int u, int v) {
  int lef = min(l[u], l[v]);
  int rig = max(r[u], r[v]);
  int g = __builtin_clz(rig - lef + 1) ^ 31;
  return h[rmq[lef][g]] < h[rmq[rig-(1<<g)+1][g]]? rmq[lef][g] : rmq[rig-(1<<g)+1][g];
}

bool check(int mbah, int anak) {
  return lca(mbah, anak) == mbah;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", t + i);
    if (t[i] == 1) {
      int v;
      scanf("%d", &v);
      edge[v].push_back(++now);
    } else {
      scanf("%d %d %d", a + i, b + i, f + i);
    }
  }
  build();
  for (int i = 0; i < n; i++) {
    if (t[i] == 2) {
      int c = lca(a[i], b[i]);
      int d = lca(a[i], f[i]);
      int e = lca(b[i], f[i]);
      if (check(c, f[i])) {
        if (h[d] < h[e]) {
          printf("%d\n", e);
        } else {
          printf("%d\n", d);
        }
      } else {
        printf("%d\n", c);
      }
    }
  }
  return 0;
}
