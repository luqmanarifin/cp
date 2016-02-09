#include <bits/stdc++.h>

using namespace std;

bool collision(int a, int b, int c, int d) {
  if(c < a) return collision(c, d, a, b);
  return c <= b;
}

int get(int a, int b, int c, int d, int e, int f, int g, int h) {
  int dx = (collision(a, c, e, g)? 0 : min(abs(c - e) - 1, abs(a - g) - 1));
  int dy = (collision(b, d, f, h)? 0 : min(abs(d - f) - 1, abs(b - h) - 1));
  return max(dx, dy);
}

const int N = 1005;
const long long inf = 1e9;

int a[N], b[N], c[N], d[N];
int tul[N][N];
long long dist[N];

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= k; i++) {
      scanf("%d %d %d %d", a + i, b + i, c + i, d + i);
    }
    a[0] = -1, b[0] = 0, c[0] = -1, d[0] = m - 1;
    a[k + 1] = n, b[k + 1] = 0, c[k + 1] = n; d[k + 1] = m - 1;
    
    for(int i = 0; i <= k + 1; i++) {
      for(int j = 0; j <= k + 1; j++) {
        tul[i][j] = get(a[i], b[i], c[i], d[i], a[j], b[j], c[j], d[j]);
      }
    }
    
    /*
    for(int i = 0; i <= k + 1; i++) {
      for(int j = i + 1; j <= k + 1; j++) {
        assert(tul[i][j] == tul[j][i]);
        printf("jarak %d %d : %d\n", i, j, tul[i][j]);
      }
    }
    */
    
    for(int i = 0; i < N; i++) dist[i] = inf;
    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, 0);
    dist[0] = 0;
    while(!pq.empty()) {
      long long cost; int now;
      tie(cost, now) = pq.top();
      pq.pop();
      cost = -cost;
      if(dist[now] != cost) continue;
      if(now == k + 1) {
        break;
      }
      for(int i = 0; i <= k + 1; i++) {
        int ncos = tul[now][i];
        if(cost + ncos < dist[i]) {
          dist[i] = cost + ncos;
          pq.emplace(-dist[i], i);
        }
      }
    }
    printf("Case #%d: %I64d\n", tt, dist[k + 1]);
  }
  
  return 0;
}
