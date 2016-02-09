#include <bits/stdc++.h>

using namespace std;

bool done[55][55];
char s[55][55];
int n, m;

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

bool dfs(int a, int b, int pa, int pb) {
  if(a == pa && b == pb) {
    return 0;
  }
  if(done[a][b]) {
    return 1;
  }
  done[a][b] = 1;
  for(int i = -1; i <= 1; i++) {
    for(int j = -1; j <= 1; j++) {
      if(abs(i) + abs(j) != 1 || (a + i == pa && b + j == pb)) {
        continue;
      }
      if(valid(a + i, b + j)) {
        if(s[a + i][b + j] == s[a][b]) {
          if(dfs(a + i, b + j, a, b)) {
            return 1;
          }
        }
      }
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
      memset(done, 0, sizeof(done));
      if(dfs(i, j, -1, -1)) {
        puts("Yes");
        return 0;
      }
    }
  }
  puts("No");
  return 0;
}