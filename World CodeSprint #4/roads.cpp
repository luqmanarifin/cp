#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int par[N], n, m;
vector<pair<int, int>> edge[N];
vector<tuple<int, int, int>> edges;
long long ans[N];

int find(int u) {
  return par[u] == u? u : par[u] = find(par[u]);
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

int dfs(int now, int bef) {
  int cnt = 1;
  for(auto it : edge[now]) {
    if(it.first == bef) continue;
    int ret = dfs(it.first, now);
    ans[it.second] += 1LL * ret * (n - ret);
    cnt += ret;
  }
  return cnt;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    edges.emplace_back(c, u, v);
  }
  sort(edges.begin(), edges.end());
  for(int i = 0; i < N; i++) par[i] = i;
  for(auto it : edges) {
    int u, v, c;
    tie(c, u, v) = it;
    if(find(u) != find(v)) {
      edge[u].emplace_back(v, c);
      edge[v].emplace_back(u, c);
      merge(u, v);
    }
  }
  dfs(1, -1);
  for(int i = 0; i < N; i++) {
    long long val = ans[i];
    ans[i] = 0;
    int j = i;
    while(val) {
      ans[j] += val % 2;
      val /= 2;
      j++;
    }
  }
  bool ada = 0;
  for(int i = N - 1; i >= 0; i--) {
    if(ans[i]) ada = 1;
    if(ada) printf("%lld", ans[i]);
  }
  printf("\n");
  return 0;
}
