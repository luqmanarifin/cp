#include <bits/stdc++.h>

using namespace std;

char s[305][305];
int f[305][305], n;
bool done[305][305];
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};

inline bool valid(int i, int j) {
  return 1 <= i && i <= n && 1 <= j && j <= n;
}

void dfs(int i, int j) {
  if(!valid(i, j) || done[i][j] || s[i][j] == '*') return;
  done[i][j] = 1;
  if(f[i][j]) return;
  for(int k = 0; k < 8; k++) {
    dfs(i + dx[k], j + dy[k]);
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(f, 0, sizeof(f));
    memset(done, 0, sizeof(done));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
      scanf("%s", &s[i][1]);
      for(int j = 1; j <= n; j++) {
        if(s[i][j] == '.') continue;
        for(int k = 0; k < 8; k++) {
          f[i + dx[k]][j + dy[k]]++;
        }
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(s[i][j] == '.' && !done[i][j] && f[i][j] == 0) {
          ans++;
          dfs(i, j);
        }
      }
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(s[i][j] == '.' && !done[i][j]) {
          ans++;
        }
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  
  return 0;
}
