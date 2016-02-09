#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct segtree {
public:
  segtree(int _n) : n(_n) {
    num.resize((n + 1) << 2);
    v.resize((n + 1) << 2);
    build(1, 0, n);
  }
  void update(int at, int val) {
    _update(1, 0, n, at, val);
  }
  int find(int l, int r) {
    return _find(1, 0, n, l, r);
  }
private:
  void gather(int p) {
    num[p] = num[p + p] != -1? num[p + p] : (num[p + p + 1] != -1? num[p + p + 1] : -1);
  }
  void build(int p, int l, int r) {
    if(l == r) {
      num[p] = l, v[p] = 0;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    gather(p);
  }
  void _update(int p, int l, int r, int at, int val) {
    if(l == r) {
      v[p] += val;
      num[p] = (v[p] == 0? l : -1);
      return;
    }
    int mid = (l + r) >> 1;
    if(at <= mid) {
      _update(p + p, l, mid, at, val);
    } else {
      _update(p + p + 1, mid + 1, r, at, val);
    }
    gather(p);
  }
  int _find(int p, int l, int r, int ll, int rr) {
    if(ll <= l && r <= rr) return num[p];
    if(l < ll || rr < r) return -1;
    int mid = (l + r) >> 1;
    int retl = _find(p + p, l, mid, ll, rr);
    int retr = _find(p + p + 1, mid + 1, r, ll, rr);
    return retl != -1? retl : (retr != -1? retr : -1);
  }
  vector<int> num;
  vector<int> v;
  int n;
};

int val[N];
int l[N], r[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(val, 0, sizeof(val));
    
    int n, m;
    scanf("%d %d", &n, &m);
    segtree seg(n);
    seg.update(0, +1);
    for(int i = 2; i <= n; i++) {
      scanf("%d %d", &l[i], &r[i]);
    }
    int ln = 1, rn = 1;
    for(int i = 2; i <= n; i++) {
      while(rn < r[i]) seg.update(val[++rn], +1);
      while(ln < l[i]) seg.update(val[ln++], -1);
      val[i] = seg.find(0, n);
    }
    int ans = 0;
    while(m--) {
      int q;
      scanf("%d", &q);
      ans ^= val[q];
    }
    puts(ans? "Marko" : "Ferde");
  }
  
  return 0;
}
