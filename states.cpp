#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e8;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int dp[N][N][3];
char s[N][N];
int n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

bool nice(int i, int j) {
  return '1' <= s[i][j] && s[i][j] <= '3';
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for(char it = '1'; it <= '3'; it++) {
    int c = it - '1';
    deque<pair<int, int>> pq;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(s[i][j] == it) {
          dp[i][j][c] = 0;
          pq.emplace_front(i, j);
        } else {
          dp[i][j][c] = inf;
        }
      }
    }
    while(!pq.empty()) {
      int cost, x, y;
      tie(x, y) = pq.front();
      cost = dp[x][y][c];
      pq.pop_front();
      if(cost != dp[x][y][c]) continue;
      for(int i = 0; i < 4; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(!valid(tx, ty) || s[tx][ty] == '#') continue;
        if(nice(tx, ty)) {
          if(cost < dp[tx][ty][c]) {
            dp[tx][ty][c] = cost;
            pq.emplace_front(tx, ty);
          }
        } else {
          if(cost + 1 < dp[tx][ty][c]) {
            dp[tx][ty][c] = cost + 1;
            pq.emplace_back(tx, ty);
          }
        }
      }
    }
  }
  
  int ans = inf;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      int cur = dp[i][j][0] + dp[i][j][1] + dp[i][j][2] - 2 * (s[i][j] == '.');
      ans = min(ans, cur);
    }
  }
  if(ans == inf) {
    puts("-1");
  } else {
    cout << ans << endl;
  }
  return 0;
}
