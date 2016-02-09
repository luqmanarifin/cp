#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long d[N], h[N];

struct Segtree {
public:
  Segtree(int n, vector<long long> b) : a(b){
    num.resize(n << 2);
    build(1, 0, n - 1);
  }
  long long cari(int l, int r) {
    return find(1, 0, n - 1, l, r);
  }
private:
  void build(int p, int l, int r) {
    if(l == r) {
      num[p] = a[l];
      return;
    }
    int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
    build(lef, l, mid);
    build(rig, mid + 1, r);
    num[p] = max(num[lef], num[rig]);
  }
  long long find(int p, int l, int r, int ll, int rr) {
    if(l == ll && r == rr) {
      return num[p];
    }
    int mid = (l + r) >> 1, lef = p << 1, rig = lef | 1;
    long long ret = -1;
    if(ll <= mid) {
      ret = max(ret, find(lef, l, mid, ll, min(mid, rr)));
    }
    if(mid < rr) {
      ret = max(ret, find(rig, mid + 1, r, max(mid + 1, ll), rr));
    } 
    return ret;
  }
  int n;
  vector<long long> num;
  vector<long long> a;
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%I64d", d + i);
  }
  for(int i = 0; i < n; i++) {
    scanf("%I64d", h + i);
    if(i) h[i] += h[i - 1];
  }
  vector<long long> l;
  vector<long long> r;
  for(int i = 0; i < n; i++) {
    r.push_back(2 * d[i] + (i? h[i - 1]) : 0);
    l.push_back(2 * d[i] - (i? h[i - 1]) : 0);
  }
  Segtree rseg(n, r);
  Segtree lseg(n, l);
  int q;
  while(q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    long long ans = 0;
    if(b < a) {
      ans = max(ans, lseg.cari(b + 1, a - 1) + rseg.cari(b + 1, a - 1));
    } else {
      ans = max(ans, )
    }
    printf("%I64d\n", ans);
  }
  return 0;
}