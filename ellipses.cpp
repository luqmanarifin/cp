#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

int a[N], b[N];
int lima, limb;

struct segtree {
public:
  segtree(int _n) : n(_n) {
    max_a.resize(n << 2);
    ca.resize(n << 2);
    pa.resize(n << 2);
    sum_a.resize(n << 2);
    
    max_b.resize(n << 2);
    cb.resize(n << 2);
    pb.resize(n << 2);
    sum_b.resize(n << 2);
    
    val.resize(n << 2);
    cnt.resize(n << 2);
    
    build(1, 1, n);
  };
  void update(int t, int l, int r, int v) {
    switch(t) {
      case 1 : set_a(1, 1, n, l, r, v); break;
      case 2 : set_b(1, 1, n, l, r, v); break;
      case 3 : add_a(1, 1, n, l, r, v); break;
      case 4 : add_b(1, 1, n, l, r, v); break;
      default : assert(0);
    }
  }
  long long get(int t, int l, int r) {
    if(t == 5) {
      return sum_area(1, 1, n, l, r);
    } else {
      return get_cnt(1, 1, n, l, r);
    }
  }
private:
  void relax(int p, int l, int r) {
    
  }
  void combine(int p, int l, int r) {
    int pl = p + p, pr = p + p + 1;
    
    max_a[p] = max(max_a[pl], max_a[pr]);
    ca[p] = inf, pa[p] = inf, sum_a[p] = sum_a[pl] + sum_a[pr];
    
    max_b[p] = max(max_b[pl], max_b[pr]);
    cb[p] = inf, pb[p] = inf, sum_b[p] = sum_b[pl] + sum_b[pr];
    
    val[p] = val[pl] + val[pr];
    cnt[p] = cnt[pl] + cnt[pr];
  }
  void build(int p, int l, int r) {
    if(l == r) {
      max_a[p] = a[l], ca[p] = inf, pa[p] = inf, sum_a[p] = a[l];
      max_b[p] = b[l], cb[p] = inf, pb[p] = inf, sum_b[p] = b[l];
      val[p] = a[p] * b[p], cnt[p] = 1;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
  }
  void set_a(int p, int l, int r, int ll, int rr, int v) {
    
  }
  void set_b(int p, int l, int r, int ll, int rr, int v) {
    
  }
  void add_a(int p, int l, int r, int ll, int rr, int v) {
    
  }
  void add_b(int p, int l, int r, int ll, int rr, int v) {
    
  }
  long long sum_area(int p, int l, int r, int ll, int rr) {
    
  }
  long long get_cnt(int p, int l, int r, int ll, int rr) {
    
  }
  
  vector<long long> max_a, ca, pa, sum_a;
  vector<long long> max_b, cb, pb, sum_b;
  vector<long long> val, cnt;
  int n;
};

int t[N], l[N], r[N], v[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d %d", a + i, b + i);
  }
  segtree seg(n);
  for(int i = 1; i <= m; i++) {
    scanf("%d %d %d %d", &t[i], &l[i], &r[i]);
    if(t[i] <= 4) {
      scanf("%d", &v[i]);
    }
  }
  scanf("%d %d", &lima, &limb);
  for(int i = 1; i <= m; i++) {
    if(t[i] <= 4) {
      seg.update(t[i], l[i], r[i], v[i]);
    } else {
      printf("%I64d\n", seg.get(t[i], l[i], r[i]));
    }
  }
  return 0;
}
