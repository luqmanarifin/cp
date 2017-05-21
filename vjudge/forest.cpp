#include <bits/stdc++.h>

using namespace std;

const int N = 205;
const int inf = 1e9;

int d[N][N];
bool block[N][N];
int x[N], y[N], r[N];
int n, m;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int i, int j) {
  return 1 <= i && i <= n && 1 <= j && j <= m;
}

int main() {
  scanf("%d %d", &n, &m);
  while (n && m) {
    memset(block, 0, sizeof(block));
    int q;
    scanf("%d", &q);
    while (q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      block[u][v] = 1;
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) scanf("%d %d %d", x + i, y + i, r + i);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        for (int it = 0; it < k; it++) {
          if ((x[it] - i)*(x[it] - i) + (y[it] - j)*(y[it] - j) <= r[it] * r[it]) {
            block[i][j] = 1;
            break;
          }          
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        d[i][j] = inf;
      }
    }
    if (block[1][1] || block[n][m]) {
      puts("Impossible.");
    } else {
      d[1][1] = 0;
      queue<pair<int, int>> q;
      q.emplace(1, 1);
      while (!q.empty()) {
        int i, j;
        tie(i, j) = q.front();
        q.pop();
        //printf("%d %d\n", i, j);
        for (int it = 0; it < 4; it++) {
          int ti = i + dx[it];
          int tj = j + dy[it];
          if (!valid(ti, tj) || block[ti][tj]) continue;
          if (d[ti][tj] > d[i][j] + 1) {
            d[ti][tj] = d[i][j] + 1;
            q.emplace(ti, tj);
          }
        }
      }
      if (d[n][m] == inf) {
        puts("Impossible.");
      } else {
        printf("%d\n", d[n][m]);
      }
    }
    
    scanf("%d %d", &n, &m);
  }

  return 0;
}
