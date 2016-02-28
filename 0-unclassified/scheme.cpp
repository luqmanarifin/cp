#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e10;

const int N = 1005;

long long dist[N];
vector<pair<int, int>> edge[N];
int p[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    for(int i = 0; i < N; i++) {
      dist[i] = inf;
      edge[i].clear();
    }
    
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      edge[a].emplace_back(b, c);
      edge[b].emplace_back(a, c);
    }
    for(int i = 1; i <= n; i++) {
      scanf("%d", &p[i]);
    }
    int st, fn;
    scanf("%d %d", &st, &fn);
    
    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, st);
    dist[st] = 0;
    bool found = 0;
    while(!pq.empty()) {
      long long cost;
      int now;
      tie(cost, now) = pq.top();
      pq.pop();
      cost = -cost;
      if(cost != dist[now]) {
        continue;
      }
      if(now == fn) {
        printf("%I64d\n", cost * 10);
        found = 1;
        break;
      }
      for(auto it : edge[now]) {
        int near = it.first;
        long long ncos = it.second;
        long long will = cost + ncos;
        if(p[near] < ncos) {
          will -= p[near];
        }
        if(will < dist[near]) {
          dist[near] = will;
          pq.emplace(-dist[near], near);
        }
      }
    }
    if(!found) {
      puts("-1");
    }
  }
  
  return 0;
}
