#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];
int n, m;
bool out[N][N];
bool vis[N][N][4];
char to[] = "^>v<";
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

bool dfs(int i, int j, int at) {
  if(s[i][j] == '.' && at == -1) return 1;
  if(at != -1 && vis[i][j][at]) return 1;
  if(at != -1) vis[i][j][at] = 1;
  
  if(s[i][j] == '.') {
    if(!valid(i + dx[at], j + dy[at])) {
      return 0;
    }
    if(!dfs(i + dx[at], j + dy[at], at)) {
      return 0;
    }
  } else {
    for(int p = 0; p < 4; p++) {
      if(s[i][j] == to[p]) {
        if(!valid(i + dx[p], j + dy[p])) {
          out[i][j] = 1;
          return 1;
        }
        if(!dfs(i + dx[p], j + dy[p], p)) {
          return 0;
        }
      }
    }
  }
  return 1;
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(out, 0, sizeof(out));
    memset(vis, 0, sizeof(vis));
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    bool can = 1;
    for(int i = 0; i < n; i++) {
      if(!can) break;
      for(int j = 0; j < m; j++) {
        if(!dfs(i, j, -1)) {
          can = 0;
          break;
        }
      }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(i != 0 && i != n - 1) continue;
        if(j != 0 && j != m - 1) continue;
        if(s[i][j] == '.') continue;
        for(int k = 0; k < 4; k++) {
          if(s[i][j] == to[k]) {
            if(!valid(i + dx[k], j + dy[k])) {
              ans++;
            }
          }
        }
      }
    }
    printf("Case #%d: ", tt);
    if(can) {
      printf("%d\n", ans);
    } else {
      puts("IMPOSSIBLE");
    }
  }
  
  return 0;
}
