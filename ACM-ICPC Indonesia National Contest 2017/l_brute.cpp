#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N][N];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int n = 5;

bool valid(int i, int j) {
  return 1 <= i && i <= n && 1 <= j && j <= n;
}

int main() {
  int p = 3, q = 3, now = -1, st = 0;
  a[p][q] = ++st;
  for (int i = 1; i < n * n; i++) {
    int ti = (p + dx[(now + 1) % 4]);
    int tj = (q + dy[(now + 1) % 4]);
    //printf("%d %d\n", ti, tj);
    if (valid(ti, tj) && a[ti][tj] == 0) {
      a[ti][tj] = ++st;
      p = ti;
      q = tj;
      now = (now + 1) % 4;
    } else {
      a[p + dx[now]][q + dy[now]] = ++st;
      p += dx[now];
      q += dy[now];
    }
  }
  /*
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)  {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  */
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] += a[i - 1][j];
      a[i][j] += a[i][j - 1];
      a[i][j] -= a[i - 1][j - 1];
    }
  }
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int r1, r2, c1, c2;
    scanf("%d %d %d %d %d", &n, &r1, &r2, &c1, &c2);
    printf("%d\n", a[r2][c2] - a[r2][c1-1] - a[r1-1][c2] + a[r1-1][c1-1]);
  }

  return 0;
}
