#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const long long inf = 1e18;

int h[N][N];
long long a[N], b[N];
bool oka[N][2][2], okb[N][2][2];
long long dpa[N][2], dpb[N][2];

void upd(long long& x, long long y) {
  x = min(x, y);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%d", &h[i][j]);
      }
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          oka[i][j][k] = okb[i][j][k] = 1;
        }
      }
    }
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    for (int i = 0; i < n; i++) scanf("%lld", b + i); 
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (h[i][j] == h[i-1][j]) {
          oka[i][0][0] = oka[i][1][1] = 0;
        }
        if (h[i][j] == h[i-1][j] + 1) {
          oka[i][1][0] = 0;
        }
        if (h[i][j] + 1 == h[i-1][j]) {
          oka[i][0][1] = 0;
        }
      }
    }

    for (int j = 1; j < n; j++) {
      for (int i = 0; i < n; i++) {
        if (h[i][j] == h[i][j-1]) {
          okb[j][0][0] = okb[j][1][1] = 0;
        }
        if (h[i][j] == h[i][j-1] + 1) {
          okb[j][1][0] = 0;
        }
        if (h[i][j] + 1 == h[i][j-1]) {
          okb[j][0][1] = 0;
        }
      }
    }
    for (int i = 0; i <= n; i++) {
      dpa[i][0] = dpa[i][1] = inf;
      dpb[i][0] = dpb[i][1] = inf;
    }
    dpa[0][0] = 0;
    dpa[0][1] = a[0];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          if (oka[i][j][k]) {
            long long cost = (k? a[i] : 0);
            upd(dpa[i][k], dpa[i-1][j] + cost);
          }
        }
      }
    }
    dpb[0][0] = 0;
    dpb[0][1] = b[0];
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          if (okb[i][j][k]) {
            long long cost = (k? b[i] : 0);
            upd(dpb[i][k], dpb[i-1][j] + cost);
          }
        }
      }
    }
    long long ans = min(dpa[n-1][0], dpa[n-1][1]) + min(dpb[n-1][0], dpb[n-1][1]);
    if (ans >= inf) ans = -1;
    printf("%lld\n", ans);
  }

  return 0;
}
