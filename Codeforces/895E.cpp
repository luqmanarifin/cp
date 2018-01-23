#include <bits/stdc++.h>

using namespace std;

struct item {
  item() {}
  item (int v, int len) : len(len) {
    x = (double) v * len;
    a = b = push = 0;
  }
  double x, a, b;
  int len;
  bool push;
};

struct segtree {
  segtree(vector<int> a) : a(a), n(a.size()) {
    num.resize(n << 2);
    build(1, 0, n - 1);
  }
  void build(int p, int l, int r) {
    num[p] = item(a[l], r - l + 1);
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
  }
  void inject(int p, double c, double d) {
    double a = num[p].a;
    double b = num[p].b;
    int len = num[p].len;
    num[p].a = -(a*c - a - c);
    num[p].b = ((1-c)*a*b + c*d) / num[p].a;
    //printf("inject %d %.3f %.3f: bef %d %.3f %.3f %.3f %.3f\n", p, num[p].a, num[p].b, len, a, b, c, d);
  }
  void relax(int p, int l, int r) {
    if (num[p].push) {
      if (l < r) {
        inject(p + p, num[p].a, num[p].b);
        inject(p + p + 1, num[p].a, num[p].b);
        num[p + p].push = 1;
        num[p + p + 1].push = 1;
      }
      //printf("relax %d %d %d: %.3f %.3f %.3f\n", p, l, r, num[p].x, num[p].a, num[p].b);
      num[p].x = (1 - num[p].a) * num[p].x + num[p].a * num[p].b * num[p].len;
      num[p].a = num[p].b = 0;
      num[p].push = 0;
    }
  }
  void combine(int p, int l, int r) {
    num[p].x = num[p + p].x + num[p + p + 1].x;
  }
  
  void update(int l, int r, double c, double d) {
    update(1, 0, n - 1, l, r, c, d);
  }
  void update(int p, int l, int r, int ll, int rr, double c, double d) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      inject(p, c, d);
      num[p].push = 1;
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr, c, d);
    update(p + p + 1, mid + 1, r, ll, rr, c, d);
    combine(p, l, r);
  }
  double find(int l, int r) {
    return find(1, 0, n - 1, l, r);
  }
  double find(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if (ll <= l && r <= rr) return num[p].x;
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    double ret = find(p + p, l, mid, ll, rr) + find(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
    return ret;
  }
  
  vector<item> num;
  vector<int> a;
  int n;
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  segtree seg(a);
  while (q--) {
    int t, l, r, l1, r1, l2, r2;
    scanf("%d", &t);
    if (t == 2) {
      scanf("%d %d", &l, &r);
      l--; r--;
      printf("%.15f\n", seg.find(l, r));
    } else {
      scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
      l1--; r1--; l2--; r2--;
      double lef = seg.find(l1, r1) / (r1 - l1 + 1);
      double rig = seg.find(l2, r2) / (r2 - l2 + 1);
      //printf("lef %.3f rig %.3f\n", lef, rig);
      seg.update(l1, r1, 1. / (r1 - l1 + 1), rig);
      seg.update(l2, r2, 1. / (r2 - l2 + 1), lef);
    }
    //for (int i = 0; i < n; i++) printf("%.3f ", seg.find(i, i)); printf("\n");
  }
  return 0;
}
