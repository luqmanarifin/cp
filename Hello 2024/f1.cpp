#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int A[N], B[N];
long long C[N];

struct segtree {
  segtree(int n) : n(n) {
    cap.assign(n << 2, 0);
    created.assign(n << 2, 0);
    passed.assign(n << 2, 0);
    build(1, 1, n);
  }
  void build(int p, int l, int r) {
    if (l == r) {
      auto cur = min(A[l], B[l]);
      created[p] = cur;
      cap[p] = B[l] - cur;
      passed[p] = A[l] - cur;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
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

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  
  for (int i = 1; i <= n; i++) scanf("%d", A + i);
  for (int i = 1; i <= n; i++) scanf("%d", B + i);
  for (int i = 1; i < n; i++) scanf("%lld", C + i);

  segtree seg(n);
  while (q--) {
    int p, x, y; long long z;
    scanf("%d %d %d %lld", &p, &x, &y, &z);
    seg.update(p, x, y, z);
    printf("%lld\n", seg.find());
  }

  return 0;
}
