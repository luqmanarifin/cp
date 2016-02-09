#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int rmq[N][20], h[N], par[N];
vector<int> edge[N];
int cnt, pos[N];
int dp[N], ans;

void dfs(int now, int p) {
  h[now] = h[p] + 1;
  par[now] = p;
  pos[now] = cnt;
  rmq[cnt++][0] = now;
  for(auto it : edge[now]) {
    if(it == p) continue;
    dfs(it, now);
    rmq[cnt++][0] = now;
  }
}

void build_rmq() {
  dfs(1, 0);
  for(int j = 1; (1 << j) <= cnt; j++) {
    for(int i = 0; i + (1 << j) <= cnt; i++) {
      rmq[i][j] = (h[rmq[i][j-1]] < h[rmq[i+(1<<(j-1))][j-1]]? rmq[i][j-1] : rmq[i+(1<<(j-1))][j-1]);
    }
  }
}

int find(int l, int r) {
  int g = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][g]] < h[rmq[r-(1<<g)+1][g]]? rmq[l][g] : rmq[r-(1<<g)+1][g];
}

int lca(int a, int b) {
  return find(min(pos[a], pos[b]), max(pos[a], pos[b]));
}

void finalize(int now, int p) {
  for(auto it : edge[now]) {
    if(it == p) continue;
    finalize(it, now);
    dp[now] += dp[it];
  }
  ans = max(ans, dp[now]);
}

int main() {
  freopen("maxflow.in","r",stdin);
  freopen("maxflow.out","w",stdout);
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  build_rmq();
  for(int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    int c = lca(u, v);
    dp[u]++;
    dp[par[c]]--;
    dp[v]++;
    dp[c]--;
  }
  finalize(1, 0);
  cout << ans << endl;
  return 0;
}
