#include "teleport.h"

#include <bits/stdc++.h>

using namespace std;

const int N = 1505;
const long long inf = 4e9;

int a[N][N], s[N][N];
long long d[N][N], u[N][N], t[N][N];
long long best = -inf;

long long getMaximumPoints(int n, int m, int K, vector<vector<int> > _s, vector<vector<int> > _a) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      s[i+1][j+1] = _s[i][j];
      a[i+1][j+1] = _a[i][j];
    }
  }
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
    t[i][j] = d[i][j] = u[i][j] = -inf;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 1) d[i][j] = 0;
      if (s[i][j]) t[i][j] = max(t[i][j], 0LL);
      for (int k = -1; k <= 1; k++) {
        t[i][j] = max(t[i][j], t[i-1][j+k]);
        d[i][j] = max(d[i][j], d[i-1][j+k]);
      }
      t[i][j] += a[i][j];
      d[i][j] += a[i][j];
      if (s[i][j]) best = max(best, t[i][j]);
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (i == n) u[i][j] = 0;
      for (int k = -1; k <= 1; k++) {
        u[i][j] = max(u[i][j], u[i+1][j+k]);
      }
      u[i][j] += a[i][j];
    }
  }
  long long direct = -inf, awal = -inf, akhir = -inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == n) direct = max(direct, d[i][j]);
      if (s[i][j]) {
        awal = max(awal, d[i][j]);
        akhir = max(akhir, u[i][j]);
      }
    }
  }
  long long ans = direct;
  if (K > 0) {
    ans = max(ans, awal + akhir);
    ans = max(ans, awal + akhir + best * (K - 1));
  }
  return ans;
}
