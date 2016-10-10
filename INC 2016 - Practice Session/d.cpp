#include <bits/stdc++.h>

using namespace std;

const int N = 16;
const int inf = 1e9;

int a[N][N], n;
int ans;
vector<int> st[N];

int find(int p, int q, int r) {
  return a[p][q] + a[q][r] + a[r][p];
}

void dfs(int now) {
  if (now == 3 * n) {
    int cur = inf;
    for (int i = 0; i < n; i++) {
      cur = min(cur, find(st[i][0], st[i][1], st[i][2]));
    }
    ans = max(ans, cur);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (st[i].size() + 1 <= 3) {
      st[i].push_back(now);
      dfs(now + 1);
      st[i].pop_back();
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    scanf("%d", &n);
    for (int i = 0; i < 3 * n; i++) {
      for (int j = 0; j < 3 * n; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    ans = 0;
    dfs(0);
    printf("Case #%d: %d\n", tt, ans);
  }

  return 0;
}
