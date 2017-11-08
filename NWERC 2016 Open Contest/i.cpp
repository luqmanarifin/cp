#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

int d[N][4];
vector<int> g[N];

int main() {
  int n, m, k;
  scanf("%d %d %d",  &n, &m, &k);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 4; j++)
      d[i][j] = inf;
  }
  priority_queue<pair<int, int> > q;
  for (int i = 0; i < m; i++) {
    int v;
    scanf("%d", &v); v--;
    d[v][1] = 1;
    q.push(make_pair(-d[v][1], (v << 2) + 1));
  }
  for (int i =0; i < k; i++) {
    int v;
    scanf("%d", &v); v--;
    d[v][2] = 1;
    q.push(make_pair(-d[v][2], (v << 2) + 2));
  }
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    while (a--) {
      int v; scanf("%d", &v); v--;
      g[v].push_back(i);
    }
  }
  while (!q.empty()) {
    int v = q.top().second >> 2, mask = q.top().second & 3;
    int dist = -q.top().first;
    q.pop();
    if (d[v][mask] != dist) continue;
    for (int u : g[v]) {
      if (d[u][mask] > d[v][mask] + 1) {
        d[u][mask] = d[v][mask] + 1;
        q.push(make_pair(-d[u][mask], (u << 2) + mask));
      }
      if (d[u][3] > d[v][1] + d[u][2]) {
        d[u][3] = d[v][1] + d[u][2];
        q.push(make_pair(-d[u][3], (u << 2) + 3));
      }
      if (d[u][3] > d[v][2] + d[u][1]) {
        d[u][3] = d[v][2] + d[u][1];
        q.push(make_pair(-d[u][3], (u << 2) + 3));
      }
    }
  }
  if (d[0][3] >= inf) {
    puts("impossible");
  }
  else
    printf("%d\n", d[0][3]-1);
  

  return 0;
}
