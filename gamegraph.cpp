#include <bits/stdc++.h>

using namespace std;

int dp[18][1 << 18];
bool adj[18][18];
int n, m;

int find(int now, int mask) {
  if(dp[now][mask] != -1) return dp[now][mask];
  int& ret = dp[now][mask] = 1;
  for(int i = 0; i < n; i++) {
    if(adj[now][i] && (mask & (1 << i)) == 0) {
      if(find(i, mask | (1 << i))) {
        ret = 0;
        break;
      }
    }
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(dp, -1, sizeof(dp));
    memset(adj, 0, sizeof(adj));
    scanf("%d %d", &n, &m);
    while(m--) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--, b--;
      adj[a][b] = adj[b][a] = 1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(find(i, 1 << i)) {
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  
  return 0;
}
