#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const int Q = 1e5 + 5;
const int magic = 800;

vector<int> edge[N];

vector<pair<int, int>> ask[N];
int ans[Q];
bool vis[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    edge[u].push_back(v);
  }
  int t = 0, q;
  scanf("%d", &q);
  while (q--) {
    int cmd;
    scanf("%d", &cmd);
    if (cmd == 1) {
      int x, d;
      scanf("%d %d", &x, &d);
      x--;
      if (d == 0) {
        edge[x].push_back(n);
      } else {
        edge[n].push_back(x);
      }
      n++;
    } else {
      int x, y;
      scanf("%d %d", &x, &y);
      x--; y--;
      ask[x].emplace_back(y, t++);
    }
  }
  for (int i = 0; i < n; i++) {
    memset(vis, 0, sizeof(vis));
    vis[i] = 1;
    queue<int> st;
    st.push(i);
    while (!st.empty()) {
      int now = st.front();
      st.pop();
      for (auto it : edge[now]) {
        if (!vis[it]) {
          vis[it] = 1;
          st.push(it);
        }
      }
    }
    for (auto it : ask[i]) {
      int near, id;
      tie(near, id) = it;
      ans[id] = vis[near];
    }
  }
  for (int i = 0; i < t; i++) puts(ans[i]? "Yes" : "No");
  return 0;
}
