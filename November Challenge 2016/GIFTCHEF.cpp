#include <bits/stdc++.h>

using namespace std;

const long long PRIME = 71;
const long long mod = 1e9 + 2407;
const int N = 3e5 + 5;

long long h[N], power[N];
char a[N], b[N];
bool ok[N];

long long dp[N];

int main() {
  power[0] = 1;
  for (int i = 1; i < N; i++) {
    power[i] = power[i - 1] * PRIME % mod;
  }
  
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(ok, 0, sizeof(ok));
    memset(dp, 0, sizeof(dp));
    
    scanf("%s %s", a + 1, b + 1);
    int n = strlen(a + 1);
    int m = strlen(b + 1);
    for (int i = 1; i <= n; i++) {
      h[i] = (h[i - 1] * PRIME + a[i] - 'a' + 1) % mod;
    }
    long long good = 0;
    for (int i = 1; i <= m; i++) {
      good = (good * PRIME + b[i] - 'a' + 1) % mod;
    }
    for (int i = 1; i + m - 1 <= n; i++) {
      long long cur = (h[i + m - 1] - h[i - 1] * power[m]) % mod;
      if (cur < 0) cur += mod;
      if (cur == good) {
        ok[i] = 1;
      }
    }
    for (int i = 1; i <= n + 1; i++) {
      dp[i] += dp[i - 1];
      dp[i] %= mod;
      if (ok[i]) {
        dp[i + m] += dp[i] + 1;
        dp[i + m] %= mod;
      }
    }
    long long ans = dp[n + 1];
    //for (int i = 1; i <= n + 1; i++) ans += dp[i];
    ans %= mod;
    cout << ans << endl;
  }

  return 0;
}
