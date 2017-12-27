#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> edge[N];
int to[N], dp[N], a[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[v].push_back(u);
    to[u]++;
  }
  queue<int> q;
  for (int i = 0; i < n; i++) if (to[i] == 0) {
    q.push(i);
    dp[i] = a[i];
  }
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto it : edge[now]) {
      dp[it] = max(dp[it], dp[now] + (a[now] == 0 && a[it] == 1));
      to[it]--;
      if (to[it] == 0) {
        q.push(it);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
  cout << ans << endl;
  return 0;
}
