#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

// node - status (1 bayar, 0 gratis, -1 gratis kabeh)
vector<pair<int, int>> edge[N];
vector<int> e;
int h[N], rmq[2 * N][20], p[N];

// 0 - turun dari tree, 1 - naik ke root
int dp[N][2];
long long use[N * 10], ans;

void dfs(int now, int prev) {
  p[now] = e.size();
  e.push_back(now);
  h[now] = h[prev] + 1;
  for(auto it : edge[now]) {
    if(it.first == prev) {
      continue;
    }
    dfs(it.first, now);
    e.push_back(now);
  }
}

void build_rmq() {
  for(int i = 0; i < e.size(); i++) {
    rmq[i][0] = e[i];
  }
  for(int j = 1; (1 << j) <= e.size(); j++) {
    for(int i = 0; i + (1 << j) <= e.size(); i++) {
      if(h[rmq[i][j - 1]] < h[rmq[i+(1<<(j-1))][j - 1]]) {
        rmq[i][j] = rmq[i][j - 1];
      } else {
        rmq[i][j] = rmq[i+(1<<(j-1))][j - 1];
      }
    }
  }
}

int find(int l, int r) {
  int t = __builtin_clz(r - l + 1) ^ 31;
  return h[rmq[l][t]] < h[rmq[r-(1<<t)+1][t]]? rmq[l][t] : rmq[r-(1<<t)+1][t];
}

int lca(int u, int v) {
  return find(min(p[u], p[v]), max(p[u], p[v]));
}

pair<int, int> compute(int now, int prev) {
  int up = dp[now][1], down = dp[now][0];
  for(auto it : edge[now]) {
    if(it.first == prev) {
      continue;
    }
    pair<int, int> ret = compute(it.first, now);
    if(it.second == 0) {
      ans += use[ret.first];
    } else if(it.second == 1) {
      ans += use[ret.second];
    }
    ans %= mod;
    up += ret.first;
    down += ret.second;
  }
  return make_pair(up, down);
}

int main() {
  use[0] = 1;
  for(int i = 1; i < N * 10; i++) {
    use[i] = use[i - 1] * 2 % mod;
  }
  for(int i = 0; i < N * 10; i++) {
    use[i]--;
    if(use[i] < 0) use[i] += mod;
  }
  
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n - 1; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(c == 0) {
      edge[a].emplace_back(b, -1);
      edge[b].emplace_back(a, -1);
    } else {
      edge[a].emplace_back(b, 0);
      edge[b].emplace_back(a, 1);
    }
  }
  dfs(1, 0);
  build_rmq();
  
  int k;
  scanf("%d", &k);
  int bef = 1;
  while(k--) {
    int now;
    scanf("%d", &now);
    int ca = lca(bef, now);
    dp[bef][1]++;
    dp[ca][1]--;
    dp[ca][0]--;
    dp[now][0]++;
    bef = now;
  }
  
  compute(1, 0);
  cout << ans << endl;
  return 0;
}
