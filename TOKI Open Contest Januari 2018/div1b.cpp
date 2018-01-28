#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 1e9 + 7;

vector<int> edge[N];
int ada[N];
long long dp[N][2], tmp[2];
long long ans;

void dfs(int now, int bef) {
  for (auto it : edge[now]) if (it != bef) dfs(it, now);
  dp[now][ada[now]] = 1;
  for (auto it : edge[now]) {
    if (it == bef) continue;
    dp[it][0]++;
    
    tmp[0] = tmp[1] = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        tmp[i | j] += dp[now][i] * dp[it][j];
        tmp[i | j] %= mod;
      }
    }
    dp[now][0] = tmp[0];
    dp[now][1] = tmp[1];
  }
  ans += dp[now][1];
  ans %= mod;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  while (k--) {
    int v;
    scanf("%d", &v);
    ada[v] = 1;
  }
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}
