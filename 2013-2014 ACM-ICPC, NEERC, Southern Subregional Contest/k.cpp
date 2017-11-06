#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int d[N], dp[N];
pair<int, int> dpi[N], dpd[N];
int pre[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", d+i);
  dpi[0] = {1, 1};
  dpd[0] = {1, -d[0]};
  pre[0] = 0;
  pair<pair<int, int>, int> lasti, lastd;
  lasti = {dpi[0], 0};
  lastd = {dpd[0], 0};
  for (int i = 1; i < n; i++) {
    int mi = min(lasti.first.first, lastd.first.first) + 1; 
    dpi[i] = {mi + 1, 1};
    dpd[i] = {mi + 1, -d[i]};
    dp[i] = mi+1;
    pre[i] = i;
    lasti.first.second++;
    lastd.first.second++;
    lastd.first.second = max(lastd.first.second, -d[i]);
    lasti = min(lasti, {dpi[i], i});
    lastd = min(lastd, {dpd[i], i});
    if (d[i] >= lasti.first.second) {
      if (lasti.first.first < dp[i])
        dp[i] = lasti.first.first, pre[i] = lasti.second;
    }
    else
      lasti = {dpi[i], i};
    if (-lastd.first.second >= 1) {
      if (lastd.first.first < dp[i])
        dp[i] = lastd.first.first, pre[i] = lastd.second;
    }
    else
      lastd = {dpd[i], i};
  }
  vector<pair<int, int> > ans;
  int now = n-1;
  while (now >= 0) {
    ans.emplace_back(pre[now], now);
    now = pre[now]-1;
  }
  printf("%d\n", ans.size());
  reverse(ans.begin(), ans.end());
  for (auto it : ans) {
    int l = it.first, r = it.second;
    bool ok = 1;
    for (int i = 0; i + l <= r; i++)
      ok &= d[l + i] > i;
    if (!ok) swap(l, r);
    printf("%d %d\n", l + 1, r + 1);
  }
  return 0;
}
