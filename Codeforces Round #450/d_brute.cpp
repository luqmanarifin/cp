
#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 155;

long long dp[N][N];
int goal, sumgoal;

long long dfs(int gcd, int sum) {
  if (gcd % goal) return 0;
  if (sum == 0) return gcd == goal;
  if (dp[gcd][sum] != -1) return dp[gcd][sum];
  dp[gcd][sum] = 0;
  for (int i = 1; i <= sum; i++) {
    dp[gcd][sum] += dfs(__gcd(gcd, i), sum - i);
    dp[gcd][sum] %= mod;
  }
  return dp[gcd][sum];
}

int main() {
  for (int i = 1; i <= 100; i++) {
    goal = i;
    memset(dp, -1, sizeof(dp));
    for (int j = 1; j <= 100; j++) {
      long long ans = 0;
      sumgoal = j;
      ans += dfs(0, j);
      printf("%d %d: %d\n", i, j, (int) ans);
    }
  }

  return 0;
}
