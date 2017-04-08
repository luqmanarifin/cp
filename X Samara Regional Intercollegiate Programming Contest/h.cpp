#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N][N];

int b[N][N], c[N][N], d[N][N], e[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      b[i][j] = c[i][j] = d[i][j] = e[i][j] = a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      b[i][j] = max(b[i][j], b[i - 1][j]);
      b[i][j] = max(b[i][j], b[i][j - 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      c[i][j] = max(c[i][j], c[i - 1][j]);
      c[i][j] = max(c[i][j], c[i][j + 1]);
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      d[i][j] = max(d[i][j], d[i + 1][j]);
      d[i][j] = max(d[i][j], d[i][j - 1]);
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      e[i][j] = max(e[i][j], e[i + 1][j]);
      e[i][j] = max(e[i][j], e[i][j + 1]);
    }    
  }
  int best = 2e9, p = -1, q = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int cur = max(max(b[i-1][j-1], c[i-1][j+1]), max(d[i+1][j-1], e[i+1][j+1]));
      //printf("%d %d cur %d\n", i, j, cur);
      if (cur < best) {
        best = cur;
        p = i;
        q = j;
      }
    }
  }
  printf("%d %d\n", p, q);
  return 0;
}
