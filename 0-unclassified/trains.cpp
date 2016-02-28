#include <bits/stdc++.h>

using namespace std;

const int N = 110;

string s[3];
int vis[3][N];
int n;

bool can(int i, int j) {
  if(i < 0 || i >= 3) return 0;
  if(j >= n) return 1;
  return !('A' <= s[i][j] && s[i][j] <= 'Z');
}

int dfs(int i, int j) {
  if(i < 0 || i >= 3) return 0;
  if(j >= n) return 1;
  int& ret = vis[i][j];
  if(ret != -1) return ret;
  
  ret = 0;
  for(int d = -1; d <= 1; d++) {
    if(can(i, j + 1) && can(i + d, j + 1) && can(i + d, j + 2) && can(i + d, j + 3)) {
      if(dfs(i + d, j + 3)) {
        return ret = 1;
      }
    }
  }
  return ret;
}

int main() {
  int t;
  cin >> t;
  bool good = 0;
  for(int tt = 1; tt <= t; tt++) {
    int k;
    cin >> n >> k;
    for(int i = 0; i < 3; i++) {
      cin >> s[i];
    }
    memset(vis, -1, sizeof(vis));
    bool can = 0;
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < n; j++) {
        if(s[i][j] == 's') {
          if(dfs(i, j)) {
            can = 1;
            goto PRINT;
          }
        }
      }
    }
    PRINT:;
    puts(can? "YES" : "NO");
  }
  return 0;
}
