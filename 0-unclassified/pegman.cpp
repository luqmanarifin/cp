#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char s[N][N];
int n, m;
// dia harus ganti arah
bool out[N][N];
// lewat sini aman
bool safe[N][N];
// lagi di-dfs in
bool ran[N][N][4];

char to[] = "^>v<";
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int dfs(int i, int j, int at) {
  if(!valid(i, j)) return 0;
  if(safe[i][j]) return 1;
  if(ran[i][j][at]) {
    safe[i][j] = 1;
    return safe[i][j];
  }
  ran[i][j][at] = 1;
  if(s[i][j] == '.') {
    int ret = dfs(i + dx[at], j + dy[at], at);
    if(ret == -1) {
      return -1;
    } else if(ret == 1) {
      safe[i][j] = 1;
    }
  } else {
    for(int k = 0; k < 4; k++) {
      if(s[i][j] == to[k]) {
        int ret = dfs(i + dx[k], j + dy[k], k);
        if(ret == -1) {
          return -1;
        } else if(ret == 1) {
          safe[i][j] = 1;
        } else {
          for(k = 0; k < 4; k++) {
            if(dfs(i + dx[k], j + dy[k], k) == 1) {
              safe[i][j] = 1;
            }
          }
          if(!safe[i][j]) {
            return -1;
          }
          out[i][j] = 1;
        }
      }
    }
  }
  ran[i][j][at] = 0;
  return safe[i][j];
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    memset(safe, 0, sizeof(safe));
    memset(out, 0, sizeof(out));
    memset(ran, 0, sizeof(ran));
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    bool can = 1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        for(int k = 0; k < 4; k++) {
          if(s[i][j] == to[k]) {
            if(dfs(i, j, k) == -1) {
              can = 0;
              break;
            }
          }
        }
      }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        for(int k = 0; k < 4; k++) {
          if(s[i][j] == to[k]) {
            int ii = i, jj = j;
            while(valid(ii, jj)) {
              ii += dx[k];
              jj += dy[k];
              if(!valid(ii, jj)) {
                ans++;
                break;
              }
              int found = 0;
              for(int it = 0; it < 4; it++) {
                if(s[ii][jj] == to[it]) {
                  found = 1;
                }
              }
              if(found) {
                break;
              }
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
