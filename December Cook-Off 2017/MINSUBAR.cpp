#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

struct segtree {
  segtree(vector<pair<long long, int>> ori) : ori(ori) {
    a.resize(ori.size() << 2);
    build(1, 0, ori.size() - 1);
  }
  void build(int p, int l, int r) {
    if (l == r) {
      a[p] = ori[l].second;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    a[p] = min(a[p + p], a[p + p + 1]);
  }
  void update(int at, int val) {
    update(1, 0, ori.size() - 1, at, val);
  }
  void update(int p, int l, int r, int at, int val) {
    if (l == r) {
      a[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if (at <= mid) {
      update(p + p, l, mid, at, val);
    } else {
      update(p + p + 1, mid + 1, r, at, val);
    }
    a[p] = min(a[p + p], a[p + p + 1]);
  }
  int find(int l, int r) {
    return find(1, 0, ori.size() - 1, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return a[p];
    if (r < ll || rr < l) return inf;
    int mid = (l + r) >> 1;
    return min(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
  }
  
  vector<int> a;
  vector<pair<long long, int>> ori;
};

long long a[N], s[N];
int pt[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, d;
    scanf("%d %d", &n, &d);
    vector<pair<long long, int>> all;
    for (int i = 0; i < n; i++) {
      scanf("%lld", a + i);
      s[i] = a[i];
      if (i) s[i] += s[i - 1];
      all.emplace_back(s[i], i);
    }
    sort(all.begin(), all.end());
    for (int i = 0; i < all.size(); i++) {
      pt[all[i].second] = i;
    }
    //puts("bef segtree");
    segtree seg(all);
    //puts("bikin segtree done");
    //for (int i = 0; i < n; i++) printf("%lld %d\n", all[i].first, all[i].second);
    
    //for (int i = 0; i < n; i++) printf("%d ", seg.find(i, i)); printf("\n");
    int ans = inf;
    for (int i = 0; i < n; i++) {
      long long val = (i? s[i - 1] : 0) + d;
      int p = lower_bound(all.begin(), all.end(), make_pair(val, -1)) - all.begin();
      if (p < all.size()) {
        int ret = seg.find(p, n - 1);
        ans = min(ans, ret - i + 1);
      }
      seg.update(pt[i], inf);
      //for (int i = 0; i < n; i++) printf("%d ", seg.find(i, i)); printf("\n");
    }
    if (ans > n) ans = -1;
    printf("%d\n", ans);
  }

  return 0;
}
