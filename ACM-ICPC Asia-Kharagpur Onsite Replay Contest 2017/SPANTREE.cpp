#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int par[N], done[N], n, maxi;
vector<int> el[N];

void merge(int u, int v) {
  u = par[u];
  v = par[v];
  if (el[u].size() < el[v].size()) {
    for (auto it : el[u]) {
      el[v].push_back(it);
      par[it] = v;
    }
  } else {
    for (auto it : el[v]) {
      el[u].push_back(it);
      par[it] = u;
    }
  }
  maxi = max(maxi, (int) el[u].size());
  maxi = max(maxi, (int) el[v].size());
}

bool cok[N];

void ask(int root) {
  memset(cok, 0, sizeof(cok));
  for (auto it : el[root]) cok[it] = 1;
  if (el[root].size() < n - el[root].size()) {
    printf("1 %d %d\n", el[root].size(), n - el[root].size());
    for (int i = 1; i <= n; i++) if (cok[i]) printf("%d ", i); printf("\n");
    for (int i = 1; i <= n; i++) if (!cok[i]) printf("%d ", i); printf("\n");
  } else {
    printf("1 %d %d\n", n - el[root].size(), el[root].size());
    for (int i = 1; i <= n; i++) if (!cok[i]) printf("%d ", i); printf("\n");
    for (int i = 1; i <= n; i++) if (cok[i]) printf("%d ", i); printf("\n");
  }
  fflush(stdout);
}

int main() {
  scanf("%d", &n);
  int ans = 0;
  maxi = 1;
  for (int i = 1; i <= n; i++) par[i] = i, el[i].push_back(i);
  while (maxi < n) {
    memset(done, 0, sizeof(done));
    vector<tuple<int, int, int>> edges;
    for (int i = 1; i <= n; i++) {
      int root = par[i];
      if (done[root]) continue;
      done[root] = 1;
      ask(root);
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      edges.emplace_back(w, u, v);
    }
    sort(edges.begin(), edges.end());
    for (auto it : edges) {
      int w, u, v;
      tie(w, u, v) = it;
      if (par[u] == par[v]) continue;
      ans += w;
      merge(u, v);
    }
  }
  printf("2 %d\n", ans);
  fflush(stdout);
  return 0;
}
