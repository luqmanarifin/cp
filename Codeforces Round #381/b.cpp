#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long bit[N], sum[N];

void add_bit(int i, long long v, long long s) {
  for (; i < N; i |= i + 1) {
    bit[i] += v;
    sum[i] += s;
  }
}

void add(int l, int r, long long val) {
//printf("%d %d %I64d\n", l, r, val);
  add_bit(l, val, -1LL * (l - 1) * val);
  add_bit(r + 1, -val, 1LL * r * val);
}

long long find_bit(int i) {
  long long at = i, v = 0, s = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    v += bit[i];
    s += sum[i];
  }
  return v * at + s;
}

long long find(int l, int r) {
  return find_bit(r) - find_bit(l - 1);
}

long long a[N], h[N], dist[N];
vector<pair<int, int>> edge[N];
long long ans[N];

void dfs(int now) {
  //printf("%d\n", now);
  int p = lower_bound(dist, dist + h[now], dist[h[now]] - a[now]) - dist;
  if (p < h[now]) {
    add(p, h[now] - 1, 1);
  }
  for (auto it : edge[now]) {
    int near = it.first;
    int cost = it.second;
    h[near] = h[now] + 1;
    dist[h[near]] = dist[h[now]] + cost;
    dfs(near);
  }
  //printf("%d done\n", now);
  ans[now] = find(h[now], h[now]);
  //printf("%d find ok\n", now);
  add(h[now], h[now], -ans[now]);
  //printf("exit %d\n", now);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
  for (int i = 2; i <= n; i++) {
    int v, w;
    scanf("%d %d", &v, &w);
    edge[v].emplace_back(i, w);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) printf("%I64d ", ans[i]);
  return 0;
}
