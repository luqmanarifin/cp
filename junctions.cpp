#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int dist[500][500];
int edge[500][500];
int d[500];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(edge, 0, sizeof(edge));
    vector<pair<int, int>> baru;
    
    int n, m;
    scanf("%d %d", &n, &m);
    int node = n;
    while(m--) {
      int a, b;
      scanf("%d %d", &a, &b);
      edge[a][b] = 1;
    }
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        dist[i][j] = inf;
        if(edge[i][j]) {
          dist[i][j] = 1;
        }
      }
      dist[i][i] = 0;
    }
    
    bool done = 0;
    while(!done) {
      for(int k = 1; k <= node; k++) {
        for(int i = 1; i <= node; i++) {
          for(int j = 1; j <= node; j++) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
      memset(d, 0, sizeof(d));
      for(int i = 1; i <= node; i++) {
        for(int j = 1; j <= node; j++) {
          if(i == j) continue;
          d[i] = max(d[i], dist[i][j]);
        }
      }
      bool same = 1;
      int maks = -1;
      for(int i = i; i <= node; i++) {
        if(i >= 2 && d[i] != d[i - 1]) {
          same = 0;
          break;
        }
        maks = max(maks, d[i]);
      }
      if(same) {
        done = 1;
        for(int i = i)
      } else {
        node = n + 1;
        for(int i = 1; i <= n; i++) {
          if(d[i] == maks) {
            baru.emplace_back(i, n + 1);
            edge[i][n + 1] = 1;
            edge[n + 1][i] = 1;
          }
        }
      }
    }
  }

  
  return 0;
}
