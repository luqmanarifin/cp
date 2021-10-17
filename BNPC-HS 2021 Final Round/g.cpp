#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

char s[N];

long long dp[2], dua[N];

int main() {
  dua[0] = 1;
  for (int i = 1; i < N; i++) dua[i] = dua[i-1] * 2 % mod;

  scanf("%s", s);
  int n = strlen(s);
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    int c = s[i] - '0';
    ans += dp[c ^ 1] * dua[i] % mod;
    ans %= mod;
    dp[c] += dua[n - 1 - i];
    dp[c] %= mod;
  }
  cout << ans << endl;
  return 0;
}
