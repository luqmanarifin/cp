#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 5;
const long long inf = 1e18;

long long dp[N];

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < N; i++) dp[i] = inf;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + a;
    if (i % 2 == 0) {
      dp[i] = min(dp[i], dp[i / 2] + b);
    } else {
      dp[i] = min(dp[i], min(dp[i / 2], dp[(i + 1) / 2]) + a + b);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
