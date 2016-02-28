#include <bits/stdc++.h>

using namespace std;

const int N = 6005;
const int inf = 1e9;

int dp[N][N];
int dx[] = {1, 2, 2, 1, -2, -1};
int dy[] = {2, 1, -1, -2, 1, 2};

int valid(int i, int j) {
  return 0 <= i && i < N && 0 <= j && j < N;
}

int main() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  queue<pair<int, int>> q;
  q.emplace(0, 0);
  while(!q.empty()) {
    int x, y;
    tie(x, y) = q.front();
    q.pop();
    if(dp[x][y] > 3000) {
      break;
    }
    for(int i = 0; i < 6; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(!valid(xx, yy)) {
        continue;
      }
      if(dp[x][y] + 1 < dp[xx][yy]) {
        dp[xx][yy] = dp[x][y] + 1;
        q.emplace(xx, yy);
      }
    }
  }
  int t;
  scanf("%d", &t);
  while(t--) {
    int ax, ay, ix, iy, h;
    scanf("%d %d %d %d %d", &ax, &ay, &ix, &iy, &h);
    int x = abs(ax - ix);
    int y = abs(ay - iy);
    if(x >= N || y >= N) {
      puts("-1");
      continue;
    }
    if(dp[x][y] <= h) {
      printf("%d\n", dp[x][y]);
    } else {
      puts("-1");
    }
  }
  return 0;
}
