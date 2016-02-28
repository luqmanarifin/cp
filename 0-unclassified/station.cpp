#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

bool done[105];
vector<int> back[105];
vector<int> aft[105];
vector<int> edge[105];
int dist[105];
long long ways[105];
long long temp[105];

void backtrack(int now) {
  if(done[now] || now == 1) return;
  done[now] = 1;
  for(auto it : back[now]) {
    aft[it].push_back(now);
    backtrack(it);
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for(int i = 0; i < 105; i++) {
    dist[i] = inf;
  }
  priority_queue<pair<int, int>> pq;
  dist[1] = 0;
  pq.emplace(0, 1);
  while(!pq.empty()) {
    int cost, now;
    tie(cost, now) = pq.top();
    pq.pop();
    cost = -cost;
    if(dist[now] != cost) continue;
    for(auto near : edge[now]) {
      if(cost + 1 < dist[near]) {
        dist[near] = cost + 1;
        pq.emplace(-dist[near], near);
        back[near].clear();
        back[near].push_back(now);
      } else if(cost + 1 == dist[near]) {
        back[near].push_back(now);
      }
    }
  }
  backtrack(n);
  queue<int> q;
  ways[1] = 1;
  q.push(1);
  memset(done, 0, sizeof(done));
  while(!q.empty()) {
    int now = q.front();
    q.pop();
    for(auto near : aft[now]) {
      ways[near] += ways[now];
      if(!done[near]) {
        done[near] = 1;
        q.push(near);
      }
    }
  }
  long long ans = ways[n];
  for(int i = 2; i < n; i++) {
    memset(temp, 0, sizeof(temp));
    memset(done, 0, sizeof(done));
    temp[i] = ways[i];
    queue<int> bfs;
    bfs.push(i);
    while(!bfs.empty()) {
      int now = bfs.front();
      bfs.pop();
      for(auto near : aft[now]) {
        temp[near] += temp[now];
        if(!done[near]) {
          done[near] = 1;
          bfs.push(near);
        }
      }
    }
    ans = max(ans, 2 * temp[n]);
  }
  printf("%.15lf\n", (double) ans / ways[n]);
  return 0;
}