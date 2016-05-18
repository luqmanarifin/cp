#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const int inf = 1e9;

int dist[N];
long long f[N];
vector<pair<int, int>> edge[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    edge[a].emplace_back(b, c);
  }
  int s, t;
  scanf("%d %d", &s, &t);
  for(int i = 0; i < N; i++) {
    dist[i] = inf;
  }
  priority_queue<pair<int, int>> pq;
  dist[s] = 0;
  pq.emplace(0, s);
  f[s] = 1;
  while(!pq.empty()) {
    int cost, now;
    tie(cost, now) = pq.top();
    cost = -cost;
    pq.pop();
    if(dist[now] != cost) {
      continue;
    }
    for(auto it : edge[now]) {
      //printf("%d to %d : %d\n", now, it.first, it.second);
      int ncos = cost + it.second;
      if(ncos < dist[it.first]) {
        dist[it.first] = ncos;
        pq.emplace(-dist[it.first], it.first);
        f[it.first] = f[now];
      } else if(ncos == dist[it.first]) {
        f[it.first] += f[now];
      }
    }
  }
  /*
  for(int i = 0; i < n; i++) {
    printf("%d : %d %d\n", i, dist[i], f[i]);
  }
  */
  cout << f[t] << endl;
  return 0;
}