#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

vector<pair<int, int>> edge[N];
int cnt[N], m;
long long tot;

void dfs(int now, int bef = -1) { 
  for (auto it : edge[now]) {
    int near = it.first;
    int cost = it.second;
    if (near == bef) continue;
    dfs(near, now);
    cnt[now] += cnt[near];
    tot += 2LL * cost * cnt[near] * (m - cnt[near]);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < N; i++) edge[i].clear();
    
    int n;
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      edge[u].emplace_back(v, w);
      edge[v].emplace_back(u, w);
    }
    for (int i = 0; i < m; i++) {
      int v;
      scanf("%d", &v);
      cnt[v]++;
    }
    tot = 0;
    dfs(1);
    long long den = 1LL * m * m;
    long long fpb = __gcd(tot, den);
    tot /= fpb;
    den /= fpb;
    printf("%lld %lld\n", tot, den);
  }

  return 0;
}
