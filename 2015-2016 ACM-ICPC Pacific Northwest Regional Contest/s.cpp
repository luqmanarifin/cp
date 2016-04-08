#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

long long dp[N];
int f[N], w[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int m;
    scanf("%d", &m);
    scanf("%d %d", f + m, w + m);
  }
  for(int i = 1; i < N; i++) {
    dp[i] = max(dp[i], dp[i - 1]);
    dp[i + w[i]] = max(dp[i + w[i]], dp[i] + f[i]);
  }
  cout << dp[N - 1] << endl;
  return 0;
}