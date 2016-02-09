#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct Segtree {
public:
  Segtree(int _n) : n(_n) {
    num.resize(n << 2);
  }
  void modify(int at, int val) {
    _modify(1, 0, n, at, val);
  }
  int get(int l, int r) {
    return _get(1, 0, n, l, r);
  }
private:
  void _modify(int p, int l, int r, int at, int val) {
    if(l == r) {
      num[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    if(at <= mid) {
      _modify(p << 1, l, mid, at, val);
    } else {
      _modify(p << 1 | 1, mid + 1, r, at, val);
    }
    num[p] = max(num[p << 1], num[p << 1 | 1]);
  }
  int _get(int p, int l, int r, int ll, int rr) {
    if(ll <= l && r <= rr) {
      return num[p];
    }
    int mid = (l + r) >> 1, ret = 0;
    if(ll <= mid) {
      ret = max(ret, _get(p << 1, l, mid, ll, rr));
    }
    if(mid < rr) {
      ret = max(ret, _get(p << 1 | 1, mid + 1, r, ll, rr));
    }
    return ret;
  }
  vector<int> num;
  int n;
};

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  Segtree seg(n);
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    int bef = seg.get(0, a[i] - 1);
    ans = max(ans, bef + 1);
    seg.modify(a[i], bef + 1);
  }
  cout << ans << endl;
  return 0;
}
