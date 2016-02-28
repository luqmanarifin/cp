#include <bits/stdc++.h>

using namespace std;

const int N = 205;

// presum
int pre[N][N];

// basic
int dp[N][2];
// presum awal
int b[N][N][2];
// berapa kali swap
int swap[N][N];

int a[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(pre, 0, sizeof(pre));
    memset(dp, 0, sizeof(dp));
    memset(b, 0, sizeof(b));
    memset(swap, 0, sizeof(swap));
    
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        scanf("%d", &a[i][j]);
        a[i][j] %= 2;
        pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        dp[i][pre[i][j] % 2]++;
        b[i][j][0] = dp[i][j][0];
        b[i][j][1] = dp[i][j][1];
      }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        swap[i][j] += swap[i][j - 1];
        
      }
    }
  } 
  return 0;
}
