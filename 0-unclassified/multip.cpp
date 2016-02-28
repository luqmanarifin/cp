#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

struct segtree {
public:
  segtree(vector<int> _v) : n(_v.size()) {
    asli = _v;
    num.resize(n << 2);
    a.resize(n << 2);
    b.resize(n << 2);
    c.resize(n << 2);
    build(1, 0, n - 1);
  }
  void update(int l, int r, int v, int q) {
    _update(1, 0, n - 1, l, r, v, q);
  }
  int find(int l, int r) {
    return _find(1, 0, n - 1, l, r);
  }
private:
  void build(int p, int l, int r) {
    a[p] = 1, b[p] = 0, c[p] = -1;
    if(l == r) {
      num[p] = asli[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = num[p + p] + num[p + p + 1];
    if(num[p] >= mod) num[p] -= mod;
  }
  void relax(int p, int l, int r) {
    if(a[p] != 1 || b[p] != 0 || c[p] != -1) {
      if(c[p] != -1) num[p] = c[p] * (r - l + 1) % mod;
      num[p] = (num[p] * a[p] + b[p] * (r - l + 1)) % mod;
      if(l < r) {
        if(c[p] != -1) {
          c[p + p] = c[p + p + 1] = c[p];
          a[p + p] = a[p + p + 1] = 1;
          b[p + p] = b[p + p + 1] = 0;
        }
        a[p + p] = (a[p + p] * a[p]) % mod;
        b[p + p] = (b[p + p] * a[p] + b[p]) % mod;
        a[p + p + 1] = (a[p + p + 1] * a[p]) % mod;
        b[p + p + 1] = (b[p + p + 1] * a[p] + b[p]) % mod;
      }
      a[p] = 1, b[p] = 0, c[p] = -1;
    }
  }
  void _update(int p, int l, int r, int ll, int rr, int v, int q) {
    relax(p, l, r);
    if(r < ll || rr < l) return;
    if(ll <= l && r <= rr) {
      if(q == 1) {
        b[p] = (b[p] + v >= mod? b[p] + v - mod : b[p] + v); 
      } else if(q == 2) {
        a[p] = (a[p] * v) % mod;
        b[p] = (b[p] * v) % mod;
      } else {
        a[p] = 1, b[p] = 0, c[p] = v;
      }
      relax(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    _update(p + p, l, mid, ll, rr, v, q);
    _update(p + p + 1, mid + 1, r, ll, rr, v, q);
    num[p] = num[p + p] + num[p + p + 1];
    if(num[p] >= mod) num[p] -= mod;
  }
  int _find(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if(r < ll || rr < l) return 0;
    if(ll <= l && r <= rr) return num[p];
    int mid = (l + r) >> 1;
    int ret = _find(p + p, l, mid, ll, rr) + _find(p + p + 1, mid + 1, r, ll, rr);
    num[p] = num[p + p] + num[p + p + 1];
    if(num[p] >= mod) num[p] -= mod;
    return (ret >= mod? ret - mod : ret);
  }
  vector<int> asli;
  vector<long long> num, a, b, c;
  int n;
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<int> a;
  for(int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);
    a.push_back(num);
  }
  segtree seg(a);
  
  vector<long long> debug;
  for(auto it : a) debug.push_back(it);
  
  for(int it = 0; it < q; it++) {
    int t, l, r, val;
    scanf("%d", &t);
    if(t == 4) {
      scanf("%d %d", &l, &r);
      l--, r--;
      //printf("case %d : \n", it);
      printf("%d\n", seg.find(l, r));
      /*
      int ans = 0;
      for(int i = l; i <= r; i++) {
        ans += debug[i];
        if(ans >= mod) ans -= mod;
      }
      printf("%d\n\n", ans);
      assert(ans == seg.find(l, r));
      */
    } else {
      scanf("%d %d %d", &l, &r, &val);
      l--, r--;
      seg.update(l, r, val, t);
      /*
      if(t == 1) {
        for(int i = l; i <= r; i++) {
          debug[i] = (debug[i] + val) % mod;
        }
      } else if(t == 2) {
        for(int i = l; i <= r; i++) {
          debug[i] = (debug[i] * val) % mod;
        }
      } else {
        for(int i = l; i <= r; i++) {
          debug[i] = val;
        }
      }
      */
    }
    /*
    printf("NOW : ");
    for(int i = 0; i < n; i++) {
      printf("%d ", seg.find(i, i));
    }
    printf("\n");
    */
  }
  
  return 0;
}
