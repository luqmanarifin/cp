#include <bits/stdc++.h>

using namespace std;

int a[5][5];
vector<int> w;
bool done[10];
int fa[10], fb[10], ta[10], tb[10];
bool vis[5][5];

bool dfs(int c, int y, int col) {
  //printf("%d %d %d\n", c, y, col);
  if(c < 0 || c >= 4 || y < 0 || y >= 4 || a[c][y] != col || vis[c][y]) return 0;
  if(ta[col] == c && tb[col] == y) return 1;
  vis[c][y] = 1;
  if(dfs(c + 1, y, col)) return 1;
  if(dfs(c - 1, y, col)) return 1;
  if(dfs(c, y + 1, col)) return 1;
  if(dfs(c, y - 1, col)) return 1;
  return 0;
}

bool backtrack(int t) {
  if(t == 16) {
    memset(vis, 0, sizeof(vis));
    for(auto it : w) {
      if(dfs(fa[it], fb[it], it) == 0) {
        return 0;
      }
    }
    return 1;
  }
  if(a[t / 4][t % 4] == 0) {
    for(auto it : w) {
      a[t / 4][t % 4] = it;
      if(backtrack(t + 1)) return 1;
    }
    a[t / 4][t % 4] = 0;
  } else {
    if(backtrack(t + 1)) return 1;
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    w.clear();
    memset(done, 0, sizeof(done));
    for(int i = 0; i < 4; i++) {
      for(int j = 0; j < 4; j++) {
        scanf("%d", &a[i][j]);
        if(a[i][j]) {
          if(!done[a[i][j]]) {
            fa[a[i][j]] = i, fb[a[i][j]] = j;
            w.push_back(a[i][j]);
          } else {
            ta[a[i][j]] = i, tb[a[i][j]] = j;
          }
          done[a[i][j]] = 1;
        }
      }
    }
    puts(backtrack(0)? "SOLVABLE" : "UNSOLVABLE");
  }
  
  return 0;
}
