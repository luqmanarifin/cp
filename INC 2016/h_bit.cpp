#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int inf = 1e9;

// milik - 0 minimum / 1 maksimum - akhir di mana
int lef[N][2][N];
int rig[N][2][N];
int a[N], n;

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
      fill(lef[i][0], lef[i][0] + N, inf);
      fill(lef[i][1], lef[i][1] + N, 0);
      fill(rig[i][0], rig[i][0] + N, inf);
      fill(rig[i][1], rig[i][1] + N, 0);
    }
    
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      lef[i][0][i] = a[i];
      lef[i][1][i] = a[i];
      rig[i][0][i] = a[i];
      rig[i][1][i] = a[i];
    }
    for (int len = 2; len <= n; len++) {
      for (int i = 1; i <= n; i++) {
        int j = i + len - 1;
        lef[i][0][j] = min(lef[i][1][j - 1], rig[j][1][i + 1]);
        lef[i][1][j] = max(lef[i][0][j - 1], rig[j][0][i + 1]);
        rig[j][0][i] = lef[i][0][j];
        rig[j][1][i] = lef[i][1][j];
      }
    }
    printf("Case #%d: %d\n", tt, lef[1][1][n]);
  }
  
  return 0;
}