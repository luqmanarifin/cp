#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const long long mod = 1e9 + 7;

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long p[26], tp[26];
char s[N];
long long dp[N][N];

long long add(long long& at, long long val) {
  at += val;
  if (at >= mod) at -= mod;
}

int main() {
  int n, m;
  scanf("%d %d %s", &n, &m, s);
  for (int i = 0; i < 26; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    p[i] = 1LL * a * inv(b) % mod;
    tp[i] = (1 - p[i] + mod) % mod;
    // printf("%c %lld %lld\n", i + 'a', p[i], tp[i]);
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      add(dp[i+1][j+1], dp[i][j] * p[s[j]-'a'] % mod);
      add(dp[i+1][j], dp[i][j] * tp[s[j]-'a'] % mod);
    }
    add(dp[i+1][m], dp[i][m]);
  }
  cout << dp[n][m] << endl;
  return 0;
}
