#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

vector<int> edge[N];
int rmq[N][25], lef[N], rig[N], h[N];
vector<int> st;

int f[N], deep[N];
vector<int> at[N];
int ans;

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

int solve(int now, int bef = -1) {
  int ret = deep[now];
  for (auto it : edge[now]) {
    if (it == bef) continue;
    int val = solve(it, now);
    if (val == 0) ans++;
    ret += val;
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < N; i++) {
      edge[i].clear();
      at[i].clear();
    }
    st.clear();
    memset(deep, 0, sizeof(deep));

    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d", f + i);
      at[f[i]].push_back(i);
    }
    dfs(1);
    for (int i = 0; i < st.size(); i++) rmq[i][0] = st[i];
    for (int j = 1; (1 << j) <= st.size(); j++) {
      for (int i = 0; i + (1 << j) <= st.size(); i++) {
        rmq[i][j] = (h[rmq[i][j-1]] < h[rmq[i+(1<<(j-1))][j-1]]? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1]);
      }
    }

    for (int i = 1; i <= n; i++) {
      if (at[i].empty()) continue;
      int root = at[i][0];
      for (auto it : at[i]) {
        root = lca(root, it);
      }
      deep[root] -= at[i].size();
      for (auto it : at[i]) {
        deep[it]++;
      }
    }
    ans = 0;
    solve(1);
    printf("Case #%d: %d\n", tt, ans);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
