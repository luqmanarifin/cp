
#include <bits/stdc++.h>

using namespace std;

const int N = 305;

int a[N][N], lef[N][N], dow[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        lef[i][j] = lef[i][j-1] + 1;
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = n; i >= 1; i--) {
      if (a[i][j]) {
        dow[i][j] = dow[i + 1][j] + 1;
      }
    }
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (lef[i][j] > 1 && dow[i][j] > 1) {
        ans = max(ans, lef[i][j] + dow[i][j] - 1);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
