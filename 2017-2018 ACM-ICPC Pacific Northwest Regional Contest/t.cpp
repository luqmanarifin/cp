#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

vector<int> all;
vector<tuple<int, int, int>> edge[N];
bool vis[N];

int main() {
  int n, m, k, s, t;
  scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);
  all.push_back(1);
  all.push_back(k + 1);
  for (int i = 0; i < m; i++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    all.push_back(c);
    all.push_back(d + 1);
    edge[a].emplace_back(b, c, d);
  }
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  int ans = 0;
  for (int it = 0; it + 1 < all.size(); it++) {
    int l = all[it], r = all[it + 1] - 1;
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      if (now == t) {
        ans += r - l + 1;
        break;
      }
      for (auto it : edge[now]) {
        int near, c, d;
        tie(near, c, d) = it;
        if (c <= l && r <= d && !vis[near]) {
          vis[near] = 1;
          q.push(near);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
