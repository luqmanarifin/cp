#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const int inf = 2e9;

vector<pair<int, int>> edge[N];
int dist[N][2];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    edge[u].emplace_back(v, c);
    edge[v].emplace_back(u, c);
  }
  for (int i = 0; i < N; i++) dist[i][0] = dist[i][1] = inf;
  // -time, node, par
  priority_queue<tuple<int, int, int>> pq;
  pq.emplace(0, 1, 0);
  while (!pq.empty()) {
    int t, now, p;
    tie(t, now, p) = pq.top();
    t = -t;
    pq.pop();
    if (now == n) {
      cout << t << endl;
      return 0;
    }
    for (auto it : edge[now]) {
      int near = it.first;
      int lim = it.second;
      int cur = -1;
      if (t >= lim) {
        cur = t + 1;
      } else {
        cur = (t % 2 == lim % 2? lim : lim + 1) + 1;
      }
      if (dist[near][cur % 2] > cur) {
        dist[near][cur % 2] = cur;
        pq.emplace(-dist[near][cur % 2], near, cur % 2);
      }
    }
  }
  puts("-1");
  return 0;
}
