#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

struct segtree {
  segtree(int n) : n(n) {
    cap.assign(n << 2, 0);
    created.assign(n << 2, 0);
    passed.assign(n << 2, 0);
  }
  void combine(int p, int l, int r) {
    auto cur = min(passed[p + p], cap[p + p + 1]);
    created[p] = created[p + p] + created[p + p + 1] + cur;
    cap[p] = cap[p + p] + cap[p + p + 1] - cur;
    passed[p] = passed[p + p] + passed[p + p + 1] - cur;
  }
  void update(int at, int a, int b, long long c) {
    update(1, 1, n, at, a, b, c);
  }
  void update(int p, int l, int r, int at, int a, int b, long long c) {
    if (l == r) {
      auto cur = min(a, b);
      created[p] = cur;
      cap[p] = b - cur;
      passed[p] = a - cur;
      return;
    }
    int mid = (l + r) >> 1;
    if (at <= mid) {
      update(p + p, l, mid, at, a, b, c);
    } else {
      update(p + p + 1, mid + 1, r, at, a, b, c);
    }
    combine(p, l, r);
  }
  long long find() {
    return created[1];
  }
  int n;
  vector<long long> cap, created, passed;
};

int a[N], b[N];
long long c[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  for (int i = 1; i < n; i++) scanf("%lld", c + i);

  // build
  segtree seg(n);
  for (int i = 1; i <= n; i++) seg.update(i, a[i], b[i], c[i]);

  while (q--) {
    int p, x, y; long long z;
    scanf("%d %d %d %lld", &p, &x, &y, &z);
    seg.update(p, x, y, z);
    printf("%lld\n", seg.find());
  }

  return 0;
}
