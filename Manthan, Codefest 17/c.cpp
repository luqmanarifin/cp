#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

// 0 - kurang dari sesuatu
// 1 - sesuatu
// 2 - lebih dari sesuatu
long long dp[N][15][3];
long long bef[15][3];
vector<int> edge[N];
int n, m, k, x;

void dfs(int now, int dad) {
  dp[now][0][2] = m - k;
  dp[now][1][1] = 1;
  dp[now][0][0] = k - 1;
  for (auto it : edge[now]) {
    if (it == dad) continue;
    dfs(it, now);
    for (int j = 0; j <= x; j++) {
      for (int l = 0; l < 3; l++) {
        bef[j][l] = dp[now][j][l];
        dp[now][j][l] = 0;
      }
    }
    for (int i = 0; i <= x; i++) {
      for (int j = 0; j <= i; j++) {
        dp[now][i][0] += bef[i - j][0] * (dp[it][j][0] + dp[it][j][1] + dp[it][j][2]);
        dp[now][i][1] += bef[i - j][1] * (dp[it][j][0]);
        dp[now][i][2] += bef[i - j][2] * (dp[it][j][0] + dp[it][j][2]);

        dp[now][i][0] %= mod;
        dp[now][i][1] %= mod;
        dp[now][i][2] %= mod;
      }
    } 
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  scanf("%d %d", &k, &x);
  dfs(1, 0);
  long long ans = 0;
  for (int i = 0; i <= x; i++) {
    //printf("ada %d: %lld %lld %lld\n", i, dp[1][i][0], dp[1][i][1], dp[1][i][2]);
    ans += dp[1][i][0] + dp[1][i][1] + dp[1][i][2];
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
