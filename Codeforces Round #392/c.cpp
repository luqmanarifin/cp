#include <bits/stdc++.h>

using namespace std;

const int N = 105;

long long a[N][N];

int main() {
  int n, m, x, y;
  long long k;
  scanf("%d %d %I64d %d %d", &n, &m, &k, &x, &y);
  //printf("%d %d %I64d %d %d\n", n, m, k, x, y);
  //puts("cok");
  long long round = (n == 1? 1 : 2 * n - 2) * m;
  long long num_rounds = k / round;
  long long rem_round = k % round;
  long long maxi = -1e18;
  long long mini = 1e18;
  long long sergey = 0;
  //puts("asu");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      //printf("%d %d\n", i, j);
      a[i][j] = (1 + (1 < i && i < n)) * num_rounds;
    }
  }
 // puts("cok2");
  int pt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pt++;
      if (pt <= rem_round) {
        a[i][j]++;
      }
    }
  }
  //puts("cok3");
  for (int i = n - 1; i > 1; i--) {
    for (int j = 1; j <= m; j++) {
      pt++;
      if (pt <= rem_round) {
        a[i][j]++;
      }
    }
  }
  //puts("cok4");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      maxi = max(maxi, a[i][j]);
      mini = min(mini, a[i][j]);
    }
  }
  sergey = a[x][y];
  printf("%I64d %I64d %I64d\n", maxi, mini, sergey);
  return 0;
}
