#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long PRIME = 89;
const long long mod = 2e9 + 89;
const int DIG = 26;

long long h[N][DIG];
char s[N];
long long power[N];

long long get(int l, int r, int c) {
  long long tmp = (h[r][c] - h[l-1][c] * power[r-l+1]) % mod;
  if (tmp < 0) tmp += mod;
  return tmp;
}

struct segtree {
  segtree(int n) : n(n) {
    pt.assign(n << 2, 0);
    for (int i = 0; i < DIG; i++) v[i].resize(n << 2, 0);
    c.assign(n << 2, 0);
    add.assign(n << 2, 0);

    build(1, 1, n);
  }
  void build(int p, int l, int r) {
    if (l == r) {
      for (int i = 0; i < DIG; i++) {
        v[i][p] = get(l, l, i);
      }
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
  }

  void relax(int p, int l, int r) {
    if (c[p] || add[p]) {
      int mid = (l + r) >> 1;
      if (c[p]) {
        pt[p] = 0;
        for (int i = 0; i < DIG; i++) v[i][p] = get(c[p], c[p] + r - l, i);

        if (l < r) {
          c[p+p] = c[p];
          c[p+p+1] = c[p] + mid - l + 1;
          add[p+p] = add[p+p+1] = 0;
        }
      } 
      if (add[p]) {
        pt[p] = (pt[p] + add[p]) % DIG;

        if (l < r) {
          add[p+p] = (add[p+p] + add[p]) % DIG;
          add[p+p+1] = (add[p+p+1] + add[p]) % DIG;
        }
      }
      c[p] = add[p] = 0;
    }
  }

  void combine(int p, int l, int r) {
    int mid = (l + r) >> 1;
    int len = r - mid;
    for (int i = 0; i < DIG; i++) {
      v[i][p] = (v[(i+pt[p+p])%DIG][p+p] * power[len] + v[(i+pt[p+p+1])%DIG][p+p+1]) % mod;
    }
    pt[p] = 0;
  }

  long long find(int l, int r) {
    return find(1, 1, n, l, r).first;
  }
  pair<long long, int> find(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if (r < ll || rr < l) return {0, 0};
    if (ll <= l && r <= rr) return {v[pt[p]][p], r - l + 1};
    int mid = (l + r) >> 1;
    auto lef = find(p + p, l, mid, ll, rr);
    auto rig = find(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
    return {(lef.first * power[rig.second] + rig.first) % mod, lef.second + rig.second};
  }

  void change(int l, int r, int k) {
    change(1, 1, n, l, r, k);
  } 
  void change(int p, int l, int r, int ll, int rr, int v) {
    //printf("%d-%d %d-%d\n", l, r, ll, rr);
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      c[p] = v;
      add[p] = 0;
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    int ada = max(0, min(mid - l + 1, mid - ll + 1));
    change(p + p, l, mid, ll, rr, v);
    change(p + p + 1, mid + 1, r, ll, rr, v + ada);
    combine(p, l, r);
  }

  void tambah(int l, int r) {
    tambah(1, 1, n, l, r);
  }
  void tambah(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      add[p]++;
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    tambah(p + p, l, mid, ll, rr);
    tambah(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
  }

  vector<int> pt;             // pointer to now addition
  vector<long long> v[DIG];    // hash value
  vector<int> c, add;         // lazy properties
  int n;
};

int main() {
  power[0] = 1;
  for (int i = 1; i < N; i++) power[i] = power[i-1] * PRIME % mod;

  scanf("%s", s + 1);
  //cout << (s + 1) << endl;
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) s[i] -= 'a';

  for (int it = 0; it < DIG; it++) {
    for (int i = 1; i <= n; i++) h[i][it] = (h[i-1][it] * PRIME + s[i] + 1) % mod;
    for (int i = 1; i <= n; i++) s[i] = (s[i] + 1) % DIG;
  }
  //cout << n << endl;
  //puts("bef segtree");
  segtree seg(n);
  //puts("segtree ok");

  int q;
  scanf("%d", &q);
  int nom = 0;
  while (q--) {
    int t, i, j, k;
    scanf("%d", &t);
    //printf("ke %d\n", ++nom);
    //printf("query %d\n", t);
    if (t == 1) {
      scanf("%d %d %d", &i, &j, &k);
      assert(k + j - i <= n);
      puts(seg.find(i, j) == seg.find(k, k + j - i)? "Y" : "N");
    } else if (t == 2) {
      scanf("%d %d %d", &i, &j, &k);
      assert(k + j - i <= n);
      seg.change(i, j, k);
    } else {
      scanf("%d %d", &i, &j);
      seg.tambah(i, j);
    }
  }

  return 0;
}
