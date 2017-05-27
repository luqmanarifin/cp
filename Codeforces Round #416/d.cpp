#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];
int n, m;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string cmd = "RLDU";
vector<int> cmds;

int d[N][N];
int bx[N][N], by[N][N], bef[N][N];

bool valid(int i, int j) {
  return 1 <= i && i <= n && 1 <= j && j <= m;
}

bool danger(int i, int j) {
  return valid(i, j) && s[i][j] == '*';
}

void dfs(int tx, int ty, int sx, int sy) {
  //printf("kontol %d %d\n", tx, ty);
  if (tx == sx && ty == sy) return;
  cmds.push_back(bef[tx][ty]);
  dfs(bx[tx][ty], by[tx][ty], sx, sy);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  int fx, fy;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'F') {
        fx = i;
        fy = j;
      }
    }
  }
  
  if (fx == 1 && fy == 1) return 0;
  
  int swap_l = -1, swap_u = -1;
  int x = 1, y = 1;
  while (true) {
    if (swap_l == -1 && m >= 2) {
      if (!danger(x, y - 1) && !danger(x, y + 1)) {
        printf("R\n");
        fflush(stdout);
        int supposed_x = x;
        int supposed_y = min(m, y + 1);
        scanf("%d %d", &x, &y);
        if (x == supposed_x && y == supposed_y) {
          swap_l = 0;
        } else {
          swap_l = 1;
        }
        
        if (x != 1 || y != 1) {
          printf("L\n");
          fflush(stdout);
          scanf("%d %d", &x, &y);
        }
      }
      if (fx == x && fy == y) return 0;
    }
    if (swap_u == -1 && n >= 2) {
      if (!danger(x - 1, y) && !danger(x + 1, y)) {
        printf("D\n");
        fflush(stdout);
        int supposed_x = min(n, x + 1);
        int supposed_y = y;
        scanf("%d %d", &x, &y);
        if (x == supposed_x && y == supposed_y) {
          swap_u = 0;
        } else {
          swap_u = 1;
        }
        
        if (x != 1 || y != 1) {
          printf("U\n");
          fflush(stdout);
          scanf("%d %d", &x, &y);
        }
      }
      if (fx == x && fy == y) return 0;
    }
    if (swap_u == -1 && n >= 2 && swap_l != -1 && !danger(x, y + 1)) {
      if (swap_l) {
        printf("L\n");
      } else {
        printf("R\n");
      }
      fflush(stdout);
      scanf("%d %d", &x, &y);
    }
    if (swap_l == -1 && m >= 2 && swap_u != -1 && !danger(x + 1, y)) {
      if (swap_u) {
        printf("U\n");
      } else {
        printf("D\n");
      }
      fflush(stdout);
      scanf("%d %d", &x, &y);
    }
    if (fx == x && fy == y) return 0;
    if (swap_u != -1 && swap_l != -1) {
      int fromx = x, fromy = y;
      queue<pair<int, int>> q;
      q.emplace(x, y);
      //printf("bfs from %d %d\n", x, y);
      while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();
        //printf("%d %d dari %d %d\n", x, y, bx[x][y], by[x][y]);
        for (int i = 0; i < 4; i++) {
          int tx = x + dx[i];
          int ty = y + dy[i];
          if (!valid(tx, ty) || danger(tx, ty)) continue;
          if (d[tx][ty] == 0) {
            q.emplace(tx, ty);
            d[tx][ty] = 1;
            bx[tx][ty] = x;
            by[tx][ty] = y;
            bef[tx][ty] = i;
          }
        }
      }
      dfs(fx, fy, fromx, fromy);
      reverse(cmds.begin(), cmds.end());
      for (auto it : cmds) {
        if (it < 2) {
          printf("%c\n", cmd[it ^ swap_l]);
        } else {
          printf("%c\n", cmd[it ^ swap_u]);
        }
        fflush(stdout);
        scanf("%d %d", &x, &y);
      }
      return 0;
    }
  }

  return 0;
}