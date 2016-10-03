#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N], b[N], c[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    int d, n;
    scanf("%d %d", &d, &n);
    for (int i = 0; i < n; i++) {
      int u, v
      scanf("%d %d", &u, &v);
      u = (u % d + d) % d;
      v = (v % d + d) % d;
      a[u]++;
      b[v]++;
      c[u][v]++;
    }
    int ans = 1e9;
    for (int i = 0; i < d; i++) {
      for (int j = 0; j < d; j++) {
        ans = min(ans, a[i] + b[j] - c[i][j]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
