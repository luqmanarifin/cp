#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    int satu = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1') {
          satu++;
        }
      }
    }
    int need = 2 * m + 2 * (n - 2);
    if (satu < need) {
      puts("-1");
      continue;
    }
    int ans = 0;
    for (int j = 0; j < m; j++) {
      if (s[0][j] == '0') ans++;
      if (s[n - 1][j] == '0') ans++;
    }
    for (int i = 1; i + 1 < n; i++) {
      if (s[i][0] == '0') ans++;
      if (s[i][m - 1] == '0') ans++;
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
