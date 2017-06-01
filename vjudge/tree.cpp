#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

vector<int> edge[N];
int x[N], n;
long long dp[N][2], tmp[2];

void dfs(int now, int bef) {
  dp[now][x[now]] = 1;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dfs(it, now);
    memset(tmp, 0, sizeof(tmp));
    tmp[0] += dp[now][0] * dp[it][0];
    tmp[1] += dp[now][1] * dp[it][0];
    tmp[1] += dp[now][0] * dp[it][1];
    tmp[0] += dp[now][0] * dp[it][1];
    tmp[1] += dp[now][1] * dp[it][1];
    
    dp[now][0] = tmp[0] % mod;
    dp[now][1] = tmp[1] % mod;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    edge[p].push_back(i);
  }
  for (int i = 0; i < n; i++) scanf("%d", x + i);
  dfs(0, -1);
  cout << dp[0][1] << endl;
  return 0;
}
