#include <bits/stdc++.h>

using namespace std;

int ada[505];
long long dp[505][505];
int lim1, lim2;
long long mod;

long long go(int x, int y) {
  if(dp[x][y] != -1) {
    return dp[x][y];
  }
  if(x + y > lim1 + lim2) {
    return dp[x][y] = 0;
  }
  dp[x][y] = go(x + 2, y) * (x + 2) * (x + 1) / 2;
  dp[x][y] %= mod;
  if(x >= 2) {
    dp[x][y] += go(x - 2, y + 2) * (y + 2) * (y + 1) / 2;
    dp[x][y] %= mod;
  }
  if(x >= 1) {
    dp[x][y] += go(x, y + 1) * x * (y + 1);
    dp[x][y] %= mod;
  }
  return dp[x][y];
}

int main() {
  int n, m;
  scanf("%d %d %I64d", &n, &m, &mod);
  for(int i = 0; i < 505; i++) ada[i] = 2;
  while(m--) {
    char s[505];
    scanf("%s", &s[1]);
    for(int i = 1; i <= n; i++) {
      ada[i] -= s[i] - '0';
    }
  }
  for(int i = 1; i <= n; i++) {
    if(ada[i] == 1) lim1++;
    if(ada[i] == 2) lim2++;
  }
  memset(dp, -1, sizeof(dp));
  dp[lim1][lim2] = 1;
  cout << go(0, 0) << endl;
  return 0;
}