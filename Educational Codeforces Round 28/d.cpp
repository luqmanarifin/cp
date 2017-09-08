#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int a[N][N], x[N * N], y[N * N], t[N * N];
int n, m, k, q;

bool rusak(int time) {
  memset(a, 0, sizeof(a));
  for (int i = 0; i < q; i++) {
    if (t[i] <= time) {
      a[x[i]][y[i]] = 1;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i) a[i][j] += a[i-1][j];
      if (j) a[i][j] += a[i][j-1];
      if (i && j) a[i][j] -= a[i-1][j-1];
    }
  }
  for (int i = k; i <= n; i++) {
    for (int j = k; j <= m; j++) {
      int cur = a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k];
      if (cur == k * k) {
        return 1;
      }
    }
  }
  return 0;
}  

int main() {
  scanf("%d %d %d %d", &n, &m, &k, &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d %d", x + i, y + i, t + i);
  }
  int l = 0, r = 1e9 + 5;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (rusak(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (l > 1e9 + 1) l = -1;
  cout << l << endl;
  return 0;
}
