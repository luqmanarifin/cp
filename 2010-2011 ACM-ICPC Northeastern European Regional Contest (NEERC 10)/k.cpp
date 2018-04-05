#include <bits/stdc++.h>

using namespace std;

const string NAME = "kgraph";
const int N = 10005;

vector<int> edge[N];
set<pair<int, int>> can[N];
int col[N];

void remove(int at, int val) {
  auto it = can[at].lower_bound(make_pair(val + 1, -1));
  if (it == can[at].begin()) return;
  it--;
  int l = it->first;
  int r = it->second;
  if (l <= val && val <= r) {
    if (l <= val - 1) {
      can[at].insert(make_pair(l, val - 1));
    }
    if (val + 1 <= r) {
      can[at].insert(make_pair(val + 1, r));
    }
    can[at].erase(make_pair(l, r));
  }
}

int main() {
#ifndef LOCAL
  freopen((NAME + ".in").c_str(), "r", stdin);
  freopen((NAME + ".out").c_str(), "w", stdout);
#endif

  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  vector<pair<int, int>> d;
  for (int i = 1; i <= n; i++) {
    d.emplace_back(edge[i].size(), i);
    can[i].insert(make_pair(1, n));
  }
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  int ans = 0;
  for (auto it : d) {
    int now = it.second;
    col[now] = (can[now].begin())->first;
    for (auto near : edge[now]) {
      remove(near, col[now]);
    }
    ans = max(ans, col[now]);
  }
  if (ans % 2 == 0) ans++;
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++) printf("%d\n", col[i]);
  
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
  return 0;
}
