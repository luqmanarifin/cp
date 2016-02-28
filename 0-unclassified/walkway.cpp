#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int inf = 2e9 + 1e8;

vector<pair<int, int>> edge[N];
int dist[N];

int area(int a, int b, int h) {
  return (a + b) * h;
}

int main() {
  int n;
  scanf("%d", &n);
  while(n) {
    vector<int> rem;
    for(int i = 0; i < n; i++) {
      int a, b, h;
      scanf("%d %d %d", &a, &b, &h);
      edge[a].emplace_back(b, h);
      edge[b].emplace_back(a, h);
      rem.push_back(a);
      rem.push_back(b);
      dist[a] = dist[b] = inf;
    }
    int from, goal;
    scanf("%d %d", &from, &goal);
    rem.push_back(from);
    rem.push_back(goal);
    dist[from] = dist[goal] = inf; 
    
    priority_queue<pair<int, int>> pq;
    dist[from] = 0;
    pq.emplace(0, from);
    while(!pq.empty()) {
      int cost, now;
      tie(cost, now) = pq.top();
      cost = -cost;
      pq.pop();
      if(dist[now] != cost) {
        continue;
      }
      if(now == goal) {
        printf("%.15f\n", 1. * cost / 100);
        break;
      }
      for(auto it : edge[now]) {
        int ncos = cost + area(now, it.first, it.second);
        if(ncos < dist[it.first]) {
          dist[it.first] = ncos;
          pq.emplace(-dist[it.first], it.first);
        }
      }
    }
    
    for(auto it : rem) {
      edge[it].clear();
    }
    scanf("%d", &n);
  }
  
  return 0;
}
