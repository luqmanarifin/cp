#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 1e9 + 7;

long long dp[N], tmp[N];
int cnt[N], n, cntr;
vector<tuple<int, int, int>> edge[N];
tuple<long long, int, int> f[N];

void dfs(int now, int p) {
  cnt[now] = 1;
  for(auto it : edge[now]) {
    int near, l, r;
    tie(near, l, r) = it;
    if(near == p) continue;
    dfs(near, now);
    cnt[now] += cnt[near];
  }
}

void build(int now, int p) {
  for(auto it : edge[now]) {
    int near, l, r;
    tie(near, l, r) = it;
    if(near == p) continue;
    build(near, now);
    f[++cntr] = make_tuple(1LL * cnt[near] * (n - cnt[near]), l, r);
  }
}

int main() {
  int s;
  scanf("%d %d", &n, &s);
  for(int i = 0; i < n - 1; i++) {
    int u, v, l, r;
    scanf("%d %d %d %d", &u, &v, &l, &r);
    edge[u].emplace_back(v, l, r);
    edge[v].emplace_back(u, l, r);
  }
  if(1LL * (n - 1) * (n - 1) > s) {
    puts("0");
    return 0;
  }
  dfs(1, 0);
  build(1, 0);
  
  dp[0] = 1;
  for(int i = 1; i < n; i++) {
    long long val; int l, r;
    tie(val, l, r) = f[i];
    for(int j = 0; j <= s; j++) {
      tmp[j] = 0;
    }
    for(int j = 0; j <= s; j++) {
      long long lef = j + val * l;
      long long rig = j + val * (r + 1);
      if(lef <= s) {
        tmp[lef] += dp[j];
        tmp[lef] %= mod;
      }
      if(rig <= s) {
        tmp[rig] -= dp[j];
        if(tmp[rig] < 0) tmp[rig] += mod;
      }
    }
    for(int j = 0; j <= s; j++) {
      if(j + val <= s) {
        tmp[j + val] += tmp[j];
        tmp[j + val] %= mod;
      }
    }
    for(int j = 0; j <= s; j++) {
      dp[j] = tmp[j];
    }
  }
  long long ans = 0;
  for(int j = 0; j <= s; j++) ans += dp[j];
  cout << ans % mod << endl;
  return 0;
}
