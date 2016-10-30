#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 105;

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

char s[N][N];
int n, m;
int c[N][N];
int si, sj, pi, pj;

int ds[N][N], dp[N][N];
bool done[N][N];

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void dijkstra(int fi, int fj, int dist[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dist[i][j] = inf;
    }
  }
  priority_queue<tuple<int, int, int>> pq;
  dist[fi][fj] = 0;
  pq.emplace(0, fi, fj);
  while (!pq.empty()) {
    int cost, ni, nj;
    tie(cost, ni, nj) = pq.top();
    cost = -cost;
    pq.pop();
    //printf("%d %d %d\n", cost, ni, nj);
    if (dist[ni][nj] != cost) continue;
    for (int k = 0; k < 4; k++) {
      int ti = ni + di[k];
      int tj = nj + dj[k];
      int ncos = cost + c[ti][tj];
      if (valid(ti, tj) && s[ti][tj] != '0' && ncos < dist[ti][tj]) {
        dist[ti][tj] = ncos;
        pq.emplace(-ncos, ti, tj);
      }
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(c, 0, sizeof(c));
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    int all = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == 'A') {
          si = i; sj = j;
        } else if (s[i][j] == 'B') {
          pi = i; pj = j;
        } else {
          c[i][j] = s[i][j] - '0';
          all += s[i][j] - '0';
        }
      }
    }
    dijkstra(si, sj, ds);
    dijkstra(pi, pj, dp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (ds[i][j] == inf || dp[i][j] == inf) continue;
        int cur = all - ds[i][j] - dp[i][j] + 2 * c[i][j];
        ans = max(ans, cur);
      }
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
