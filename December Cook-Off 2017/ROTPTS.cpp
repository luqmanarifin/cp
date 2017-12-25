#include <bits/stdc++.h>
 
using namespace std;
 
const long long mod = 1e9 + 7;
#define matrix vector<vector<long long>>
 
inline void norm(long long& at) {
  if (at >= mod) at -= mod;
  if (at < 0) at += mod;
}
 
inline matrix add(matrix& a, matrix& b) {
  matrix ret(a.size(), vector<long long>(a[0].size(), 0));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[0].size(); j++) {
      ret[i][j] = a[i][j] + b[i][j];
      norm(ret[i][j]);
    }
  }
  return ret;
}
 
inline matrix multiply(matrix& a, matrix& b) {
  matrix ret(a.size(), vector<long long>(b[0].size(), 0));
  for (int k = 0; k < a[0].size(); k++) {
    for (int i = 0; i < a.size(); i++) {
      for (int j = 0; j < b[0].size(); j++) {
        ret[i][j] += a[i][k] * b[k][j];
        ret[i][j] %= mod;
      }
    }
  }
  return ret;
}
 
inline matrix negasikeun(matrix& a) {
  matrix ret(a.size(), vector<long long>(a[0].size(), 0));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[0].size(); j++) {
      ret[i][j] = mod - a[i][j];
      norm(ret[i][j]);
    }
  }
  return ret;
}
 
struct item {
  item() {
    a = {{1, 0}, {0, 1}};
    b = {{0}, {0}};
  }
  item(matrix a, matrix b) : a(a), b(b) {}
  matrix a, b;
};
 
inline item combine(item& a, item& b) {
  matrix retA = multiply(b.a, a.a);
  matrix temp = multiply(b.a, a.b);
  matrix retB = add(temp, b.b);
  return item(retA, retB);
}
 
matrix rot[] = {
  {{1, 0}, {0, 1}},
  {{0, -1}, {1, 0}},
  {{-1, 0}, {0, -1}},
  {{0, 1}, {-1, 0}}
};
 
int id[360];
 
struct segtree {
  segtree(vector<item> ori) : ori(ori) {
    a.resize(ori.size() << 2);
    build(1, 0, ori.size() - 1);
  }
  void build(int p, int l, int r) {
    if (l == r) {
      a[p] = ori[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    a[p] = combine(a[p + p], a[p + p + 1]);
  }
  void update(int at, item& val) {
    update(1, 0, ori.size() - 1, at, val);
  }
  inline void update(int p, int l, int r, int at, item& val) {
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
    a[p] = combine(a[p + p], a[p + p + 1]);
  }
  item find(int l, int r) {
    return find(1, 0, ori.size() - 1, l, r);
  }
  inline item find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return a[p];
    int mid = (l + r) >> 1;
    item ret;
    if (ll <= mid) {
      item lef = find(p + p, l, mid, ll, rr);
      ret = combine(ret, lef);
    }
    if (mid < rr) {
      item rig = find(p + p + 1, mid + 1, r, ll, rr);
      ret = combine(ret, rig);
    }
    return ret;
  }
  
  vector<item> ori, a;
};
 
inline item build(int x, int y, int b) {
  b = id[b];
  matrix A = {{x}, {y}};
  matrix B = rot[b];
  matrix retA = B;
  matrix temp = multiply(B, A);
  temp = negasikeun(temp);
  matrix retB = add(temp, A);
  return item(retA, retB);
}
 
inline matrix apply(int x, int y, item o) {
  matrix X = {{x}, {y}};
  matrix temp = multiply(o.a, X);
  return add(temp, o.b);
}
 
int main() {
  id[90] = 1;
  id[180] = 2;
  id[270] = 3;
  int n;
  scanf("%d", &n);
  vector<item> a;
  for (int i = 0; i < n; i++) {
    int x, y, d;
    scanf("%d %d %d", &x, &y, &d);
    a.push_back(build(x, y, d));
  }
  segtree seg(a);
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, x, y, l, r;
    scanf("%d %d %d %d %d", &t, &x, &y, &l, &r);
    if (t == 1) {
      l--; r--;
      item ret = seg.find(l, r);
      matrix ans = apply(x, y, ret);
      printf("%lld %lld\n", ans[0][0], ans[1][0]);
    } else {
      x--;
      item be = build(y, l, r);
      seg.update(x, be);
    }
  }
  return 0;
}
 