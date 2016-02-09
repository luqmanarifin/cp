#include <bits/stdc++.h>

using namespace std;

// pos - last - dif
int memo[1005][15][15];
char s[15];

int dfs(int pos, int last, int dif) {
  int &ret = memo[pos][last][dif];
  if(ret != -1) {
    return ret;
  }
  if(pos == 1) {
    if(last == dif) {
      puts("YES");
      printf("%d ", last);
      return 1;
    }
    return ret = 0;
  }
  if(dif >= last || dif >= 10) {
    return ret = 0;
  }
  //printf("%d %d %d\n", pos, last, dif);
  ret = 0;
  int wd = last - dif;
  for(int i = wd; i <= 10; i++) {
    if(s[i] - '0' && i != last) {
      if(dfs(pos - 1, i, wd)) {
        printf("%d ", last);
        return ret = 1;
      }
    }
  }
  return ret = 0;
}

int main() {
  for(int i = 0; i < 1005; i++) {
    for(int j = 0; j < 15; j++) {
      for(int k = 0; k < 15; k++) {
        memo[i][j][k] = -1;
      }
    }
  }
  int m;
  scanf("%s %d", s + 1, &m);
  for(int i = 1; i <= 10; i++) {
    if(s[i] - '0') {
      for(int j = 1; j <= 10; j++) {
        if(dfs(m, i, j)) {
          return 0;
        }
      }
    }
  }
  puts("NO");
  return 0;
}
