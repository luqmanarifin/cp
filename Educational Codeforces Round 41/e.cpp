
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

struct segtree {
  segtree(int n) : n(n) {
    num.resize(n << 2);
    build(1, 1, n);
  }
  void build(int p, int l, int r) {
    num[p].resize(r - l + 1);
    if (l == r) {
      num[p][0] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    merge(num[p + p].begin(), num[p + p].end(), num[p + p + 1].begin(), num[p + p + 1].end(), num[p].begin());
  }
  int find(int l, int r, int val) {
    if (l > r) return 0;
    return find(1, 1, n, l, r, val);
  }
  int find(int p, int l, int r, int ll, int rr, int val) {
    if (ll <= l && r <= rr) return r - l + 1 - (lower_bound(num[p].begin(), num[p].end(), val) - num[p].begin());
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    return find(p + p, l, mid, ll, rr, val) + find(p + p + 1, mid + 1, r, ll, rr, val);
  }
  int n;
  vector<vector<int>> num;
};

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  segtree seg(n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > i) {
      int r = min(a[i], n);
      ans += seg.find(i + 1, r, i);
    }
  }
  cout << ans << endl;
  return 0;
}
