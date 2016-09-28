#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

struct matriks {
  matriks() {
    memset(a, 0, sizeof(a));
  }
  matriks(const matriks& m) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        a[i][j] = m.a[i][j];
      }
    }
  }
  matriks& operator=(const matriks& m) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        a[i][j] = m.a[i][j];
      }
    }
    return *this;
  }
  matriks operator+(const matriks& m) {
    matriks ret;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        ret.a[i][j] = (this->a[i][j] + m.a[i][j]) % mod;
      }
    }
    return ret;
  }
  matriks operator*(const matriks& m) {
    matriks ret;
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          ret.a[i][j] += this->a[i][k] * m.a[k][j];
          ret.a[i][j] %= mod;
        }
      }
    }
    return ret;
  }
  long long a[2][2];
};

matriks satu, t, base;

matriks power(matriks a, long long b) {
  if (b == 0) return satu;
  matriks temp = power(a, b / 2);
  temp = temp * temp;
  if (b & 1) {
    temp = temp * a;
  }
  return temp;
}

int a[N], n;

struct segtree {
  segtree() {
    a.resize(n << 2);
    push.resize(n << 2);
    build(1, 1, n);
  }
  void relaks(int p, int l, int r) {
    if (push[p] != 0) {
      if (l < r) {
        push[p + p] += push[p];
        push[p + p + 1] += push[p];
      }
      a[p] = a[p] * power(t, push[p]);
      push[p] = 0;
    }
  }
  void combine(int p, int l, int r) {
    a[p] = a[p + p] + a[p + p + 1];
  }
  void build(int p, int l, int r) {
    push[p] = 0;
    if (l == r) {
      a[p] = base * power(t, ::a[l]);
      //printf("%d: %I64d padahal %d\n", l, a[p].a[0][0], ::a[l]);
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
  }
  void update(int l, int r, int v) {
    update(1, 1, n, l, r, v);
  }
  void update(int p, int l, int r, int ll, int rr, int v) {
    relaks(p, l, r);
    if (ll <= l && r <= rr) {
      push[p] += v;
      relaks(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr, v);
    update(p + p + 1, mid + 1, r, ll, rr, v);
    combine(p, l, r);
  }
  long long find(int l, int r) {
    return find(1, 1, n, l, r);
  }
  long long find(int p, int l, int r, int ll, int rr) {
    relaks(p, l, r);
    if (ll <= l && r <= rr) return a[p].a[0][0];
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    long long ret = 0;
    ret += find(p + p, l, mid, ll, rr);
    ret += find(p + p + 1, mid + 1, r, ll, rr);
    ret %= mod;
    combine(p, l, r);
    return ret;
  }
  vector<matriks> a;
  vector<long long> push;
};

int main() {
  satu.a[0][0] = 1;
  satu.a[1][1] = 1;
  t.a[0][0] = 1;
  t.a[1][0] = 1;
  t.a[0][1] = 1;
  base.a[1][0] = 1;
  base.a[0][1] = 1;
  base.a[1][1] = mod - 1;
  
  int m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  segtree seg;
  
  //for (int i = 1; i <= n; i++) printf("%I64d ", seg.find(i, i)); printf("\n");
  while (m--) {
    int tt, l, r, v;
    scanf("%d %d %d", &tt, &l, &r);
    if (tt == 1) {
      scanf("%d", &v);
      seg.update(l, r, v);
    } else {
      printf("%I64d\n", seg.find(l, r));
    }
    //for (int i = 1; i <= n; i++) printf("%I64d ", seg.find(i, i)); printf("\n");
  }
  return 0;
}