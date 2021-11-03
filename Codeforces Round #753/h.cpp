#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int LEN = 2e6 + 5;

long long a[N], b[N], m[N], xa[N], xb[N];
vector<tuple<int, int, int>> seg[LEN];
bool done[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    set<int> pos;
    for (int i = 0; i < n; i++) {
      scanf("%lld %lld %lld", a + i, b + i, m + i);
      int at = a[i] + b[i] - m[i];
      pos.insert(at);
      int min_a = min(m[i], a[i]);
      int min_b = min(m[i], b[i]);
      int l = b[i] - min_b;
      int r = b[i] - (m[i] - min_a);
      seg[at].emplace_back(l, r, i);
    }
    int ans = 0;
    for (auto it : pos) {
      vector<pair<int, int>> pl, pr;
      for (auto x : seg[it]) {
        int l, r, id;
        tie(l, r, id) = x;
        pl.emplace_back(l, id);
        pr.emplace_back(r, id);
      }
      sort(pl.begin(), pl.end());
      sort(pr.begin(), pr.end());

      int i = 0, j = 0;
      while (j < pr.size() && i < pl.size()) {
        while (j < pr.size() && done[pr[j].second]) j++;
        if (j == pr.size()) break;
        ans++;
        while (i < pl.size() && pl[i].first <= pr[j].first) {
          int id = pl[i].second;
          if (!done[id]) {
            done[id] = 1;
            xb[id] = b[id] - pr[j].first;
            xa[id] = m[id] - xb[id];
          }
          i++;
        }
      }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) {
      printf("%lld %lld\n", xa[i], xb[i]);
    }

    for (auto it : pos) seg[it].clear();
    for (int i = 0; i < n; i++) {
      done[i] = 0;
    }
  }

  return 0;
}
