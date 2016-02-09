#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 1e9;

int dist[N][N][2][4], n, m, s[N][N];
bool vis[N][N][2][4];

int db[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int main() {
  freopen("dream.in","r",stdin);
  freopen("dream.out","w",stdout);
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%d", &s[i][j]);
    }
  }
  queue<tuple<int, int, int, int>> q;
  for(int i = 0; i < 4; i++) {
    vis[0][0][0][i] = 1;
    q.emplace(0, 0, 0, i);
  }
  while(!q.empty()) {
    int b, y, c, d;
    tie(b, y, c, d) = q.front();
    q.pop();
    if(s[b][y] == 0) continue;
    if(s[b][y] == 3 && c == 0) continue;
    //printf("%d %d %d %d\n", b, y, c, d);
    
    int cost = dist[b][y][c][d];
    if(b == n - 1 && y == m - 1) {
      cout << cost << endl;
      return 0;
    }
    if(s[b][y] == 4) {
      int tb = b + db[d];
      int ty = y + dy[d];
      if(valid(tb, ty)) {
        if(s[tb][ty] != 0 && s[tb][ty] != 3) {
          if(!vis[tb][ty][0][d]) {
            vis[tb][ty][0][d] = 1;
            dist[tb][ty][0][d] = cost + 1;
            q.emplace(tb, ty, 0, d);
          }
        } else {
          goto kentang;
        }
      } else {
        goto kentang;
      }
      continue;
    }
    kentang:;
    if(s[b][y] == 2) {
      c = 1;
    }
    if(s[b][y] == 4) {
      c = 0;
    }
    for(int i = 0; i < 4; i++) {
      int tb = b + db[i];
      int ty = y + dy[i];
      if(valid(tb, ty) && !vis[tb][ty][c][i]) {
        vis[tb][ty][c][i] = 1;
        dist[tb][ty][c][i] = cost + 1;
        q.emplace(tb, ty, c, i);
      }
    }
  }
  puts("-1");
  return 0;
}
