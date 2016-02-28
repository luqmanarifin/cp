#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int inf = 1e9;

int a[N];
int dist[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    int maxi = 0;
    for(int i = 1; i <= n; i++) {
      int num, val;
      scanf("%d %d", &num, &val);
      a[num] = val;
      maxi = max(maxi, val);
    }
    for(int i = 1; i <= maxi; i++) {
      for(int j = 1; j <= maxi; j++) {
        dist[i][j] = inf;
      }
      dist[i][i] = 0;
    }
    
    int q;
    scanf("%d", &q);
    while(q--) {
      int u, v;
      scanf("%d %d", &u, &v);
      dist[u][v] = dist[v][u] = 1;
    }

    for(int k = 1; k <= n; k++) {
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      ans += dist[a[i]][i];
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
