#include <bits/stdc++.h>

using namespace std;

const double inf = 1e18;
const int N = 1005;

#define ld long double

// peppercorn - dollar
ld a[N][N], b[N][N];
int sel[N][N], buy[N][N];

int main() {
  long long d;
  int n, m;
  scanf("%d %d %lld", &n, &m, &d);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      scanf("%d %d", &sel[i][j], &buy[i][j]);
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      a[i][j] = b[i][j] = -inf;
    }
  }
  for(int i = 0; i < N; i++) {
    a[i][0] = d;
    b[i][0] = 0;
  }
  for(int j = 1; j <= m; j++) {
    for(int i = 1; i <= n; i++) {
      for(int c = -1; c <= 1; c++) {
        a[i][j] = max(a[i + c][j - 1], a[i][j]);
        b[i][j] = max(b[i + c][j - 1], b[i][j]);
      }
      a[i][j] = max(a[i][j], b[i][j - 1] * buy[i][j]);
      b[i][j] = max(b[i][j], a[i][j - 1] / sel[i][j]);
      if(a[i][j] > inf) {
        puts("Quintillionnaire");
        return 0;
      }
    }
  }
  ld ans = -inf;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, a[i][m]);
  }
  printf("%.15f\n", (double) ans);
  return 0;
}
