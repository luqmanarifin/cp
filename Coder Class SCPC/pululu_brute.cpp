#include <bits/stdc++.h>

using namespace std;

const int N = 5;

int a[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int i, int j, int n, int m) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int solve(int n, int m) {
  int ans = 0;
  for (int mask = 0; mask < (1 << (n * m)); mask++) {
    memset(a, 0, sizeof(a));
    for (int i = 0; i < (n * m); i++) {
      if (mask & (1 << i)) {
        a[i / m][i % m] = 1;
      }
    }
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 0) continue;
        int ada = 0;
        for (int d = 0; d < 4; d++) {
          int px = i + dx[d];
          int py = j + dy[d];
          while (valid(px, py, n, m)) {
            if (a[px][py]) {
              ada++;
              break;
            }
            px += dx[d];
            py += dy[d];
          }
        }
        if (ada > 2) {
          ok = 0;
          break;
        }
      }
    }
    if (ok) {
      ans = max(ans, __builtin_popcount(mask));
    }
  }
  return ans;
}

int main() {
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      printf("%d %d: %d\n", i, j, solve(i, j));
    }
  }

  int n, m;
  scanf("%d %d", &n, &m);
  printf("%d\n", solve(n, m));
  return 0;
}
