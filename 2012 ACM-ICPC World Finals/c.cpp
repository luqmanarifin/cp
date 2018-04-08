#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int inf = 1e9;

int to_s[N][1 << N];
int to_f[N][1 << N];
int d[N][N];

int main() {
  int n, m;
  int tt = 0;
  while (scanf("%d %d", &n, &m) == 2) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        d[i][j] = inf;
      }
      d[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      d[u][v] = c;
      d[v][u] = c;
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
    //~ for (int i = 0; i < n; i++) {
      //~ for (int j = 0; j < n; j++) {
        //~ printf("s %d %d: %d\n", i, j, d[i][j]);
      //~ }
    //~ }
    printf("Case %d: ", ++tt);
    if (n == 3) {
      printf("%d\n", 2 * (d[0][1] + d[1][2]));
      continue;
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < (1 << N); j++) {
        to_s[i][j] = inf;
        to_f[i][j] = inf;
      }
    }
    int h = n - 2;
    int mask_max = max(h/2, h - h/2 + 1);
    
    to_s[0][0] = 0;
    priority_queue<tuple<int, int, int>> pq;
    pq.emplace(0, 0, 0);
    while (!pq.empty()) {
      int cost, now, mask;
      tie(cost, now, mask) = pq.top();
      cost = -cost;
      pq.pop();
      //~ printf("%d %d: %d\n", now, mask, cost);
      if (__builtin_popcount(mask) > mask_max) continue;
      if (cost != to_s[now][mask]) continue;
      for (int i = 1; i < n - 1; i++) {
        int ncos = cost + d[now][i];
        if (to_s[i][mask | (1 << i)] > ncos) {
          to_s[i][mask | (1 << i)] = ncos;
          pq.emplace(-ncos, i, mask | (1 << i));
        }
      }
    }
    
    to_f[n - 1][0] = 0;
    pq.emplace(0, n - 1, 0);
    while (!pq.empty()) {
      int cost, now, mask;
      tie(cost, now, mask) = pq.top();
      cost = -cost;
      pq.pop();
      if (__builtin_popcount(mask) > mask_max) continue;
      if (cost != to_f[now][mask]) continue;
      for (int i = 1; i < n - 1; i++) {
        int ncos = cost + d[now][i];
        if (to_f[i][mask | (1 << i)] > ncos) {
          to_f[i][mask | (1 << i)] = ncos;
          pq.emplace(-ncos, i, mask | (1 << i));
        }
      }
    }
    
    int ans = inf;
    for (int mask = 0; mask < (1 << n); mask++) {
      if (mask & (1 << 0)) continue;
      if (mask & (1 << (n - 1))) continue;
      if (__builtin_popcount(mask) != h / 2) continue;
      int all = (((1 << (n - 2)) - 1) << 1);
      for (int s = 1; s < n - 1; s++) {
        if ((mask & (1 << s)) == 0) continue;
        for (int f = 1; f < n - 1; f++) {
          if ((mask & (1 << f)) == 0) continue;
          int rev_s = ((all ^ mask) | (1 << s));
          int rev_f = ((all ^ mask) | (1 << f));
          int cur = to_s[s][mask] + to_f[s][rev_s] + to_s[f][rev_f] + to_f[f][mask];
          ans = min(ans, cur);
        }
      }
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
