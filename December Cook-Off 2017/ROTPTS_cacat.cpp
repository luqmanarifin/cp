#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

struct matrix {
  matrix() {}
  matrix(int n, int m) : n(n), m(m) {
    a = new int*[n];
    for (int i = 0; i < n; i++) {
      a[i] = new int[m];
      for (int j = 0; j < m; j++) {
        a[i][j] = 0;
      }
    }
  }
  matrix(vector<vector<long long>> p) {
    n = p.size();
    m = p[0].size();
    a = new int*[n];
    for (int i = 0; i < n; i++) {
      a[i] = new int[m];
      for (int j = 0; j < m; j++) {
        a[i][j] = p[i][j];
      }
    }
  }
  int n, m;
  int** a;
};

void norm(long long& at) {
  if (at >= mod) at -= mod;
  if (at < 0) at += mod;
}

matrix add(matrix& a, matrix& b) {
  matrix ret(a.n, a.m);
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.m; j++) {
      ret.a[i][j] = a.a[i][j] + b.a[i][j];
      norm(ret.a[i][j]);
    }
  }
  return ret;
}

matrix multiply(matrix& a, matrix& b) {
  matrix ret(a.n, b.m);
  for (int k = 0; k < a.m; k++) {
    for (int i = 0; i < a.n; i++) {
      for (int j = 0; j < b.m; j++) {
        ret.a[i][j] += a.a[i][k] * b.a[k][j];
        ret.a[i][j] %= mod;
      }
    }
  }
  return ret;
}

matrix negasikeun(matrix& a) {
  matrix ret(a.n, a.m);
  for (int i = 0; i < a.n; i++) {
    for (int j = 0; j < a.m; j++) {
      ret.a[i][j] = mod - a.a[i][j];
      norm(ret.a[i][j]);
    }
  }
  return ret;
}

struct item {
  item() {
    a = matrix({{1, 0}, {0, 1}});
    vector<vector<long long>> zero = {{0}, {0}};
    b = matrix(zero);
  }
  item(matrix a, matrix b) : a(a), b(b) {}
  matrix a, b;
};

item combine(item& a, item& b) {
  matrix A = a.a;
  matrix B = a.b;
  matrix C = b.a;
  matrix D = b.b;
  matrix retA = multiply(C, A);
  matrix temp = multiply(C, B);
  matrix retB = add(temp, D);
  return item(retA, retB);
}

matrix rot[] = {
  matrix({{1, 0}, {0, 1}}),
  matrix({{0, -1}, {1, 0}}),
  matrix({{-1, 0}, {0, -1}}),
  matrix({{0, 1}, {-1, 0}})
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
  void update(int p, int l, int r, int at, item& val) {
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
  item find(int p, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) return a[p];
    if (r < ll || rr < l) {
      item ret;
      return ret;
    }
    int mid = (l + r) >> 1;
    item lef = find(p + p, l, mid, ll, rr);
    item rig = find(p + p + 1, mid + 1, r, ll, rr);
    return combine(lef, rig);
  }
  
  vector<item> ori, a;
};

item build(int x, int y, int b) {
  b = id[b];
  matrix A = {{x}, {y}};
  matrix B = rot[b];
  matrix retA = B;
  matrix temp = multiply(B, A);
  temp = negasikeun(temp);
  matrix retB = add(temp, A);
  return item(retA, retB);
}

matrix apply(int x, int y, item o) {
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
      printf("%lld %lld\n", ans.a[0][0], ans.a[1][0]);
    } else {
      x--;
      item be = build(y, l, r);
      seg.update(x, be);
    }
  }
  return 0;
}
