/**
 * taken from visualgo.cpp
 * SG Preliminary Contest
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;
const long long inf = 1e18;
const int mod = 2010000089;

long long dist[N];
long long f[N];
vector<pair<int, int>> edge[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  while(k--) {
    int junk;
    scanf("%d", &junk);
  }
    
  while(m--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    edge[a].emplace_back(b, c);
    edge[b].emplace_back(a, c);
  }
  int s = 1, t = n;
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
      int ncos = cost + it.second;
      if(ncos < dist[it.first]) {
        dist[it.first] = ncos;
        pq.emplace(-dist[it.first], it.first);
        f[it.first] = f[now];
      } else if(ncos == dist[it.first]) {
        f[it.first] += f[now];
        f[it.first] %= mod;
      }
    }
  }
  cout << (f[t] != 1? "yes" : "no") << endl;
  return 0;
}
