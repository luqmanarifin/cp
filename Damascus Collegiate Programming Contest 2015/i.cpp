#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int N = 105;

long long dist[N];
bool edge[N][N];
long long a[N], b[N], p[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(p, 0, sizeof(p));
    memset(edge, 0, sizeof(edge));
    
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
      scanf("%I64d %I64d %I64d", a + i, b + i, p + i);
    }
    scanf("%I64d %I64d %I64d %I64d", &a[0], &b[0], &a[n + 1], &b[n + 1]);
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(p[i] * p[i] >= (a[i] - a[j])*(a[i] - a[j]) + (b[i] - b[j])*(b[i] - b[j])) {
          edge[i][j] = 1;
        }
      }
    }
    for(int i = 0; i < N; i++) dist[i] = inf;
    priority_queue<pair<long long, int>> pq;
    dist[0] = 0;
    pq.emplace(0, 0);
    while(!pq.empty()) {
      long long cost; int now;
      tie(cost, now) = pq.top();
      cost = -cost;
      pq.pop();
      if(dist[now] != cost) continue;
      for(int i = 0; i <= n + 1; i++) {
        long long ncos = cost + abs(a[now] - a[i]) + abs(b[now] - b[i]);
        if(ncos < dist[i]) {
          dist[i] = ncos;
          pq.emplace(-dist[i], i);
        }
        if(edge[now][i]) {
          ncos = cost + 2;
          if(ncos < dist[i]) {
            dist[i] = ncos;
            pq.emplace(-dist[i], i);
          }
        }
      }
    }
    printf("%I64d\n", dist[n + 1]);
  }
  return 0;
}
