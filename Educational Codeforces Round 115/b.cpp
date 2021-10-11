#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N][5];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int m = 5;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    bool found = 0;
    for (int j = 0; j < m; j++) {
      for (int k = j + 1; k < m; k++) {
        int lef = 0, rig = 0, both = 0, none = 0;
        for (int i = 0; i < n; i++) {
          if (a[i][j] && a[i][k]) {
            both++;
          } else if (a[i][j]) {
            lef++;
          } else if (a[i][k]) {
            rig++;
          } else {
            none++;
          }
        }
        // printf("%d %d: %d %d %d %d\n", j, k, lef, rig, both, none);
        if (none > 0) continue;
        if (lef + both < n / 2) continue;
        if (rig + both < n / 2) continue;
        found = 1;
      }
    }
    puts(found? "YES" : "NO");
  }
  return 0;
}
