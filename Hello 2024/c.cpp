#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 2e5 + 5;

struct segtree {
  segtree(int n) : n(n) {
    num.assign(n << 2, inf);
    push.assign(n << 2, 0);
  }
  void update(int x, int val) {
    update(1, 1, n, x, val);
  }
  void update(int p, int l, int r, int at, int val) {
    lazy(p, l, r);
    if (at < l) return;
    if (at > r) return;
    if (l == r) {
      num[p] = min(num[p], val);
      return;
    }
    int mid = (l + r) >> 1;
    update(p + p, l, mid, at, val);
    update(p + p + 1, mid + 1, r, at, val);
    combine(p, l, r);
  }
  void add(int l, int r, int val) {
    add(1, 1, n, l, r, val);
  }
  void add(int p, int l, int r, int ll, int rr, int val) {
    lazy(p, l, r);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
      push[p] += val;
      lazy(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    add(p + p, l, mid, ll, rr, val);
    add(p + p + 1, mid + 1, r, ll, rr, val);
    combine(p, l, r);
  }
  int find(int l, int r) {
    return find(1, 1, n, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    lazy(p, l, r);
    int ret = inf;
    if (r < ll || rr < l) return ret;
    if (ll <= l && r <= rr) return num[p];
    int mid = (l + r) >> 1;
    ret = min(ret, find(p + p, l, mid, ll, rr));
    ret = min(ret, find(p + p + 1, mid + 1, r, ll, rr));
    combine(p, l, r);
    return ret;
  }
  void lazy(int p, int l, int r) {
    if (push[p] != 0) {
      num[p] += push[p];
      if (l < r) {
        push[p + p] += push[p];
        push[p + p + 1] += push[p];
      }
      push[p] = 0;
    }
  }
  void combine(int p, int l, int r) {
    num[p] = min(num[p + p], num[p + p + 1]);
  }
  int n;
  vector<int> num, push;
};

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    segtree seg(n);
    seg.update(n, 0);
    // for (int j = 1; j <= n; j++) printf("%d: %d\n", j, seg.find(j, j)); printf("\n");
    for (int i = 1; i < n; i++) {
      int down, up;
      if (a[i] > 1) {
        down = seg.find(1, a[i] - 1);
      }
      up = seg.find(a[i], n);

      // base, continue from before
      int add = (a[i-1] < a[i]);
      seg.add(1, n, add);

      // use anything but before
      if (a[i] > 1) {
        seg.update(a[i-1], down + 1);
      }
      seg.update(a[i-1], up);

      // for (int j = 1; j <= n; j++) printf("%d: %d\n", j, seg.find(j, j)); printf("\n");
    }
    printf("%d\n", seg.find(1, n));
  }
  return 0;
}
