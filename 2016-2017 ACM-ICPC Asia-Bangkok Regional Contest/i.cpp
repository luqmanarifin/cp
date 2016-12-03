#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int h[N], p[N];
vector<int> edge[N];

vector<int> st;
int rmq[2 * N][20];
int lef[N], rig[N], n;

int lift[N][20], num[N];

void dfs(int now, int bef) {
  lef[now] = st.size();
  st.push_back(now);
  num[now] = 1;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    p[it] = now;
    h[it] = h[now] + 1;
    dfs(it, now);
    st.push_back(now);
    num[now] += num[it];
  }
  rig[now] = st.size() - 1;
}

void build_rmq() {
  for (int i = 0; i < st.size(); i++) rmq[i][0] = st[i];
  for (int j = 1; (1 << j) <= st.size(); j++) {
    for (int i = 0; i + (1 << j) <= st.size(); i++) {
      rmq[i][j] = (h[rmq[i][j-1]] < h[rmq[i+(1<<(j-1))][j-1]]? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1]);
    }
  }
}

void build_lift() {
  for (int i = 1; i <= n; i++) lift[i][0] = p[i];
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= n; i++) {
      lift[i][j] = lift[lift[i][j-1]][j-1];
    }
  }
}

int lca(int u, int v) {
  int l = min(lef[u], lef[v]);
  int r = max(rig[u], rig[v]);
  int g = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < N; i++) edge[i].clear();
    st.clear();
    
    int q, r;
    scanf("%d %d %d", &n, &q, &r);
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    dfs(1, 0);
    build_rmq();
    build_lift();
    printf("Case #%d:\n", tt);
    while (q--) {
      int s, u;
      scanf("%d %d", &s, &u);
      if (s == 0) {
        r = u;
      } else {
        int root = lca(r, u);
        if (r == u) {
          printf("%d\n", n);
        } else if (root == r || root != u) {
          printf("%d\n", num[u]);
        } else {
          int naik = abs(h[u] - h[r]) - 1;
          int now = r;
          for (int i = 0; i < 20; i++) {
            if (naik & (1 << i)) {
              now = lift[now][i];
            }
          }
          printf("%d\n", n - num[now]);
        }
      }
    }
  }

  return 0;
}
