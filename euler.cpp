#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N][N];
int dx4[] = {1, 0, -1, 0};
int dy4[] = {0, -1, 0, 1};
int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
int n, m;
bool done[N][N];

bool valid(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs_black(int x, int y) {
  if(done[x][y]) return;
  done[x][y] = 1;
  for(int i = 0; i < 8; i++) {
    int tx = x + dx8[i];
    int ty = y + dy8[i];
    if(!valid(tx, ty)) continue;
    if(s[tx][ty] == 'X') {
      dfs_black(tx, ty);
    }
  }
}

void dfs_white(int x, int y) {
  if(done[x][y]) return;
  done[x][y] = 1;
  for(int i = 0; i < 4; i++) {
    int tx = x + dx4[i];
    int ty = y + dy4[i];
    if(!valid(tx, ty)) continue;
    if(s[tx][ty] == 'O') {
      dfs_white(tx, ty);
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    memset(done, 0, sizeof(done));
    for(int i = 0; i < n; i++) {
      if(s[i][0] == 'O') dfs_white(i, 0);
      if(s[i][m - 1] == 'O') dfs_white(i, m - 1);
    }
    for(int j = 0; j < m; j++) {
      if(s[0][j] == 'O') dfs_white(0, j);
      if(s[n - 1][j] == 'O') dfs_white(n - 1, j);
    }
    
    int region = 0, hole = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(!done[i][j]) {
          if(s[i][j] == 'X') {
            dfs_black(i, j);
            region++;
          } else {
            dfs_white(i, j);
            hole++;
          }
        }
      }
    }
    printf("%d\n", region - hole);
  }
  
  
  return 0;
}
