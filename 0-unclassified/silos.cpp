#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

vector<pair<int, int>> edge[N];
long long dist[N];

bool valid(int a, int len) {
  return 0 < a && a < len;
}

int main() {
  int n, m, s;
  scanf("%d %d %d", &n, &m, &s);
  while(m--) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    edge[u].emplace_back(v, c);
    edge[v].emplace_back(u, c);
  }
  int l;
  scanf("%d", &l);
  
  for(int i = 0; i < N; i++) {
    dist[i] = inf;
  }
  priority_queue<pair<long long, int>> pq;
  dist[s] = 0;
  pq.emplace(0, s);
  while(!pq.empty()) {
    long long cost; int now;
    tie(cost, now) = pq.top();
    pq.pop();
    cost = -cost;
    if(cost != dist[now]) {
      continue;
    }
    for(auto it : edge[now]) {
      int near = it.first;
      int ncos = it.second;
      if(cost + ncos < dist[near]) {
        dist[near] = cost + ncos;
        pq.emplace(-dist[near], near);
      }
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    for(auto it : edge[i]) {
      int near = it.first;
      int len = it.second;
      if(near < i) continue;
      bool v1 = 1;
      int d1 = l - dist[i];
      if(!valid(d1, len)) v1 = 0;
      int jar = min(dist[i] + d1, dist[near] + len - d1);
      if(jar != l) v1 = 0;
      
      bool v2 = 1;
      int d2 = l - dist[near];
      if(!valid(d2, len)) v2 = 0;
      int jra = min(dist[near] + d2, dist[i] + len - d2);
      if(jra != l) v2 = 0;
      
      if(v1 && v2) {
        if(d1 + d2 == len) {
          ans++;
        } else {
          ans += 2;
        }
      } else if(v1 || v2) {
        ans++;
      }
    }
    if(dist[i] == l) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
