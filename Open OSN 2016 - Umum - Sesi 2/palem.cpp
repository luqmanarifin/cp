#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int d[N][N], n, m, q, K;
int x[N*N], y[N*N], pos[N][N];
char junk[25], s[N][N];
bool done[N*N];

int main() {
  scanf("%s %d %d %d %d", junk, &n, &m, &K, &q);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  int pt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == 'X') {
        x[pt] = i;
        y[pt] = j;
        pos[i][j] = pt;
        pt++;
      }
    }
  }
  while (q--) {
    memset(done, 0, sizeof(done));
    int u, v;
    scanf("%d %d", &u, &v);
    int at = pos[u][v];
    if (s[u][v] != 'X') {
      int best = 1e9, p = -1;
      for (int i = 0; i < pt; i++) {
        int d = abs(u - x[i]) + abs(v - y[i]);
        if (d < best) {
          best = d;
          p = i;
        } else if (d == best) {
          p = -1;
        }
      }
      if (p == -1) {
        printf("%d %d\n", u, v);
        continue;
      }
      at = p;
    }
    while (1) {
      //printf("at %d\n", at);
      done[at] = 1;
      int best = 1e9, p = -1;
      for (int i = 0; i < pt; i++) {
        if (i == at) continue;
        int d = abs(x[i] - x[at]) + abs(y[i] - y[at]);
        if (d < best) {
          best = d;
          p = i;
        } else if (d == best) {
          p = -1;
        }
      }
      if (p == -1 || done[p]) {
        printf("%d %d\n", x[at], y[at]);
        break;
      }
      at = p;
    }
  }

  return 0;
}
