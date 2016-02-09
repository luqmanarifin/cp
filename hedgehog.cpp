#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], dp[N];
vector<int> edge[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while(m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  for(int i = 1; i <= n; i++) {
    dp[i] = 1;
  }
  for(int i = 1; i <= n; i++) {
    for(auto it : edge[i]) {
      if(it > i) {
        dp[it] = max(dp[it], dp[i] + 1);
      }
    }
  }
  long long ans = 0;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, 1LL * dp[i] * edge[i].size());
  }
  cout << ans << endl;
  return 0;
}
