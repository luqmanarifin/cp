#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<pair<int, int>> edge[N];

long long find(int u, int v) {
  if (edge[u].size() > edge[v].size()) {
    swap(u, v);
  }
  int p = lower_bound(edge[u].begin(), edge[u].end(), make_pair(v, -1)) - edge[u].begin();
  if (p < edge[u].size() && edge[u][p].first == v) {
    return edge[u][p].second;
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 0; i < m; i++) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      edge[u].emplace_back(v, c);
      edge[v].emplace_back(u, c);
    }
    for (int i = 1; i <= n; i++) {
      sort(edge[i].begin(), edge[i].end());
    }
    printf("Case #%d:", tt);
    map<pair<int, int>, long long> cache;
    while (q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      if (edge[u].size() > edge[v].size()) {
        swap(u, v);
      } else if (edge[u].size() == edge[v].size() && u > v) {
        swap(u, v);
      }
      if (cache.count(make_pair(u, v))) {
        printf(" %lld", cache[make_pair(u, v)]);
        continue;
      }

      long long ans = 2LL * find(u, v);
      for (auto it : edge[u]) {
        ans += min((long long) it.second, find(it.first, v));
      }
      cache[make_pair(u, v)] = ans;
      printf(" %lld", ans);
    }
    printf("\n");
    cerr << tt << " done!" << endl; 

    for (int i = 1; i <= n; i++) edge[i].clear();
  }

  return 0;
}
