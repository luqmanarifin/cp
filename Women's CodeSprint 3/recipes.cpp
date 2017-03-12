#include <bits/stdc++.h>

using namespace std;

const int N = 35;

bool ada[N];
int c[N], a[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(ada, 0, sizeof(ada));
    
    int r, p, n, m;
    scanf("%d %d %d %d", &r, &p, &n, &m);
    for (int i = 0; i < m; i++) {
      int v;
      scanf("%d", &v);
      ada[v] = 1;
    }
    for (int i = 0; i < p; i++) scanf("%d", c + i);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < p; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    int ans = 2e9;
    for (int mask = 0; mask < (1 << p); mask++) {
      int cost = 0;
      for (int j = 0; j < p; j++) {
        if (!ada[j] && ((1 << j) & mask)) {
          cost += c[j];
        }
      }
      int ready = 0;
      for (int i = 0; i < r; i++) {
        bool all = 1;
        for (int j = 0; j < p; j++) {
          if (a[i][j] && (mask & (1 << j)) == 0) {
            all = 0;
            break;
          }
        }
        if (all) ready++;
      }
      if (ready >= n) {
        ans = min(ans, cost);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
