#include <bits/stdc++.h>

using namespace std;

const int N = 55;

long long sum(int n) {
  return 1LL * n * (n + 1) / 2;
}

long long sum(int l, int r) {
  return sum(r) - sum(l - 1);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, k;
    scanf("%d %d", &n, &k);
    int best = k;
    int now = k - 1;
    int tot = 0;
    for (int i = 2; i <= n; i++) {
      tot += now;
      if (now <= 1) break;
      now--;
    }
    vector<tuple<int, int, int>> ans;
    if (best >= tot || k == 1 || n == 2) {
      ans.emplace_back(1, n, 1);
    } else {
      ans.emplace_back(1, n, k);
      int now = k - 1;
      for (int i = 2; i <= n; i++) {
        if (now == 1) {
          ans.emplace_back(i - 1, n, now);
          break;
        }
        ans.emplace_back(i - 1, i, now);
        now--;
      }
    }
    printf("Case #%d: %d\n", tt, max(0, tot - best));
    printf("%d\n", ans.size());
    for (auto it : ans) {
      int u, v, w;
      tie(u, v, w) = it;
      printf("%d %d %d\n", u, v, w);
    }
  }
  return 0;
}
