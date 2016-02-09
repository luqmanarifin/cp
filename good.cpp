#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

int n, m;
vector<int> edge[N];
int to[2 * N];
int st[2 * N];
bool done[2 * N];
bool entered[2 * N];
vector<tuple<int, int, int>> ans;

int dist[N];
int good[N];
int back[N];

void backtrack(int now) {
  if(now == 1) {
    return;
  }
  int id = back[now];
  done[id] = done[id ^ 1] = 1;
  backtrack(to[id]);
}

int main() {
  scanf("%d %d", &n, &m);
  int id = 0;
  for(int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    to[id] = b;
    st[id] = c;
    edge[a].push_back(id);
    id++;
    
    to[id] = a;
    st[id] = c;
    edge[b].push_back(id);
    id++;
  }
  for(int i = 0; i < N; i++) {
    dist[i] = inf;
    good[i] = -inf;
  }
  
  priority_queue<tuple<int, int, int>> pq;
  dist[1] = 0;
  good[1] = 0;
  pq.emplace(0, 0, 1);
  while(!pq.empty()) {
    int cost, fine, now;
    tie(cost, fine, now) = pq.top();
    pq.pop();
    cost = -cost;
    if(cost != dist[now] || fine != good[now]) {
      continue;
    }
    for(auto id : edge[now]) {
      int near = to[id];
      int stat = st[id];
      if(cost + 1 < dist[near] || (cost + 1 == dist[near] && fine + stat > good[near])) {
        dist[near] = cost + 1;
        good[near] = fine + stat;
        pq.emplace(-dist[near], good[near], near);
        back[near] = id ^ 1;
      }
    }
  }
  backtrack(n);
  for(int i = 1; i <= n; i++) {
    for(auto id : edge[i]) {
      if(done[id] && !entered[id] && st[id] == 0) {
        ans.emplace_back(i, to[id], 1);
        entered[id] = entered[id ^ 1] = 1;
      }
      if(!done[id] && !entered[id] && st[id] == 1) {
        ans.emplace_back(i, to[id], 0);
        entered[id] = entered[id ^ 1] = 1;
      }
    }
  }
  cout << ans.size() << endl;
  for(auto it : ans) {
    int a, b, c;
    tie(a, b, c) = it;
    printf("%d %d %d\n", a, b, c);
  }
  
  return 0;
}