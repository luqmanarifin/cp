#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

set<pair<int, int>> edge[N];
vector<pair<int, int>> nekko[N];

// node, cost
pair<int, int> solve(int now, int bef) {
  auto it = edge[now].begin();
  if (it != edge[now].end() && it->second == bef) it++;
  if (it == edge[now].end()) {
    return make_pair(-1, 0);
  } else {
    return make_pair(it->second, it->first);
  }
}

int main() {
  int n, m, k, t1;
  scanf("%d %d %d %d", &n, &m, &k, &t1);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    nekko[a].emplace_back(b, c);
    nekko[b].emplace_back(a, c);
  }
  for (int i = 0; i < n; i++) {
    sort(nekko[i].begin(), nekko[i].end());
    for (int j = 0; j < nekko[i].size(); j++) {
      edge[i].insert(make_pair(nekko[i][j].second, nekko[i][j].first));
      while (j + 1 < nekko[i].size() && nekko[i][j + 1].first == nekko[i][j].first) j++;
    }
  }
  long long ans = 0;
  int now = t1, bef = -1;
  while (k--) {
    auto it = solve(now, bef);
    if (it.first == -1) break;
    // printf("%d goto %d\n", now, it.first);
    ans += it.second;
    bef = now;
    now = it.first;
  }
  cout << ans << endl;
  return 0;
}
