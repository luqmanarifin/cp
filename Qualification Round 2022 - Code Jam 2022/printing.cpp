#include <bits/stdc++.h>

using namespace std;

const int MIN = 1e6;

int a[5][5], ans[5];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int j = 0; j < 4; j++) ans[j] = 1e9;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        scanf("%d", &a[i][j]);
        ans[j] = min(ans[j], a[i][j]);
      }
    }
    int tot = 0;
    for (int j = 0; j < 4; j++) tot += ans[j];
    printf("Case #%d:", tt);
    if (tot < MIN) {
      printf(" IMPOSSIBLE\n");
      continue;
    }
    int rem = tot - MIN;
    for (int j = 0; j < 4; j++) {
      int now = min(rem, ans[j]);
      ans[j] -= now;
      rem -= now;
      printf(" %d", ans[j]);
    }
    printf("\n");
  } 

  return 0;
}
