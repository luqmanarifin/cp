#include <bits/stdc++.h>

using namespace std;

const int N = 8e5 + 5;
const int K = 25;
const long long mod = 1e9 + 7;

vector<pair<int, int>> edge[N]; // index - capacity

int d[N][K], u[N][K], par[N], sz[N], pcap[N];

void upd(int& at, int val) {
  at = max(at, val);
}

void dfs(int now, int bef) {
  for (int j = 0; j < K; j++) {
    d[now][j] = 1;
  }
  for (auto it : edge[now]) {
    int near, cap;
    tie(near, cap) = it;
    if (near == bef) continue;
    pcap[near] = cap;
    dfs(near, now);

    for (int j = 0; j < K; j++) {
      if (cap >= j) {
        d[now][j] += d[near][j];
      }
    }
  }
  // printf("d %d: ", now); for (int j = 1; j < 10; j++) printf("%d ", d[now][j]); printf("\n");
}

void reverse(int now, int bef) {
  for (auto it : edge[now]) {
    int near, cap;
    tie(near, cap) = it;
    if (near == bef) continue;
    for (int j = 0; j < K; j++) {
      u[near][j] = d[now][j];
      if (pcap[now] >= j) {
        u[near][j] += u[now][j];
      }
      if (cap >= j) {
        u[near][j] -= d[near][j];
      }
    }

    reverse(near, now);
  }
  // printf("u %d: ", now); for (int j = 1; j < 10; j++) printf("%d ", u[now][j]); printf("\n");
}

int find(int u) {
  return par[u] = par[u] == u? u : find(par[u]);
}

long long merge(int u, int v) {
  if (find(u) == find(v)) return 0;
  u = find(u); v = find(v);
  long long ret = 1LL * sz[u] * sz[v] % mod;
  par[u] = v;
  sz[v] += sz[u];
  return ret;
}

void norm(long long& val) {
  val %= mod;
  if (val < 0) val += mod;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(d, 0, sizeof(d));
    memset(u, 0, sizeof(u));
    for (int i = 0; i < N; i++) {
      edge[i].clear();
    }
    for (int i = 0; i < N; i++) par[i] = i, sz[i] = 1;

    int n;
    scanf("%d", &n);
    vector<tuple<int, int, int>> edges;
    for (int i = 1; i < n; i++) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      edge[u].emplace_back(v, c);
      edge[v].emplace_back(u, c);
      edges.emplace_back(c, u, v);
    }
    dfs(1, 0);
    reverse(1, 0);

    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    long long all = 0;
    for (auto it : edges) {
      int c, u, v;
      tie(c, u, v) = it;
      long long ret = merge(u, v);
      all += ret * c;
      all %= mod;
    }
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
      long long rem = 0;
      for (int j = pcap[i]; j >= 1; j--) {
        long long mul = 1LL * d[i][j] * u[i][j] % mod;
        if (j < pcap[i]) {
          mul -= 1LL * d[i][j+1] * u[i][j+1] % mod;
        }
        rem += j * mul;
        norm(rem);
      }
      ans *= (all - rem);
      norm(ans);
    }
    cerr << tt << " done!" << endl; 
    printf("Case #%d: %lld\n", tt, ans);
  }

  return 0;
}
