#include <bits/stdc++.h>

using namespace std;

const int N = 21;

int vis[N][N];
int sx[N * N], sy[N * N];
int sn, n, m;

vector<pair<int, int> > edge[N][N]; 

bool dfs(int i, int j) {
  vis[i][j] = 1;
  sx[sn] = i;
  sy[sn] = j;
  sn++;

  if (sn == n * m) return 1;
  for (auto it : edge[i][j]) {
    int x, y;
    tie(x, y) = it;
    if (vis[x][y]) continue;
    if (dfs(x, y)) return 1;
  }
  vis[i][j] = 0;
  sn--;
  return 0;
} 

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    printf("Case #%d: ", tt);
    // printf("%d %d: ", n, m);
    scanf("%d %d", &n, &m);
    int p = n, q = m;
    if (p > q) swap(p, q);
    if (p == 2) {
      if (q <= 4) {
        puts("IMPOSSIBLE");
        continue;
      }
    }
    if (p == 3 && q == 3) {
      puts("IMPOSSIBLE");
      continue;
    }
    puts("POSSIBLE");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        vis[i][j] = 0;
        edge[i][j].clear();
      }
    }
    sn = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < n; k++) {
          for (int l = 0; l < m; l++) {
            if (i == k) continue;
            if (j == l) continue;
            if (i - j == k - l) continue;
            if (i + j == k + l) continue;
            edge[i][j].emplace_back(k, l);
          }
        }
      }
    }

    bool can = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (dfs(i, j)) {
          can = 1;
          goto hell;
        }
      }
    }
    hell:;
    assert(can);
    for (int i = 0; i < sn; i++) {
      printf("%d %d\n", sx[i] + 1, sy[i] + 1);
    }
  }

  return 0;
}
