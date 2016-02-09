// too easy to AC
#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
const int inf = 1e9;

vector<pair<int, int>> edge[N];
int dist[N];

int main() {
  int n, m, t, k;
  scanf("%d %d %d %d", &n, &m, &t, &k);
  while(m--) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    edge[u].emplace_back(v, w);
    edge[v].emplace_back(u, w);
  }
  set<int> safe;
  for(int i = 1; i <= n; i++) {
    safe.insert(i);
    dist[i] = inf;
  }
  while(t--) {
    int a;
    scanf("%d", &a);
    if(safe.empty()) {
      puts("0");
      continue;
    }
    
    priority_queue<pair<int, int>> pq;
    dist[a] = 0;
    pq.emplace(0, a);
    while(!pq.empty()) {
      int cost, now;
      tie(cost, now) = pq.top();
      cost = -cost;
      pq.pop();
      if(cost >= k) break;
      if(dist[now] != cost) continue;
      safe.erase(now);
      for(auto it : edge[now]) {
        int near = it.first;
        int ncos = cost + it.second;
        if(ncos < dist[near]) {
          dist[near] = ncos;
          pq.emplace(-dist[near], near);
        }
      }
    }
    printf("%d\n", safe.size());
  }
  return 0;
}
