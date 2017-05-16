#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

set<pair<int, int>> edges;
vector<int> edge[N];
int ans[N];
vector<int> all[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edges.insert(make_pair(u, v));
    edges.insert(make_pair(v, u));
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  int best = 1e9, p = -1;
  for (int i = 1; i <= n; i++) {
    if (edge[i].size() < best) {
      best = edge[i].size();
      p = i;
    }
  }
  printf("%d\n", p);
  ans[p] = 1;
  all[1].push_back(p);
  queue<int> q;
  q.push(p);
  int pol = 1;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto it : edge[now]) {
      if (!ans[it]) {
        ans[it] = ans[now] + 1;
        all[ans[it]].push_back(it);
        pol = max(pol, ans[it]);
        q.push(it);
      }
    }
  }
  /*
  for (int it = 1; it <= pol; it++) {
    for (int i = 0; i < all[it].size(); i++) {
      for (int j = i + 1; j < all[it].size(); j++) {
        if (!edges.count(make_pair(all[it][i], all[it][j]))) {
          puts("NO");
          return 0;
        }
      }
    }
    if (it > 1) {
      for (int i = 0; i < all[it].size(); i++) {
        for (int j = 0; j < all[it-1].size(); j++) {
          if (!edges.count(make_pair(all[it][i], all[it-1][j]))) {
            puts("NO");
            return 0;
          }
        }
      }
    }
  }
  */
  puts("YES");
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
