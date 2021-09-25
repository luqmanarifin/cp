#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> a(n + 1, vector<int>(m));
    vector<map<int, int>> cnt(n + 1);
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
        cnt[i][a[i][j]]++;
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int change = m;
      for (auto it : cnt[i]) {
        int v = it.first;
        int same = min(cnt[i][v], cnt[i-1][v]);
        change -= same;
      }
      ans += change;
    }
    int need_stagnan = 0;
    for (auto it : cnt[0]) {
      int v = it.first;
      int pure = cnt[0][v], foreign = 0;
      for (int i = 1; i <= n; i++) {
        if (cnt[i-1][v] <= cnt[i][v]) {
          foreign = cnt[i][v] - pure;
        } else {
          foreign = min(foreign, cnt[i][v]);
          pure = cnt[i][v] - foreign;
        }
      }
      // printf("v %d: pure %d\n", v, pure);
      need_stagnan += pure;
    }
    ans -= m - need_stagnan;
    printf("Case #%d: %d\n", tt, ans);
  }

  return 0;
}
