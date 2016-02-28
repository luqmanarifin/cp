#include <bits/stdc++.h>

using namespace std;

const int N = 5055;
const int mod = 1e9 + 7;
const long long MOD = 2e9 + 89;
const long long prime = 73;

char s[N];
int e[N][N];
long long dp[N][N];
int n;

// compare fucking a_b and c_d in O(1)
// return true if a_b >= c_d
inline bool compare(int a, int b, int c, int d) {
  if(b - a > d - c) return 1;
  if(b - a < d - c) return 0;
  int fd = e[a][c];
  if(a + fd > b || c + fd > d) return 1;
  assert(s[a + fd] != s[c + fd]);
  return s[a + fd] > s[c + fd];
}

int main() {
  scanf("%d %s", &n, s + 1);
  for(int i = 1; i <= n; i++) {
    dp[1][i] = 1;
  }
  for(int i = n; i >= 1; i--) {
    for(int j = i; j >= 1; j--) {
      if(s[i] == s[j]) {
        e[j][i] = e[j + 1][i + 1] + 1;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    int k = i + 1;
    for(int j = i; j >= 1; j--) {
      if(s[j] == '0') {
        dp[j][i] = 0;
        continue;
      }
      while(k <= n && compare(j, i, i + 1, k)) k++;
      dp[i + 1][k] += dp[j][i];
      dp[i + 1][k] %= mod;
    }
    for(int j = i + 1; j <= n; j++) {
      dp[i + 1][j] += dp[i + 1][j - 1];
      dp[i + 1][j] %= mod;
    }
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    ans += dp[i][n];
  }
  cout << ans % mod << endl;
  return 0;
}
