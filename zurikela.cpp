#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], nope[N], dp[N][2];
vector<int> edge[N];

void dfs(int now, int bef) {
  nope[now] = 1;
  dp[now][1] = a[now];
  for(auto it : edge[now]) {
    if(it == bef) continue;
    dfs(it, now);
    dp[now][1] += dp[it][0];
    dp[now][0] += max(dp[it][0], dp[it][1]);
  }
}

int main() {
  int q;
  scanf("%d", &q);
  int num = 0;
  while(q--) {
    char c;
    scanf(" %c", &c);
    if(c == 'A') {
      int u;
      scanf("%d", &u);
      a[++num] = u;
    } else if(c == 'B') {
      int u, v;
      scanf("%d %d", &u, &v);
      assert(u <= num && v <= num);
      if(!nope[u] && !nope[v]) {
        edge[u].push_back(v);
        edge[v].push_back(u);
      } else {
        assert(0);
      }
    } else {
      int u;
      scanf("%d", &u);
      assert(u <= num);
      if(nope[u]) {
        assert(0);
        nope[++num] = 1;
      } else {
        dfs(u, 0);
        a[++num] = max(dp[u][0], dp[u][1]);
      }
    }
  }
  int ans = 0;
  for(int i = 1; i <= num; i++) {
    if(nope[i]) continue;
    dfs(i, 0);
    ans += max(dp[i][0], dp[i][1]);
  }
  cout << ans << endl;
  return 0;
}
