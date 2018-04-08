#include <bits/stdc++.h>

using namespace std;

const int offset = 2010;
const int N = 4100;

int a[5][N][N];
int got[] = {6, 12, 3, 9, 15};

bool valid(int i, int j) {
  return 0 <= i && i < N && 0 <= j && j < N;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char c;
    int x, y, d;
    scanf(" %c %d %d %d", &c, &x, &y, &d);
    x += offset;
    y += offset;
    if (c == 'A') {
      a[4][x - d/2][y - d/2]++;
      a[4][x - d/2][y + d/2]--;
      a[4][x + d/2][y - d/2]--;
      a[4][x + d/2][y + d/2]++;
    } else {
      a[0][x - d/2][y - 1]++;
      a[0][x][y + d/2 - 1]--;
      a[0][x][y - d/2 - 1]--;
      a[0][x + d/2][y - 1]++;
      
      a[1][x - d/2][y]++;
      a[1][x][y + d/2]--;
      a[1][x][y - d/2]--;
      a[1][x + d/2][y]++;
      
      a[2][x - d/2 + 1][y - 1]++;
      a[2][x + 1][y + d/2 - 1]--;
      a[2][x + 1][y - d/2 - 1]--;
      a[2][x + d/2 + 1][y - 1]++;
      
      a[3][x - d/2 + 1][y]++;
      a[3][x + 1][y + d/2]--;
      a[3][x + 1][y - d/2]--;
      a[3][x + d/2 + 1][y]++;
    }
  }
  //~ puts("done baca");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (valid(i, j - 1)) {
        a[4][i][j] += a[4][i][j - 1];
      }
      if (valid(i - 1, j)) {
        a[4][i][j] += a[4][i - 1][j];
      }
      if (valid(i - 1, j - 1)) {
        a[4][i][j] -= a[4][i - 1][j - 1];
      }
    }
  }
  //~ puts("dp full");
  for (int k = 0; k < 4; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (valid(i - 1, j - 1)) {
          a[k][i][j] += a[k][i - 1][j - 1];
        }
        if (valid(i - 1, j + 1)) {
          a[k][i][j] += a[k][i - 1][j + 1];
        }
        if (valid(i - 2, j)) {
          a[k][i][j] -= a[k][i - 2][j];
        }
      }
    }
  }
  //~ puts("dp parsial");
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int cur = 0;
      for (int k = 0; k <= 4; k++) {
        if (a[k][i][j]) {
          cur |= got[k];
        }
      }
      ans += __builtin_popcount(cur);
    }
  }
  printf("%.2f\n", (double) ans / 4);
  return 0;
}
