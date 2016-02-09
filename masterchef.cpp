#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const int rup = 505;

struct segtree {
public:
  segtree(int _n) : n(_n) {
    num.resize(n << 2, inf);
    at.resize(n << 2, inf);
  }
  void update(int l, int r, int val) {
    _update(1, 1, n, l, r, val);
  }
  int find(int l) {
    return _find(1, 1, n, l);
  }
private: 
  void _update(int p, int l, int r, int ll, int rr, int val) {
    if(ll <= l && r <= rr) {
      at[p] = min(at[p], val);
      num[p] = min(num[p], at[p]);
      return;
    }
    int mid = (l + r) >> 1;
    if(ll <= mid) {
      _update(p + p, l, mid, ll, rr, val);
    }
    if(mid < rr) {
      _update(p + p + 1, mid + 1, r, ll, rr, val);
    }
    num[p] = min(at[p], min(num[p + p], num[p + p + 1]));
  }
  int _find(int p, int l, int r, int ll) {
    if(l == r) return num[p];
    int mid = (l + r) >> 1, ret = inf;
    if(ll <= mid) {
      ret = min(ret, _find(p + p, l, mid, ll));
    } else {
      ret = min(ret, _find(p + p + 1, mid + 1, r, ll));
    }
    return min(ret, at[p]);
  }
  vector<int> num, at;
  int n;
};

int a[N];
long long f[rup];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    long long sum = 0;
    for(int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      sum += a[i];
    }
    segtree seg(n);
    while(m--) {
      int l, r, c;
      scanf("%d %d %d", &l, &r, &c);
      seg.update(l, r, c);
    }
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= n; i++) {
      int cost = seg.find(i);
      if(a[i] < 0 && cost != inf) {
        long long get = -a[i];
        for(int c = k; c >= cost; c--) {
          f[c] = max(f[c], f[c - cost] + get);
        }
      }
    }
    long long del = 0;
    for(int i = 0; i <= k; i++) {
      del = max(del, f[i]);
    }
    printf("%lld\n", sum + del);
  }
  
  return 0;
}
