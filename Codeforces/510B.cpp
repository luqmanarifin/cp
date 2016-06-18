#include <bits/stdc++.h>

using namespace std;

char s[55][55];
bool vis[55][55];
int n, m;

int da[] = {0, 0, 1, -1};
int db[] = {1, -1, 0, 0};

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

bool dfs(int i, int j, int li, int lj) {
  if(vis[i][j]) return 1;
  vis[i][j] = 1;
  for(int k = 0; k < 4; k++) {
    int pi = i + da[k];
    int pj = j + db[k];
    if(!valid(pi, pj)) continue;
    if(pi == li && pj == lj) continue;
    if(s[i][j] != s[pi][pj]) continue;
    if(dfs(pi, pj, i, j)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(!vis[i][j]) {
        if(dfs(i, j, -1, -1)) {
          //printf("%d %d\n", i, j);
          puts("Yes");
          return 0;
        }
      }
    }
  }
  puts("No");
  return 0;
}
