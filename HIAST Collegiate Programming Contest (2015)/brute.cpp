#include <bits/stdc++.h>

using namespace std;

int done[2][1 << 20], n;

int dfs(int p, int mask) {
  if(__builtin_popcount(mask) == n) {
    //puts("JANCOK");
    return done[p][mask] = 1;
  }
  if(done[p][mask] != -1) return done[p][mask];
  bool adaLose = 0;
  for(int i = 1; i <= n; i++) {
    if(mask & (1 << (i - 1))) continue;
    int add = 0;
    for(int j = 1; j <= n; j++) {
      if(i % j == 0) {
        add |= (1 << (j - 1));
      }
    }
    int ret = dfs(p ^ 1, mask | add);
    //printf("%d %d %d\n", p ^ 1, mask | add, ret);
    if(ret == 0) {
      adaLose = 1;
      break;
    }
  }
  //printf("%d %d %d\n", p, mask, adaLose);
  return done[p][mask] = adaLose;
}

int main() {
  for(n = 1; n <= 20; n++) {
    memset(done, -1, sizeof(done));
    printf("%d %d\n", n, dfs(0, 0));
  }
  return 0;
}