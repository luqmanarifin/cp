#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const long long inf = (1LL << 62) - 1;

// dp[pos][how many group have been created]
long long dp[N][N];
long long num[N];

long long get(int i, int j) {
  return num[j] - num[i - 1];
}

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for(int i = 1; i <= n; i++) {
    scanf("%lld", &num[i]);
    num[i] += num[i - 1];
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= b; j++) {
      for(int k = 0; k < i; k++) {
        if(j == 1 & k != 0) continue;
        dp[i][j] = min(dp[i][j], (dp[k][j - 1] | get(k + 1, i)));
      }
    }
  }
  long long ans = inf;
  for(int i = a; i <= b; i++) {
    ans = min(ans, dp[n][i]);
  }
  cout << ans << endl;
  return 0;
}
