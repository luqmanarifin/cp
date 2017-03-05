#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int inf = 2e9; 

int a[N], b[N], c[N], R[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d %d %d", a + i, b + i, c + i, R + i);
    int ans = inf;
    for (int mask = 1; mask < (1 << n) - 1; mask++) {
      int l = 1, r = 4e8;
      while (l < r) {
        int mid = (l + r) >> 1;
        int ai = inf, aj = inf, ak = inf;
        int bi = inf, bj = inf, bk = inf;
        for (int i = 0; i < n; i++) {
          if (mask & (1 << i)) {
            ai = min(ai, a[i] - R[i]);
            aj = min(aj, b[i] - R[i]);
            ak = min(ak, c[i] - R[i]);
          } else {
            bi = min(bi, a[i] - R[i]);
            bj = min(bj, b[i] - R[i]);
            bk = min(bk, c[i] - R[i]);
          }
        }
        bool can = 1;
        for (int i = 0; i < n; i++) {
          if (mask & (1 << i)) {
            if (a[i] + R[i] > ai + mid) can = 0;
            if (b[i] + R[i] > aj + mid) can = 0;
            if (c[i] + R[i] > ak + mid) can = 0;
          } else {
            if (a[i] + R[i] > bi + mid) can = 0;
            if (b[i] + R[i] > bj + mid) can = 0;
            if (c[i] + R[i] > bk + mid) can = 0;
          }
        }
        if (can) {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      ans = min(ans, l);
    }
    printf("Case #%d: %d\n", tt, ans);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
