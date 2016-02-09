#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N];

struct Segtree {
public:
  Segtree(int _n) {
    n = _n;
    num.resize(n << 2);
    build(1, 1, n);
  }
  int find(int l, int r) {
    int ret;
    tie(ret, ignore, ignore) = cari(1, 1, n, l, r);
    return ret << 1;
  }
private:
  void build(int p, int l, int r) {
    int a = 0, b = 0, c = 0;
    if(l == r) {
      if(s[l] == '(') b++; else c++;
    } else {
      int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
      build(lef, l, mid);
      build(rig, mid + 1, r);
      int la, lb, lc, ra, rb, rc;
      tie(la, lb, lc) = num[lef];
      tie(ra, rb, rc) = num[rig];
      int be = min(lb, rc);
      a += la + ra + be;
      b += lb + rb - be;
      c += lc + rc - be;
    }
    num[p] = make_tuple(a, b, c);
  }
  tuple<int, int, int> cari(int p, int l, int r, int ll, int rr) {
    if(l == ll && r == rr) {
      return num[p];
    }
    int a = 0, b = 0, c = 0;
    int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
    int la = 0, lb = 0, lc = 0, ra = 0, rb = 0, rc = 0;
    if(ll <= mid) {
      tie(la, lb, lc) = cari(lef, l, mid, ll, min(mid, rr));
    }
    if(mid < rr) {
      tie(ra, rb, rc) = cari(rig, mid + 1, r, max(mid + 1, ll), rr);
    }
    int be = min(lb, rc);
    a += la + ra + be;
    b += lb + rb - be;
    c += lc + rc - be;
    return make_tuple(a, b, c);
  }
  int n;
  vector<tuple<int, int, int>> num;
};

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1), q;
  Segtree seg(n);
  scanf("%d", &q);
  while(q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", seg.find(l, r));
  }
  
  return 0;
}
