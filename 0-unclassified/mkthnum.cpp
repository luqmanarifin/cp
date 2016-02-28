#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9 + 10;

int a[N];

class segtree {
public:
  segtree(int _n) : n(_n) {
    build(1, 1, n);
  }
  int get(int l, int r, int val) {
    return _get(1, 1, n, l, r, val);
  }
private:
  void build(int p, int l, int r) {
    v[p].resize(r - l + 1);
    if(l == r) {
      v[p][0] = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    merge(v[p + p].begin(), v[p + p].end(), v[p + p + 1].begin(), v[p + p + 1].end(), v[p].begin());
  }
  int _get(int p, int l, int r, int ll, int rr, int val) {
    if(r < ll || rr < l) return 0;
    if(ll <= l && r <= rr) return upper_bound(v[p].begin(), v[p].end(), val) - v[p].begin();
    int mid = (l + r) >> 1;
    return _get(p + p, l, mid, ll, rr, val) + _get(p + p + 1, mid + 1, r, ll, rr, val);
  }
  vector<int> v[N << 2];
  int n;
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  segtree seg(n);
  while(q--) {
    int i, j, k;
    scanf("%d %d %d", &i, &j, &k);
    long long l = -inf, r = inf;
    while(l < r) {
      long long mid = (l + r) >> 1;
      if(seg.get(i, j, (int) mid) >= k) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    printf("%d\n", (int) l);
  }
  
  return 0;
}
