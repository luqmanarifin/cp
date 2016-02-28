#include <bits/stdc++.h>

using namespace std;

const int N = 15;

string str = "URDL";
int db[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
char s[N][N];
bool vis[N][N][4];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void dfs(int b, int y, int d) {
  if(vis[b][y][d]) return;
  vis[b][y][d] = 1;
  for(int tt = 0; tt < 4; tt++) {
    int tb = b + db[d];
    int ty = y + dy[d];
    if(valid(tb, ty) && s[tb][ty] != '*') {
      return dfs(tb, ty, d);
    }
    d = (d + 1) % 4;
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] != '.' && s[i][j] != '*') {
        for(int k = 0; k < 4; k++) {
          if(s[i][j] == str[k]) {
            dfs(i, j, k);
          }
        }
      }
    }
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      bool done = 0;
      for(int k = 0; k < 4; k++) {
        if(vis[i][j][k]) {
          done = 1;
        }
      }
      if(done) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
