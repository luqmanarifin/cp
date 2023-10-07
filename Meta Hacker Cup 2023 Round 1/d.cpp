#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int mod = 1e9 + 7;

struct segtree {
  segtree(int n, vector<int> a) : n(n), a(a) {
    x.assign(n << 2, 0);
    val[0].resize(n << 2);
    val[1].resize(n << 2);
    build(1, 0, n - 1);
  }
  void build(int p, int l, int r) {
    x[p] = 0;
    if (l == r) {
      val[0][p] = make_pair(a[l], -l);
      val[1][p] = make_pair(mod - a[l], -l);
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p);
    // printf("build %d %d %d: %d %d: %d %d\n", p, l, r, val[0][p].first, val[0][p].second, val[1][p].first, val[1][p].second);
  }
  pair<int, int> find(int l, int r) {
    return find(1, 0, n - 1, l, r);
  }
  pair<int, int> find(int p, int l, int r, int ll, int rr) {
    pair<int, int> ret = make_pair(-1, -1);
    push(p, l, r);
    if (r < ll || rr < l) return ret;
    if (ll <= l && r <= rr) {
      x[p]++;
      push(p, l, r);
      // printf("seg %d %d %d %d %d: %d %d\n", p, l, r, ll, rr, val[0][p].first, val[0][p].second);
      return val[0][p];
    }
    int mid = (l + r) >> 1;
    ret = max(ret, find(p + p, l, mid, ll, rr));
    ret = max(ret, find(p + p + 1, mid + 1, r, ll, rr));
    combine(p);
    // printf("com %d %d %d %d %d: %d %d\n", p, l, r, ll, rr, ret.first, ret.second);
    return ret;
  }
  pair<int, int> solve() {
    return val[0][1];
  }
  void push(int p, int l, int r) {
    if (x[p] > 0) {
      if (l < r) {
        x[p + p] += x[p];
        x[p + p + 1] += x[p];
      }
      if (x[p] % 2) {
        swap(val[0][p], val[1][p]);
      }
      x[p] = 0;
    }
  }
  void combine(int p) {
    for (int i = 0; i < 2; i++) {
      val[i][p] = max(val[i][p + p], val[i][p + p + 1]);
    }
  }
  int n;
  vector<int> x, a;
  vector<pair<int, int>> val[2];
};

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      a.push_back(v);
    }
    segtree seg(n, a);
    int q;
    scanf("%d", &q);
    long long ans = 0;
    while (q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      l--; r--;
      seg.find(l, r);
      auto cur = seg.solve();
      ans += (-cur.second) + 1;
      // printf("add %d %d\n", (-cur.second) + 1, cur.first);
    }
    printf("Case #%d: %lld\n", tt, ans);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
