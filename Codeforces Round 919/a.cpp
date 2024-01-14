#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    set<pair<int, int>> s;
    s.insert(make_pair(1, (int) 1e9));
    for (int i = 0; i < n; i++) {
      int k, v;
      scanf("%d %d", &k, &v);
      set<pair<int, int>> x;
      if (k == 1) {
        for (auto it : s) {
          if (v <= it.second) {
            x.insert(make_pair(max(v, it.first), it.second));
          }
        }
      } else if (k == 2) {
        for (auto it : s) {
          if (it.first <= v) {
            x.insert(make_pair(it.first, min(v, it.second)));
          }
        }
      } else {
        for (auto it : s) {
          if (it.first <= v && v <= it.second) {
            if (it.first <= v - 1) {
              x.insert(make_pair(it.first, v - 1));
            }
            if (v + 1 <= it.second) {
              x.insert(make_pair(v + 1, it.second));
            }
          } else {
            x.insert(it);
          }
        }
      }
      s = x;
    }
    int ans = 0;
    for (auto it : s) ans += it.second - it.first + 1;
    printf("%lld\n", ans);
  }

  return 0;
}
