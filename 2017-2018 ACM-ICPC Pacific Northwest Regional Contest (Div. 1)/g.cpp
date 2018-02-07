#include <bits/stdc++.h>

using namespace std;

const int N = 5050;
vector<tuple<int, int, int> > g[N];
bool vis[N][N * 3];

int main() {
  int n, m, k, s, t;
  scanf("%d %d %d", &n, &m, &k);
  vector<int> val;
  scanf("%d %d", &s, &t);
  --s, --t;
  val.push_back(k+1);
  val.push_back(1);
  for (int i = 0; i < m; ++i) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    --a, --b;
    g[a].emplace_back(b, c, d+1);
    val.push_back(c);
    val.push_back(d+1);
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  for (int i = 0; i < n; ++i) {
    for (auto & it : g[i]) {
      int b, c, d;
      tie(b, c, d) = it;
      c = lower_bound(val.begin(), val.end(), c) - val.begin();
      d = lower_bound(val.begin(), val.end(), d) - val.begin();
      it = make_tuple(b, c, d);
    }
  }
  k = (int)val.size()-1;
  queue<pair<int, int> > que;
  for (int i = 0; i < k; ++i) {
    que.emplace(s, i);
    vis[s][i] = 1;
  }
  while (!que.empty()) {
    int v, id;
    tie(v, id) = que.front(); que.pop();
    for (auto it : g[v]) {
      int b, c, d;
      tie(b, c, d) = it;
      if (c <= id && id < d && !vis[b][id]) {
        vis[b][id] = 1;
        que.emplace(b, id);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < k; ++i) {
    if (vis[t][i])
      ans += val[i+1] - val[i];
  }
  printf("%d\n", ans);
    
  return 0;
}