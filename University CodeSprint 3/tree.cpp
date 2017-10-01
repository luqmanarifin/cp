#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], dp[N][2], stop[N][2], dad[N];
vector<int> edge[N];
int best, at, pos;  // pos 1 positif

void dfs(int now, int bef) {
  dad[now] = bef;
  for (auto it : edge[now]) if (it != bef) dfs(it, now);
  int cur[2] = {};
  for (auto it : edge[now]) if (it != bef) {
    cur[0] += dp[it][0];
    cur[1] += dp[it][1];
  }
  if (a[now]) {
    cur[0]++;
    cur[1]++;
  } else {
    cur[0]--;
    cur[1]--;
  }
  if (dp[now][1] < cur[1]) {
    dp[now][1] = cur[1];
  } else {
    stop[now][1] = 1;
  }
  if (dp[now][0] > cur[0]) {
    dp[now][0] = cur[0];
  } else {
    stop[now][0] = 1;
  }
  if (dp[now][1] > best) {
    best = dp[now][1];
    at = now;
    pos = 1;
  }
  if (-dp[now][0] > best) {
    best = -dp[now][0];
    at = now;
    pos = 0;
  }
}

vector<int> ans;

void backtrack(int now, int bef) {
  if (stop[now][pos]) return;
  ans.push_back(now);
  for (auto it : edge[now]) if (it != bef) {
    backtrack(it, now);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0);
  backtrack(at, dad[at]);
  printf("%d\n", best);
  printf("%d\n", ans.size());
  for (auto it : ans) printf("%d ", it);
  return 0;
}
