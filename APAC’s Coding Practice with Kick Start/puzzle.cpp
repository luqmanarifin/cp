#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int OFFSET = 100;

int n, vis[N][N], did[N][2];
char s[N][N];

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};

int group(int x, int y, int d) {
  if (d == 0) {
    return x + y;
  }
  return x - y + OFFSET;
}

bool valid(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int x, int y) {
  if (vis[x][y]) return;
  vis[x][y] = 1;

  int c = (s[x][y] == '.');
  for (int d = 0; d < 2; d++) {
    if (did[group(x, y, d)][d] != -1 && did[group(x, y, d ^ 1)][d ^ 1] == -1) {
      did[group(x, y, d ^ 1)][d ^ 1] = (c ^ did[group(x, y, d)][d]);
    }
  }
  for (int dir = 0; dir < 4; dir++) {
    int gx = x + dx[dir];
    int gy = y + dy[dir];
    if (!valid(gx, gy)) continue;
    dfs(gx, gy);
  }
}

int solve(int x, int y, int d, int val) {
  memset(vis, 0, sizeof(vis));
  memset(did, -1, sizeof(did));
  did[group(x, y, d)][d] = val;
  dfs(x, y);

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2; j++) {
      if (did[i][j] == 1) {
        ans++;
      }
    }
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    int ans = min(solve(0, 0, 0, 0), solve(0, 0, 0, 1)) + min(solve(0, 1, 0, 0), solve(0, 1, 0, 1));
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
