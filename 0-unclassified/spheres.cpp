#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
const int mod = 1e9 + 7;

long long dp[N][N];
int a[N], b[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    a[num]++;
  }
  for(int i = 0; i < m; i++) {
    int num;
    scanf("%d", &num);
    b[num]++;
  }
  for(int i = 0; i < N; i++) {
    dp[i][0] = (1LL * a[i] * b[i]) % mod;
  }
  for(int i = 1; i <= k; i++) {
    long long sum = 0;
    for(int j = 0; j < N; j++) {
      dp[j][i] = sum * dp[j][0] % mod;
      sum += dp[j][i - 1];
      sum %= mod;
    }
  }
  for(int i = 1; i <= k; i++) {
    long long ans = 0;
    for(int j = 0; j < N; j++) {
      ans += dp[j][i];
    }
    printf("%lld ", ans % mod);
  }
  return 0;
}
