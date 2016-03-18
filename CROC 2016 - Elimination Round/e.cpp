#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 2e6 + 5;

int last[26];
char s[N];
long long dp[N];

int main() {
  int n, k;
  scanf("%d %d %s", &n, &k, s + 1);
  int m = strlen(s + 1);
  for(int i = 1; i <= m; i++) {
    int c = s[i] - 'a';
    last[c] = i;
  }
  vector<pair<int, int>> p;
  for(int i = 0; i < k; i++) {
    p.emplace_back(last[i], i);
  }
  sort(p.begin(), p.end());
  for(int i = 0; i < n; i++) {
    s[m + 1 + i] = p[i % p.size()].second + 'a';
  }
  dp[0] = 1;
  memset(last, 0, sizeof(last));
  for(int i = 1; i <= n + m; i++) {
    dp[i] = dp[i - 1] * 2 % mod;
    int c = s[i] - 'a';
    if (last[c] != 0) dp[i] = (dp[i] - dp[last[c] - 1] + mod) % mod;
    last[c] = i;
  }
  cout << dp[n + m] << endl;
  return 0;
}
