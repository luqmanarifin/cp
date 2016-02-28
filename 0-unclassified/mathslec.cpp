#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

long long mod;
long long ten[N];
long long tenmod[N];
long long dp[N][105][2];
int n, k;

long long go(int pos, int rem, int st) {
  if(dp[pos][rem][st] != -1) {
    return dp[pos][rem][st];
  }
  if(rem == 0 && st) {
    if(pos == n) {
      return dp[pos][rem][st] = 1;
    } else {
      return dp[pos][rem][st] = (tenmod[n - pos - 1] * 9) % mod;
    }
  }
  if(pos == n) {
    return dp[pos][rem][st] = 0;
  }
  dp[pos][rem][st] = 0;
  if(pos < n) {
    dp[pos][rem][st] += go(pos + 1, rem, st);
  }
  for(int i = 1; i <= 9; i++) {
    dp[pos][rem][st] += go(pos + 1, (i * ten[pos] + rem) % k, 1);
    dp[pos][rem][st] %= mod;
  }
  return dp[pos][rem][st];
}

int main() {
  scanf("%d %d %I64d", &n, &k, &mod);
  ten[0] = 1 % k;
  tenmod[0] = 1 % mod;
  for(int i = 1; i < N; i++) {
    ten[i] = ten[i - 1] * 10;
    ten[i] %= k;
    tenmod[i] = tenmod[i - 1] * 10;
    tenmod[i] %= mod;
  }
  memset(dp, -1, sizeof(dp));
  cout << go(0, 0, 0) << endl;
  return 0;
}