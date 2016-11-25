#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    bool ok = 0;
    for (int j = 0; j < m; j++) {
      ok |= a[i][j];
      if (a[i][j] == 0) ans += ok;
    }
  }
  for (int i = 0; i < n; i++) {
    bool ok = 0;
    for (int j = m - 1; j >= 0; j--) {
      ok |= a[i][j];
      if (a[i][j] == 0) ans += ok;
    }
  }
  for (int j = 0; j < m; j++) {
    bool ok = 0;
    for (int i = 0; i < n; i++) {
      ok |= a[i][j];
      if (a[i][j] == 0) ans += ok;
    }
  }
  for (int j = 0; j < m; j++) {
    bool ok = 0;
    for (int i = n - 1; i >= 0; i--) {
      ok |= a[i][j];
      if (a[i][j] == 0) ans += ok;
    }
  }
  cout << ans << endl;
  return 0;
}
