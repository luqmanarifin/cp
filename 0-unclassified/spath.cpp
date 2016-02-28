#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int N = 1e5 + 5;

long long dist[N][2];
int last[N][2];
vector<tuple<int,int,int>> edge[N];

bool ada(long long cost, int now, int color) {
  for(int i = 0; i < 2; i++) {
    if(dist[now][i] == cost && last[now][i] == color) {
      return 1;
    }
  }
  return 0;
}

void normalize(int now) {
  if(dist[now][1] < dist[now][0]) {
    swap(dist[now][1], dist[now][0]);
    swap(last[now][1], last[now][0]);
  }
}

int main() {
  int n, m, c;
  scanf("%d %d %d", &n, &m, &c);
  while(m--) {
    int v, u, w, cok;
    scanf("%d %d %d %d", &v, &u, &w, &cok);
    edge[v].emplace_back(u, w, cok);
  }
  int start, q;
  scanf("%d %d", &start, &q);
  
  for(int i = 0; i < N; i++) {
    dist[i][0] = dist[i][1] = inf;
  }
  // cost - vertex - color
  priority_queue<tuple<long long, int, int>> pq;
  dist[start][0] = 0;
  last[start][0] = -1;
  pq.emplace(0, start, -1);
  while(!pq.empty()) {
    long long cost; int now, color;
    tie(cost, now, color) = pq.top();
    pq.pop();
    cost = -cost;
    if(!ada(cost, now, color)) {
      continue;
    }
    for(auto it : edge[now]) {
      int ncos, to, ncol;
      tie(to, ncos, ncol) = it;
      if(color == ncol) {
        continue;
      }
      if(ncol == last[to][0]) {
        if(cost + ncos < dist[to][0]) {
          dist[to][0] = cost + ncos;
          pq.emplace(-dist[to][0], to, ncol);
        }
      } else if(ncol == last[to][1]) {
        if(cost + ncos < dist[to][1]) {
          dist[to][1] = cost + ncos;
          pq.emplace(-dist[to][1], to, ncol);
        }
      } else {
        if(cost + ncos < dist[to][0]) {
          dist[to][1] = dist[to][0];
          last[to][1] = last[to][0];
          dist[to][0] = cost + ncos;
          last[to][0] = ncol;
          pq.emplace(-dist[to][0], to, ncol);
        } else if(cost + ncos < dist[to][1]) {
          dist[to][1] = cost + ncos;
          last[to][1] = ncol;
          pq.emplace(-dist[to][1], to, ncol);
        }
      }
      normalize(to);
    }
  }
  
  while(q--) {
    int t;
    scanf("%d", &t);
    printf("%I64d\n", (dist[t][0] == inf? -1 : dist[t][0]));
  }
  
  return 0;
}
