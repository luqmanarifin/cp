#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5;
const int magic = 170;
const int inf = 1e9;

bool vis[N];
bool done[magic][magic];
vector<int> p[N];
int dist[N];

int main() {
  for(int i = 0; i < N; i++) {
    dist[i] = inf;
  }
  
  int n, m;
  scanf("%d %d", &n, &m);
  int goal = -1, start= -1;
  for(int i = 0; i < m; i++) {
    int b, sebar;
    scanf("%d %d", &b, &sebar);
    p[b].push_back(sebar);
    if(i == 0) {
      start = b;
    } else if(i == 1) {
      goal = b;
    }
  }
  
  bool reachable = 0;
  stack<int> st;
  st.push(start);
  vis[start] = 1;
  while(!st.empty()) {
    int now = st.top();
    st.pop();
    if(now == goal) {
      reachable = 1;
      break;
    }
    for(auto it : p[now]) {
      if(it < magic) {
        if(done[it][now % it]) {
          continue;
        }
        done[it][now % it] = 1;
      }
      for(int i = now + it; i < n; i += it) {
        if(!vis[i]) {
          vis[i] = 1;
          st.push(i);
        }
      }
      for(int i = now - it; i >= 0; i -= it) {
        if(!vis[i]) {
          vis[i] = 1;
          st.push(i);
        }
      }
    }
  }
  if(!reachable) {
    puts("-1");
    return 0;
  }
  
  priority_queue<pair<int, int>> pq;
  pq.emplace(0, -start);
  dist[start] = 0;
  while(!pq.empty()) {
    int cost, now;
    tie(cost, now) = pq.top();
    pq.pop();
    cost = -cost; now = -now;
    if(cost != dist[now]) {
      continue;
    }
    if(now == goal) {
      printf("%d\n", cost);
      return 0;
    }
    for(auto it : p[now]) {
      int d = 0;
      for(int i = now + it; i < n; i += it) {
        d++;
        if(cost + d < dist[i]) {
          dist[i] = cost + d;
          pq.emplace(-dist[i], -i);
        }
      }
      d = 0;
      for(int i = now - it; i >= 0; i -= it) {
        d++;
        if(cost + d < dist[i]) {
          dist[i] = cost + d;
          pq.emplace(-dist[i], -i);
        }
      }
    }
  }
  puts("-1");
  return 0;
}
