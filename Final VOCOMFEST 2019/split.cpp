#include <bits/stdc++.h>

using namespace std;

const int N = 8005;

map<int, map<int, int>> cnt;
map<int, int> lef;

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    cnt.clear();
    lef.clear();

    for (int i = 0; i < 24; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      cnt[x][y]++;
      lef[x]++;
    }
    vector<int> factors = {1, 2, 3, 4, 6, 8, 12, 24};
    bool perfect = 0;
    for (auto i : factors) {
      auto j = 24 / i;
      bool bad = 0;
      for (auto it : lef) {
        if (it.second % j) {
          bad = 1;
          break;
        }
      }
      if (bad) continue;
      vector<pair<int, int> > base;
      for (auto it : cnt) {
        int copies = lef[it.first] / j;
        bool good = 1;
        vector<pair<int, int> > cur;
        for (auto jt : it.second) {
          if (jt.second % copies) {
            good = 0;
            break;
          }
          cur.emplace_back(jt.first, jt.second / copies);
        }
        if (!good) {
          bad = 1;
          break;
        }
        sort(cur.begin(), cur.end());
        if (base.empty()) {
          base = cur;
        } else {
          if (base != cur) {
            bad = 1;
            break;
          }
        }
      }
      if (bad) continue;
      perfect = 1;
      break;
    }
    printf("Case #%d: %s\n", tt, perfect? "RUN!" : "STAY");
  }

  return 0;
}
