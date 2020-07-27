#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int N = 1e6 + 5;

struct segtree {
  segtree(int n) : n(n) {
    num.resize(n << 2);
    for (int i = 0; i < num.size(); i++) num[i] = INF;
  }
  void update(int at, long long val) {
    update(1, 1, n, at, val);
  }
  void update(int p, int l, int r, int at, long long val) {
    if (l == r) {
      assert(at == l);
      num[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (at <= mid) {
      update(p + p, l, mid, at, val);
    }
    if (mid < at) {
      update(p + p + 1, mid + 1, r, at, val);
    }
    num[p] = min(num[p + p], num[p + p + 1]);
  }
  long long find(int l, int r) {
    return find(1, 1, n, l, r);
  }
  long long find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return num[p];
    if (r < ll || rr < l) return INF;
    int mid = (l + r) >> 1;
    long long ret = INF;
    ret = min(ret, find(p + p, l, mid, ll, rr));
    ret = min(ret, find(p + p + 1, mid + 1, r, ll, rr));
    return ret;
  }
  int n;
  vector<long long> num;
};

int c[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", c + i);
    segtree seg(n);
    seg.update(n, 0);
    for (int i = n - 1; i > 1; i--) {
      if (c[i] == 0) continue;
      int l = i + 1;
      int r = min(n, i + m);
      long long cost = c[i] + seg.find(l, r);
      seg.update(i, cost);
    }
    long long ans = seg.find(2, min(n, 1 + m));
    if (ans >= INF) ans = -1;
    printf("Case #%d: %lld\n", tt, ans);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
