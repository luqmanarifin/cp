#include <bits/stdc++.h>

using namespace std;

const int N = 405;

vector<pair<int, int>> edge[N];
int dp[N][N], n, k, dad[N], iddad[N];
vector<pair<int, int>> back[N][N];
vector<int> ret;

void dfs(int now, int bef) {
  dad[now] = bef;
  dp[now][1] = (bef? 1 : 0);
  for (auto it : edge[now]) {
    int near = it.first;
    if (bef == near) continue;
    iddad[near] = it.second;
    dfs(near, now);
    for (int i = k; i >= 1; i--) {
      dp[now][i]++;
      for (int j = 1; j < i; j++) {
        if (dp[now][i] > dp[now][i-j] + dp[near][j] - 1) {
          dp[now][i] = dp[now][i-j] + dp[near][j] - 1;
          back[now][i].clear();
          back[now][i].emplace_back(near, j);
          for (auto p : back[now][i-j]) {
            back[now][i].push_back(p);
          }
        }
      }
    }
  }
}

void solve(int now, int val, int bef, int first = 1) {
  //printf("pip %d %d\n", now, val);
  if (first && bef) {
    //puts("anjing");
    ret.push_back(iddad[now]);
  }
  set<int> used;
  for (auto it : back[now][val]) {
    used.insert(it.first);
    solve(it.first, it.second, now, 0);
  }
  for (auto it : edge[now]) {
    if (it.first == bef) continue;
    if (!used.count(it.first)) {
      //puts("kuda");
      ret.push_back(it.second);
    }
  }
}

int main() {
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[i][j] = 1e9;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].emplace_back(v, i);
    edge[v].emplace_back(u, i);
  }
  dfs(1, 0);
  int ans = 1e9, p = -1;
  for (int i = 1; i <= n; i++) {
    //printf("holy %d %d\n", i, dp[i][k]);
    if (dp[i][k] < ans) {
      ans = dp[i][k];
      p = i;
    }
  }
  //printf("ans %d %d\n", ans, p);
  solve(p, k, dad[p]);
  printf("%d\n", ans);
  assert(ans == ret.size());
  for (int i = 0; i < ret.size(); i++) {
    if (i) printf(" ");
    printf("%d", ret[i]);
  }
  printf("\n");
  return 0;
}
