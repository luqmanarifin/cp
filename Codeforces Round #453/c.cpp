
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int LOG = 21;

vector<int> edge[N];
int par[N], p[N], hop[N][LOG], mn[N][LOG], mx[N][LOG], h[N], til[N];
bool vis[N];
long long s[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  par[find(u)] = find(v);
}

void dfs(int now, int bef) {
  vis[now] = 1;
  if (bef != 0) {
    p[now] = bef;
    h[now] = h[bef] + 1;
  }
  for (auto it : edge[now]) if (it != bef) dfs(it, now);
}

pair<int, int> solve(int u, int v) {
  int mini = min(u, v);
  int maxi = max(u, v);
  if (h[u] > h[v]) swap(u, v);
  // samain tinggi
  for (int i = LOG - 1; i >= 0 && h[u] < h[v]; i--) {
    if (h[u] <= h[v] - (1 << i)) {
      mini = min(mini, mn[v][i]);
      maxi = max(maxi, mx[v][i]);
      v = hop[v][i];
    }
  }
  // naik ke atas bareng
  for (int i = LOG - 1; i >= 0 && p[u] != p[v]; i--) {
    if (hop[u][i] != hop[v][i]) {
      mini = min(mini, mn[u][i]);
      mini = min(mini, mn[v][i]);
      maxi = max(maxi, mx[u][i]);
      maxi = max(maxi, mx[v][i]);
      u = hop[u][i];
      v = hop[v][i];
    }
  }
  if (u != v) {
    mini = min(mini, p[u]);
    maxi = max(maxi, p[v]);
  }
  return make_pair(mini, maxi);
}

long long sum(int n) {
  return 1LL * n * (n + 1) / 2;
}

long long sum(int l, int r) {
  if (l > r) return 0;
  return sum(r) - sum(l - 1);
}

long long sum_til(int l, int r) {
  if (l > r) return 0;
  return s[r] - s[l - 1];
}

int main() {
  for (int i = 0; i < N; i++) par[i] = i;
  vector<pair<int, int>> unused;
  
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (find(u) != find(v)) {
      edge[u].push_back(v);
      edge[v].push_back(u);
      merge(u, v);
    } else {
      unused.emplace_back(u, v);
    }
  }
  for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0);
  //puts("dfs done");
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < LOG; j++) {
      mn[i][j] = N;
      mx[i][j] = -N;
    }
  }
  for (int i = 1; i <= n; i++) {
    hop[i][0] = p[i];
    mn[i][0] = p[i];
    mx[i][0] = p[i];
  }
  for (int j = 1; j < LOG; j++) {
    for (int i = 1; i <= n; i++) {
      hop[i][j] = hop[hop[i][j-1]][j-1];
      mn[i][j] = min(mn[i][j-1], mn[hop[i][j-1]][j-1]);
      mx[i][j] = max(mx[i][j-1], mx[hop[i][j-1]][j-1]);
    }
  }
  fill(til, til + N, N);
  for (auto it : unused) {
    int u = it.first;
    int v = it.second;
    auto ret = solve(u, v);
    til[ret.first] = min(til[ret.first], ret.second - 1);
  }
  for (int i = n; i >= 1; i--) til[i] = min(til[i], til[i + 1]);
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + til[i];
  for (int i = 2; i <= n; i++) assert(til[i-1] <= til[i]);
  //for (int i = 1; i <= n; i++) printf("%d ", til[i]); printf("\n");
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    int p = lower_bound(til + l, til + r + 1, r) - til;
    long long ans = 0;
    ans += sum_til(l, p - 1) - sum(l, p - 1) + (p - l); 
    ans += 1LL * r * (r - p + 1) - sum(p, r) + (r - p + 1);
    printf("%lld\n", ans);
  }
  return 0;
}
