#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int inf = 1e9;

int d[N][N], x[1005], y[1005], z[1005];

void upd(int& at, int val) {
  at = min(at, val);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        d[i][j] = inf;
      }
      d[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", x + i, y + i, z + i);
      upd(d[x[i]][y[i]], z[i]);
      upd(d[y[i]][x[i]], z[i]);
    }
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          upd(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
    bool ok = 1;
    for (int i = 0; i < m; i++) {
      if (d[x[i]][y[i]] != z[i]) {
        ok = 0;
      }
    }
    printf("Case #%d: ", tt);
    if (!ok) {
      printf("Impossible\n");
      continue;
    }
    int edges = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (d[i][j] != inf) edges++;
      }
    }
    printf("%d\n", edges);
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (d[i][j] != inf) {
          printf("%d %d %d\n", i, j, d[i][j]);
        }
      }
    }
  }

  return 0;
}
