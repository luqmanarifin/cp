#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> edge[N];
int rmq[N][20], lef[N], rig[N], h[N];
vector<int> st;
bool can[N];

void dfs(int now, int bef = -1) {
  lef[now] = rig[now] = st.size();
  st.push_back(now);
  for (auto it : edge[now]) {
    if (bef == it) continue;
    h[it] = h[now] + 1;
    dfs(it, now);
    rig[now] = st.size();
    st.push_back(now);
  }
}

int lca(int u, int v) {
  int l = min(lef[u], lef[v]);
  int r = max(rig[u], rig[v]);
  int g = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

int dist(int u, int v) {
  int root = lca(u, v);
  return h[u] + h[v] - 2 * h[root];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1);
  for (int i = 0; i < st.size(); i++) rmq[i][0] = st[i];
  for (int j = 1; (1 << j) <= st.size(); j++) {
    for (int i = 0; i + (1 << j) <= st.size(); i++) {
      rmq[i][j] = (h[rmq[i][j-1]] < h[rmq[i+(1<<(j-1))][j-1]]? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1]);
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int k;
    scanf("%d", &k);
    vector<int> ask;
    while (k--) {
      int v;
      scanf("%d", &v);
      ask.push_back(v);
    }
    if (ask.size() == 1) {
      puts("0");
      continue;
    }
    vector<int> c;
    for (int i = 0; i < ask.size(); i++) {
      for (int j = i + 1; j < ask.size(); j++) {
        int root = lca(ask[i], ask[j]);
        if (!can[root]) {
          can[root] = 1;
          c.push_back(root);
        }
      }
    }
    int ans = 1e9;
    for (auto cen : c) {
      int cur = 0;
      for (auto it : ask) {
        cur += dist(cen, it);
      }
      ans = min(ans, cur);
    }
    printf("%d\n", ans);
    
    for (auto it : c) can[it] = 0;
  }

  return 0;
}
