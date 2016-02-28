#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9 + 1e8;
const int N = 2e5 + 5;

int a[2005][205];
int dp[2005][205][2], sum[2005][205];
int d[4005][4005];
int qx[N], qy[N];
int cnt[4005];

int dist(int x, int y, int p, int q) {
  int ret = inf;
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      ret = min(ret, dp[x][y][i] + d[x*2+i][p*2+j] + dp[p][q][j]);
    }
  }
  if(p == x) {
    ret = min(ret, sum[x][max(y, q)] - sum[x][min(y, q) - 1]);
  }
  return ret;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      sum[i][j] = sum[i][j - 1] + a[i][j];
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 2; j <= m; j++) {
      dp[i][j][0] = dp[i][j - 1][0] + a[i][j];
    }
    for(int j = m - 1; j >= 1; j--) {
      dp[i][j][1] = dp[i][j + 1][1] + a[i][j];
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < 2; j++) {
      queue<int> q;
      int* dist = d[i*2+j];
      for(int k = 1; k <= n; k++) {
        dist[k*2] = dist[k*2+1] = inf;
      }
      dist[i*2+j] = a[i][j? m : 1];
      q.push(i*2 + j);
      cnt[i*2 + j]++;
      while(!q.empty()) {
        int val = q.front();
        int x = val / 2;
        int y = val % 2;
        int c = dist[val];
        q.pop();
        cnt[val]--;
        if(x < n) {
          int nc = c + a[x + 1][y? m : 1];
          int at = (x+1)*2 + y;
          if(nc < dist[at]) {
            dist[at] = nc;
            if(cnt[at] == 0) {
              q.push(at);
              cnt[at]++;
            }
          }
        }
        if(x > 1) {
          int nc = c + a[x - 1][y? m : 1];
          int at = (x-1)*2 + y;
          if(nc < dist[at]) {
            dist[at] = nc;
            if(cnt[at] == 0) {
              q.push(at);
              cnt[at]++;
            }
          }
        }
        int nc = c + (y? dp[x][1][1] : dp[x][m][0]);
        int at = x*2 + (y^1);
        if(nc < dist[at]) {
          dist[at] = nc;
          if(cnt[at] == 0) {
            q.push(at);
            cnt[at]++;
          }
        }
      }
    }
  }
  int q;
  qx[0] = 1; qy[0] = 1;
  scanf("%d", &q);
  
  long long ans = a[1][1];
  for(int i = 1; i <= q; i++) {
    scanf("%d %d", qx + i, qy + i);
    ans += dist(qx[i - 1], qy[i - 1], qx[i], qy[i]) - a[qx[i-1]][qy[i-1]];
  }
  cout << ans << endl;
  return 0;
}