#include <bits/stdc++.h>

using namespace std;

const int N = 505;

char s[N][N];
int a[N][N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int dx = 0; dx < 2; dx++) {
        for (int dy = 0; dy < 2; dy++) {
          if (s[i + dx][j + dy] == 'B') {
            a[i][j] ^= 1;
          }
        }
      }
      tot += a[i][j];
    }
  }
  int ans = tot;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i][j] && a[n][j] && a[i][m] && a[n][m]) {
        ans = min(ans, tot - 1);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
