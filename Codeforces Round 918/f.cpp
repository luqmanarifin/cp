#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct segtree {
  segtree(vector<pair<int, int>> a) : a(a), n(a.size()) {
    num.resize(n << 2);
    build(1, 0, n - 1);
  }
  void build(int p, int l, int r) {
    if (r < l) return;
    if (l == r) {
      num[p] = {a[l].second};
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    for (auto it : num[p + p]) num[p].push_back(it);
    for (auto it : num[p + p + 1]) num[p].push_back(it);
    sort(num[p].begin(), num[p].end());
  }
  int find(int x, int y) {
    if (y < x || n == 0) return 0;
    return find(1, 0, n - 1, x, y);
  }
  int find(int p, int l, int r, int x, int y) {
    if (a[r].first < x || y < a[l].first) return 0;
    if (x <= a[l].first && a[r].first <= y) {
      return upper_bound(num[p].begin(), num[p].end(), y) - lower_bound(num[p].begin(), num[p].end(), x);
    }
    int mid = (l + r) >> 1, ans = 0;
    ans += find(p + p, l, mid, x, y);
    ans += find(p + p + 1, mid + 1, r, x, y);
    return ans;
  }
  vector<pair<int, int>> a;
  int n;
  vector<vector<int>> num;
};

int u[N], v[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> lef, rig;
    vector<int> lo, hi;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", u + i, v + i);
      if (u[i] < v[i]) {
        rig.emplace_back(u[i], v[i]);
        lo.push_back(u[i]);
        hi.push_back(v[i]);
      } else {
        lef.emplace_back(v[i], u[i]);
      }
    }
    sort(lef.begin(), lef.end());
    sort(rig.begin(), rig.end());
    sort(lo.begin(), lo.end());
    sort(hi.begin(), hi.end());

    segtree seg_lef(lef), seg_rig(rig);

    // compute inner lef
    long long ans = 0;
    for (auto it : lef) {
      ans += seg_lef.find(it.first + 1, it.second - 1);
    }

    // compute inner rig
    for (auto it : rig) {
      ans += seg_rig.find(it.first + 1, it.second - 1);
    }

    // compute interlaced
    for (auto it : lef) {
      ans += max(0, int(lower_bound(lo.begin(), lo.end(), it.second) - lower_bound(lo.begin(), lo.end(), it.first + 1)));
      ans += max(0, int(lower_bound(hi.begin(), hi.end(), it.second) - lower_bound(hi.begin(), hi.end(), it.first + 1)));
      ans -= seg_rig.find(it.first + 1, it.second - 1);
    }
    printf("%lld\n", ans);
  }

  return 0;
}
