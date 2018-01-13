#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int par[N], a[N];
long long sum[N], cnt[N];
vector<int> edge[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return;
  par[u] = v;
  sum[v] += sum[u];
  cnt[v] += cnt[u];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  vector<pair<int, int>> all;
  for (int i = 1; i <= n; i++) {
    all.emplace_back(a[i], i);
    par[i] = -1;
    sum[i] = a[i];
    cnt[i] = 1;
  }
  sort(all.begin(), all.end());
  long long ans = 0;
  for (auto it : all) {
    int now = it.second;
    long long tot_cnt = 1;
    vector<int> num = {1};
    for (auto it : edge[now]) {
      if (par[it] == -1) continue;
      num.push_back(cnt[find(it)]);
      tot_cnt += cnt[find(it)];
    }
    for (auto it : num) {
      ans += it * (tot_cnt - it) * a[now];
    }
    par[now] = now;
    for (auto it : edge[now]) if (par[it] != -1) merge(it, now);
  }
  //cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    par[i] = -1;
    sum[i] = a[i];
    cnt[i] = 1;
  }
  reverse(all.begin(), all.end());
  for (auto it : all) {
    int now = it.second;
    long long tot_cnt = 1;
    vector<int> num = {1};
    for (auto it : edge[now]) {
      if (par[it] == -1) continue;
      num.push_back(cnt[find(it)]);
      tot_cnt += cnt[find(it)];
    }
    for (auto it : num) {
      ans -= it * (tot_cnt - it) * a[now];
    }
    par[now] = now;
    for (auto it : edge[now]) if (par[it] != -1) merge(it, now);
  }
  cout << ans / 2 << endl;
  return 0;
}
