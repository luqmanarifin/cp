#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<int> edge[N];
bool vis[N], done[N];
vector<int> st;
int to[N], d[N], ans[N];

void dfs(int now) {
  if (vis[now]) return;
  vis[now] = 1;
  st.push_back(now);
  for (auto it : edge[now]) dfs(it);
}

void clear(int n) {
  for (int i = 1; i <= n; i++) {
    edge[i].clear();
    vis[i] = done[i] = to[i] = 0;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    int now = 0;
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) {
        st.clear();
        dfs(i);

        set<pair<int, int>> s;  // to[i], i
        for (auto it : st) {
          to[it] = edge[it].size();
          s.insert(make_pair(to[it], it));
        }
        int cur = now + st.size();
        while (!s.empty()) {
          auto now = s.begin();
          done[now->second] = 1;
          d[now->second] = now->first;
          ans[now->second] = cur--;
          int tmp = now->second;
          // printf("iter %d %d %d\n", now->first, tmp, s.size());
          s.erase(now);
          for (auto it : edge[tmp]) {
            if (!done[it]) {
              s.erase(make_pair(to[it], it));
              to[it]--;
              s.insert(make_pair(to[it], it));
            }
          }
        }

        now += st.size();
      }
    }
    int mn = 1e9, mx = -1;
    for (int i = 1; i <= n; i++) {
      mn = min(d[i], mn);
      mx = max(d[i], mx);
    }
    printf("%d\n", mx - mn);
    for (int i = 1; i <= n; i++) {
      printf("%d%c", ans[i], i == n? '\n' : ' ');
    }

    clear(n);
  }

  return 0;
}
