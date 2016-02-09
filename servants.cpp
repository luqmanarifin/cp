#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, a[N];

struct segtree {
  segtree() {
    build(1, 1, n);
  }
  void build(int p, int l, int r) {
    num[p].resize(r - l + 1);
    if(l == r) {
      num[p][0] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    merge(num[p + p].begin(), num[p + p].end(), num[p + p + 1].begin(), num[p + p + 1].end(), num[p].begin());
  }
  int find(int l, int r, int val) {
    return find(1, 1, n, l, r, val);
  }
  int find(int p, int l, int r, int ll, int rr, int val) {
    if(r < ll || rr < l) return 0;
    if(ll <= l && r <= rr) return upper_bound(num[p].begin(), num[p].end(), val) - num[p].begin();
    int mid = (l + r) >> 1;
    return find(p + p, l, mid, ll, rr, val) + find(p + p + 1, mid + 1, r, ll, rr, val);
  }
  vector<int> num[N << 2];
};

int main() {
  int q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  segtree seg;
  while(q--) {
    int lef, rig;
    scanf("%d %d", &lef, &rig);
    int len = rig - lef + 1;
    int k = (len + 1) / 2;
    int l = 1, r = 1e9;
    while(l < r) {
      int mid = (l + r) >> 1;
      if(seg.find(lef, rig, mid) >= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    printf("%d\n", l);
  }
  return 0;
}
