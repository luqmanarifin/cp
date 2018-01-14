#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
int dp[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  vector<pair<int, int>> num;
  for (int i = 0; i < n; i++) {
    num.emplace_back(edge[i].size(), i);
  }
  fill(dp, dp + N, 1);
  sort(num.begin(), num.end());
  int ans = 1;
  for (auto i : num) {
    int now = i.second;
    for (auto it : edge[now]) {
      if (edge[it].size() > edge[now].size()) {
        dp[it] = max(dp[it], dp[now] + 1);
        ans = max(ans, dp[it]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
