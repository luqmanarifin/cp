#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int inf = 1e9;

char s[N][N];
bool a[N][N];
int n, m;

int di[] = {0, 0, 1, -1, 0};
int dj[] = {1, -1, 0, 0, 0};

int main() {
  while (scanf("%d %d", &n, &m) == 2) {
    if (n == 0 && m == 0) break;
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    int ans = inf;
    for (int mask = 0; mask < (1 << m); mask++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          a[i][j] = (s[i][j] != '.');
        }
      }
      int cur = 0;
      for (int j = 0; j < m; j++) {
        if (mask & (1 << j)) {
          a[0][j] ^= 1;
          if (j) a[0][j - 1] ^= 1;
          a[0][j + 1] ^= 1;
          a[1][j] ^= 1;
          cur++;
        }
      }
      for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (a[i - 1][j]) {
            a[i][j] ^= 1;
            if (j) a[i][j - 1] ^= 1;
            a[i][j + 1] ^= 1;
            if (i) a[i - 1][j] ^= 1;
            a[i + 1][j] ^= 1;
            cur++;
          }
        }
      }
      bool nice = 1;
      for (int j = 0; j < m; j++) if (a[n - 1][j]) {
        nice = 0;
      }
      if (nice) {
        ans = min(ans, cur);
      }
    }
    if (ans == inf) {
      puts("Damaged billboard.");
    } else {
      printf("You have to tap %d tiles.\n", ans);
    }
  }
  
  return 0;
}