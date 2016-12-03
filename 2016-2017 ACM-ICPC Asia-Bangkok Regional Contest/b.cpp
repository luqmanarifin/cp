#include <bits/stdc++.h>

using namespace std;

const int N = 62;
const int M = 202, mod = 1e9 + 7;

long long dp[N][M * N];
long long ans[N][M];

int main() {
  cerr << "cuek" << endl;
  for (int f = 1; f < M; f++) {
    dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
      long long sum = 0;
      for (int j = 0; j <= f * i; j++) {
        sum = (sum + dp[i-1][j]) % mod;
        dp[i][j] = sum;
        if (j >= f)
          sum = (sum + mod - dp[i-1][j-f]) % mod;
      }
      ans[i][f] = 0;
      for (int j = 0; j <= f; j++)
        ans[i][f] = (ans[i][f] + dp[i][j * i]) % mod;
    }
  }
  int a, b;
  scanf("%d %d", &a, &b);
  while (a && b) {
    long long anss = (ans[a-1][b] * a) % mod;
    if (anss < 0)
      anss += mod;
    printf("%lld\n", anss);
    scanf("%d %d", &a, &b);
  }
 

  return 0;
}
