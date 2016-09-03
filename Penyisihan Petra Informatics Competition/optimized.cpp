#include <bits/stdc++.h>

using namespace std;

const int N = 12;

int dp[N][1 << N][255];
int d[N][N];
int a[N];
vector<pair<int, int> > to[N];
vector<int> b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++) {
      to[i].clear();
      b[i].clear();
    }
    
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      for (int j = 0; j < n; j++) {
        scanf("%d", &d[i][j]);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; i++) {
        if (d[i][j] > 0) {
          to[i].emplace_back(j, d[i][j]);
        }
      }
    }
    
    dp[0][1][m] = a[0];
    for (int k = m; k >= 0; k--) {
      for (int i = 0; i < n; i++) {
        
      }
    }
  }

  return 0;
}
