#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m;

long long dp[N][N][2];
int a[N][N];
long long ans;

long long get(long long u, long long v) {
  if (u && v) return u + v - 1;
  return u + v;
}

void update(int i, int j, int k, long long val) {
  long long old = get(dp[i][j][k^1], dp[i][j][k]);
  long long bar = get(dp[i][j][k^1], val);
  ans += bar - old;
  dp[i][j][k] = val;
}

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void flip(int x, int y) {
  if (a[x][y] == 0) {
    a[x][y] ^= 1;
    update(x, y, 0, 0);
    update(x, y, 1, 0);
    for (int k = 0; k < 2; k++) {
      for (int step = 1; ; step++) {
        int p = x - step / 2 - (step % 2 && k == 1);
        int q = y - step / 2 - (step % 2 && k == 0);
        if (!valid(p, q)) break;
        if (a[p][q]) break;
        int c = (step % 2? 1 : 0) ^ (!k);
        update(p, q, c, step);
      }
    }
  } else {
    a[x][y] ^= 1;
    for (int k = 0; k < 2; k++) {
      int add = 1;
      for (int step = 1; ; step++) {
        int p = x + step / 2 + (step % 2 && k == 0);
        int q = y + step / 2 + (step % 2 && k == 1); 
        if (!valid(p, q)) break;
        if (a[p][q]) break;
        add = step + 1;
      }
      for (int step = 0; ; step++) {
        int p = x - step / 2 - (step % 2 && k == 1);
        int q = y - step / 2 - (step % 2 && k == 0);
        if (!valid(p, q)) break;
        if (a[p][q]) break;
        int c = (step % 2? 1 : 0) ^ (!k);
        update(p, q, c, dp[p][q][c] + add);
      }
    }
  }
}

void init() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 2; k++) {
        int l = 0, r = 2005;
        while (l < r) {
          int mid = (l + r + 1) >> 1;
          int p = i + mid / 2 + (mid % 2 && k == 1);
          int q = j + mid / 2 + (mid % 2 && k == 0);
          if (!valid(p, q)) {
            r = mid - 1;
          } else {
            l = mid;
          }
        }
        update(i, j, k, l + 1);
      }
    }
  }
}


int main() {
  int q;
  scanf("%d %d %d", &n, &m, &q);
  init();
  // for (int k = 0; k < 2; k++) {
  //   printf("%d:\n", k);
  //   for (int i = 0; i < n; i++) {
  //     for (int j = 0; j < m; j++) {
  //       printf("%d ", dp[i][j][k]);
  //     }
  //     printf("\n");
  //   }
  // }
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    flip(x, y);

    // printf("\n");
    // for (int k = 0; k < 2; k++) {
    //   printf("%d:\n", k);
    //   for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //       printf("%d ", dp[i][j][k]);
    //     }
    //     printf("\n");
    //   }
    // }
    printf("%lld\n", ans);
  }
  return 0;
}
