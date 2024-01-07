#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const long long inf = 2e18;

int A[N], B[N];
long long C[N];

void upd(long long& a, long long b) {
  a = min(a, b);
}

struct segtree {
  segtree(int n) : n(n) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        val[i][j].assign(n << 2, inf);
      }
    }
  }
  void combine(int p, int l, int r) {
    int mid = (l + r) >> 1;
    for (int a = 0; a < 2; a++) {
      for (int d = 0; d < 2; d++) {
        val[a][d][p] = inf;
        for (int b = 0; b < 2; b++) {
          for (int c = 0; c < 2; c++) {
            long long cur = val[a][b][p + p] + val[c][d][p + p + 1];
            if (b == 1 && c == 0) {
              cur += C[mid];
            }
            upd(val[a][d][p], cur);
          }
        }
      }
    }
  }
  void update(int at) {
    update(1, 1, n, at);
  }
  void update(int p, int l, int r, int at) {
    if (l == r) {
      val[0][0][p] = A[l];
      val[1][1][p] = B[l];
      val[0][1][p] = inf;
      val[1][0][p] = inf;
      return;
    }
    int mid = (l + r) >> 1;
    if (at <= mid) {
      update(p + p, l, mid, at);
    } else {
      update(p + p + 1, mid + 1, r, at);
    }
    combine(p, l, r);
  }
  long long find() {
    return min(min(val[0][0][1], val[0][1][1]), min(val[1][0][1], val[1][1][1]));
  }
  int n;
  vector<long long> val[2][2];
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  
  for (int i = 1; i <= n; i++) scanf("%d", A + i);
  for (int i = 1; i <= n; i++) scanf("%d", B + i);
  for (int i = 1; i < n; i++) scanf("%lld", C + i);

  segtree seg(n);
  for (int i = 1; i <= n; i++) seg.update(i);
  while (q--) {
    int p, x, y; long long z;
    scanf("%d %d %d %lld", &p, &x, &y, &z);
    A[p] = x;
    B[p] = y;
    C[p] = z;
    seg.update(p);
    printf("%lld\n", seg.find());
  }

  return 0;
}
