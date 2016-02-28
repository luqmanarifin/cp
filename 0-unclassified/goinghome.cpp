#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;
const long long inf = 1e18;

long long up[N], down[N];
vector<pair<int, int> > upward[N], backward[N];
 
void djiktra(int source, long long* dist, vector<pair<int, int> >* edge) {
  for(int i = 0; i < N; i++) {
    dist[i] = inf;
  }
  dist[source] = 0;
  priority_queue<pair<long long, int> > pq;
  pq.push(make_pair(0, source));
  while(!pq.empty()) {
    long long cur = pq.top().first;
    int now = pq.top().second;
    cur = -cur;
    pq.pop();
    for(int i = 0; i < edge[now].size(); i++) {
      long long ncos = edge[now][i].second;
      int near = edge[now][i].first;
      if(cur + ncos < dist[near]) {
        dist[near] = cur + ncos;
        pq.push(make_pair(-dist[near], near));
      }
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    printf("Case #%d:\n", tt);
    for(int i = 0; i < N; i++) {
      upward[i].clear();
      backward[i].clear();
    }
    
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    while(m--) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      upward[a].push_back(make_pair(b, c));
      backward[b].push_back(make_pair(a, c));
    }
    djiktra(0, up, upward);
    djiktra(n - 1, down, backward);
    assert(up[n - 1] == down[0]);
    while(q--) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      long long cur = up[x] + down[y] + z;
      if(cur < up[n - 1]) {
        puts("YES");
      } else {
        puts("NO");
      }
    }
    
  }
  
  return 0;
}
