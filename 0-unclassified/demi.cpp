#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int inf = 1e9;

int dp[N][2];
vector<int> child[N];

void dfs(int now) {
  dp[now][0] = dp[now][1] = 1;
  int mini = inf, maxi = 0;
  for(auto it : child[now]) {
    dfs(it);
    mini = min(mini, dp[it][0]);
    maxi = max(maxi, dp[it][1]);
  }
  if(mini == inf) mini = 0;
  dp[now][1] += mini;
  dp[now][0] += maxi;
}

int main() {
  int n;
  scanf("%d", &n);
  while(--n) {
    int u, v;
    scanf("%d %d", &u, &v);
    child[u].push_back(v);
  }
  dfs(1);
  printf("%d %d\n", dp[1][0], dp[1][1]);
  return 0;
}
