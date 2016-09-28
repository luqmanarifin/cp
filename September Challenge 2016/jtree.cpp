#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

struct segtree {
  segtree() {
    a.assign(N << 2, inf);
  }
  void set(int _n) {
    n = _n;
  }
  void update(int at, long long val) {
    update(1, 1, n, at, val);
  }
  void update(int p, int l, int r, int at, long long val) {
    if (l == r) {
      a[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (at <= mid) {
      update(p + p, l, mid, at, val);
    } else {
      update(p + p + 1, mid + 1, r, at, val);
    }
    a[p] = min(a[p + p], a[p + p + 1]);
  }
  long long find(int l, int r) {
    return find(1, 1, n, l, r);
  }
  long long find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return a[p];
    if (rr < l || r < ll) return inf;
    int mid = (l + r) >> 1;
    return min(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }
  vector<long long> a;
  int n;
};

vector<pair<int, int>> buy[N];
vector<int> edge[N];
segtree seg;
long long ans[N];

void dfs(int now, int h) {
  if (h > 1) {
    for (auto it : buy[now]) {
      int r = it.first;
      int c = it.second;
      ans[now] = min(ans[now], seg.find(max(1, h - r), h - 1) + c);
      seg.update(h, ans[now]);
    }
    //printf("%d %I64d\n", now, ans[now]);
  }
  for (auto it : edge[now]) {
    dfs(it, h + 1);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  seg.set(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[v].push_back(u);
  }
  while (m--) {
    int v, k, w;
    scanf("%d %d %d", &v, &k, &w);
    buy[v].emplace_back(k, w);
  }
  fill(ans, ans + N, inf);
  ans[1] = 0;
  seg.update(1, 0);
  dfs(1, 1);
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int v;
    scanf("%d", &v);
    printf("%lld\n", ans[v]);
  }
  return 0;
}
