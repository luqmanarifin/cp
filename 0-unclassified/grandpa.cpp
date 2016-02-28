#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dp[N][N];
int a[N][N], n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int dfs(int x, int y) {
  if(dp[x][y] != -1) return dp[x][y];
  int& ret = dp[x][y] = 0;
  for(int i = 0; i < 4; i++) {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if(valid(tx, ty) && a[x][y] < a[tx][ty]) {
      ret += dfs(tx, ty);
    }
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        bool ada = 0;
        for(int k = 0; k < 4; k++) {
          int ti = i + dx[k];
          int tj = j + dy[k];
          if(valid(ti, tj) && a[i][j] < a[ti][tj]) {
            ada = 1;
          }
        }
        if(!ada) {
          dp[i][j] = 1;
        }
      }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        bool ada = 0;
        for(int k = 0; k < 4; k++) {
          int ti = i + dx[k];
          int tj = j + dy[k];
          if(valid(ti, tj) && a[i][j] > a[ti][tj]) {
            ada = 1;
          }
        }
        if(!ada) {
          ans += dfs(i, j);
        }
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
