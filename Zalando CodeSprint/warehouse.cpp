#include <bits/stdc++.h>

using namespace std;

const int N = 16;
const int inf = 1e9;

int a[N][N];
int cur[N], need[N];

int main() {
  int w, b, p;
  scanf("%d %d %d", &w, &b, &p);
  for(int i = 0; i < w; i++) {
    for(int j = 0; j < p; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for(int i = 0; i < b; i++) {
    for(int j = 0; j < p; j++) {
      scanf("%d", &need[j]);
    }
    int ans = inf;
    for(int mask = 0; mask < (1 << w); mask++) {
      memset(cur, 0, sizeof(cur));
      for(int k = 0; k < w; k++) {
        if(mask & (1 << k)) {
          for(int j = 0; j < p; j++) {
            cur[j] += a[k][j];
          }
        }
      }
      bool good = 1;
      for(int j = 0; j < p; j++) {
        if(cur[j] < need[j]) {
          good = 0;
          break;
        }
      }
      if(good) {
        ans = min(ans, __builtin_popcount(mask));
      }
    }
    if(ans == inf) {
      puts("-1");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}