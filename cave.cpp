#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int db[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

char s[N][N], tmp[N][N];
int n, m, done[N][N];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

int dfs(int b, int y) {
  if(done[b][y]) return 0;
  done[b][y] = 1;
  int ret = 1;
  for(int d = 0; d < 4; d++) {
    int tb = b + db[d];
    int ty = y + dy[d];
    if(valid(b + db[d], y + dy[d])) {
      if(tmp[tb][ty] == '.') {
        ret += dfs(tb, ty);
      }
    }
  }
  return ret;
}

int lepas(int p, int q) {
  memset(done, 0, sizeof(done));
  //printf("lepas %d %d\n", p, q);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(abs(p - i) + abs(q - j) <= 2) {
        tmp[i][j] = '.';
      } else {
        tmp[i][j] = s[i][j];
        if(tmp[i][j] == 'C') {
          tmp[i][j] = '.';
        }
      }
    }
    //printf("%s\n", tmp[i]);
  }
  int ret = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(tmp[i][j] == '.' && !done[i][j]) {
        ret = max(ret, dfs(i, j));
      }
    }
  }
  return ret;
}

int dfs_polos(int b, int y) {
  if(done[b][y]) return 0;
  done[b][y] = 1;
  int ret = 1;
  for(int d = 0; d < 4; d++) {
    int tb = b + db[d];
    int ty = y + dy[d];
    if(valid(b + db[d], y + dy[d])) {
      if(s[tb][ty] != '#') {
        ret += dfs(tb, ty);
      }
    }
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) scanf("%s", s[i]);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(!done[i][j] && s[i][j] != '#') {
        ans = max(ans, dfs_polos(i, j));
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == 'C') {
        ans = max(ans, lepas(i, j));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
