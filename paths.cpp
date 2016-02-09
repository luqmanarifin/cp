#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long inf = 2e18;

pair<int, int> edges[N];
vector<int> side[N];

int last[N];
long long dist[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int id = 0;
  for(int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    
    side[u].push_back(id);
    edges[id++] = make_pair(v, w);
    
    side[v].push_back(id);
    edges[id++] = make_pair(u, w);
  }
  int start;
  scanf("%d", &start);
  
  for(int i = 0; i < N; i++) {
    dist[i] = inf;
  }
  dist[start] = 0;
  priority_queue<pair<long long, int>> pq;
  pq.emplace(0, start);
  while(!pq.empty()) {
    long long cost;
    int now;
    tie(cost, now) = pq.top();
    pq.pop();
    cost = -cost;
    if(cost != dist[now]) continue;
    for(auto it : side[now]) {
      int ncos = edges[it].second;
      int near = edges[it].first;
      if(dist[now] + ncos < dist[near]) {
        dist[near] = dist[now] + ncos;
        pq.emplace(-dist[near], near);
        last[near] = it;
      } else if(dist[now] + ncos == dist[near]) {
        if(edges[it].second < edges[last[near]].second) {
          last[near] = it;
        }
      }
    }
  }
  long long tot = 0;
  vector<int> ans;
  for(int i = 1; i <= n; i++) {
    if(i != start && dist[i] != inf) {
      tot += edges[last[i]].second;
      assert(i == edges[last[i]].first);
      ans.push_back(last[i] / 2 + 1);
    }
  }
  cout << tot << endl;
  for(auto it : ans) {
    printf("%d ", it);
  }
  
  return 0;
}
