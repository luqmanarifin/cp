#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int d[N], a[N];
vector<int> edge[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  
  priority_queue<pair<int, int>> pq;
  pq.emplace(a[1], 1);
  d[1] = a[1];
  while (!pq.empty()) {
    int cost, now;
    tie(cost, now) = pq.top();
    pq.pop();
    if (cost != d[now]) continue;
    for (auto it : edge[now]) {
      int ncos = __gcd(cost, a[it]);
      if (ncos > d[it]) {
        d[it] = ncos;
        pq.emplace(ncos, it);
      }
    }
  }
  printf("%d\n", d[n]);
  return 0;
}
