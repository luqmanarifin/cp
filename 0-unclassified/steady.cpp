#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9;
const int N = 2005;

long long isi[N];
long long dp[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(isi, 0, sizeof(isi));
    memset(dp, 0, sizeof(dp));
    int n, m;
    scanf("%d %d", &n, &m);
    isi[0] = 1;
    for(int i = 0; i < m; i++) {
      for(int j = 1; j <= m; j++) {
        isi[j] += isi[j - 1];
        isi[j] %= mod;
      }
    }
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
      for(int j = 1; j <= m; j++) {
        dp[j] += dp[j - 1];
        dp[j] %= mod;
      }
      for(int j = 0; j <= m; j++) {
        dp[j] *= isi[j];
        dp[j] %= mod;
      }
    }
    long long ans = 0;
    for(int i = 0; i <= m; i++) {
      ans += dp[i];
      ans %= mod;
    }
    printf("%d\n", (int) ans);
  }
  
  return 0;
}
