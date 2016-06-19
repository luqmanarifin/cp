#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

vector<vector<vector<int>>> dp;

int a[15];

int main() {
  int n, l;
  scanf("%d %d", &n, &l);
  dp.resize(1 << n);
  for(int i = 0; i < (1 << n); i++) {
    dp[i].resize(n + 1);
    for(int j = 0; j <= n; j++) {
      dp[i][j].resize(l + 1);
    }
  }


  for(int i = 0; i < n; i++) scanf("%d", a + i);
  for(int i = 0; i < n; i++) {
    dp[1 << i][i][0] = 1;
  }
  for(int mask = 0; mask < (1 << n) - 1; mask++) {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < l; j++) {
        if(dp[mask][i][j] == 0) continue;
        int now = dp[mask][i][j];
        for(int k = 0; k < n; k++) {
          if((mask & (1 << k)) == 0) {
            if(j + abs(a[i] - a[k]) <= l) {
              int& cur = dp[mask | (1 << k)][k][j + abs(a[i] - a[k])];
              cur += dp[mask][i][j];
              cur %= mod;
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= l; j++) {
      ans += dp[(1 << n) - 1][i][j];
      ans %= mod;
    }
  }  
  cout << ans << endl;
  return 0;
}
