#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

vector<pair<int, int>> edge[N];
vector<int> delay[N];
vector<int> to[N];

long long dist[N];

int get(int i, long long time) {
  int id = lower_bound(delay[i].begin(), delay[i].end(), time) - delay[i].begin();
  if(!(0 <= id && id < delay[i].size())) return -1;
  return (delay[i][id] == time? id : -1);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    edge[a].emplace_back(b, c);
    edge[b].emplace_back(a, c);
  }
  for(int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    for(int j = 0; j < k; j++) {
      int a;
      scanf("%d", &a);
      delay[i].push_back(a);
    }
    to[i].resize(k);
    for(int j = k - 1; j >= 0; j--) {
      if(j + 1 < k && delay[i][j] + 1 == delay[i][j + 1]) {
        to[i][j] = to[i][j + 1];
      } else {
        to[i][j] = delay[i][j] + 1;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    dist[i] = inf;
  }
  priority_queue<pair<long long, int>> pq;
  pq.emplace(0, 1);
  dist[1] = 0;
  while(!pq.empty()) {
    long long cost; int now;
    tie(cost, now) = pq.top();
    pq.pop();
    cost = -cost;
    if(dist[now] != cost) {
      continue;
    }
    if(now == n) {
      cout << cost << endl;
      return 0;
    }
    int come = get(now, cost);
    if(come != -1) { 
      dist[now] = to[now][come];
      pq.emplace(-dist[now], now);
      continue;
    }
    for(auto it : edge[now]) {
      int near = it.first;
      long long will = cost + it.second;
      if(will < dist[near]) {
        dist[near] = will;
        pq.emplace(-dist[near], near);
      }
    }
  }
  puts("-1");
  return 0;
}
