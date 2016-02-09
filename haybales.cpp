#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

struct segtree {
public:
  segtree(int n) : n(n) {
    push.resize(n << 2);
    num.resize(n << 2);
    sum.resize(n << 2);
  }
  void add(int l, int r, int val) {
    add(1, 1, n, l, r, val);
  }
  long long get_min(int l, int r) {
    return get_min(1, 1, n, l, r);
  }
  long long get_sum(int l, int r) {
    return get_sum(1, 1, n, l, r);
  }
private:
  void relax(int p, int l, int r) {
    if(push[p]) {
      num[p] += push[p];
      sum[p] += push[p] * (r - l + 1);
      if(l < r) {
        push[p + p] += push[p];
        push[p + p + 1] += push[p];
      }
      push[p] = 0;
    }
  }
  void combine(int p, int l, int r) {
    int mid = (l + r) >> 1;
    num[p] = min(num[p + p] + push[p + p], num[p + p + 1] + push[p + p + 1]);
    sum[p] = sum[p + p] + push[p + p] * (mid - l + 1) + sum[p + p + 1] + push[p + p + 1] * (r - mid);
  }
  void add(int p, int l, int r, int ll, int rr, int val) {
    relax(p, l, r);
    if(ll <= l && r <= rr) {
      push[p] += val;
      relax(p, l, r);
      return;
    }
    if(r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    add(p + p, l, mid, ll, rr, val);
    add(p + p + 1, mid + 1, r, ll, rr, val);
    combine(p, l, r);
  }
  long long get_min(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if(ll <= l && r <= rr) return num[p];
    if(r < ll || rr < l) return inf;
    int mid = (l + r) >> 1; long long ret = inf;
    ret = min(ret, get_min(p + p, l, mid, ll, rr));
    ret = min(ret, get_min(p + p + 1, mid + 1, r, ll, rr));
    combine(p, l, r);
    return ret;
  }
  long long get_sum(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if(ll <= l && r <= rr) return sum[p];
    if(r < ll || rr < l) return 0;
    int mid = (l + r) >> 1; long long ret = 0;
    ret += get_sum(p + p, l, mid, ll, rr);
    ret += get_sum(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
    return ret;
  }
  int n;
  vector<long long> push, num, sum;
};

int main() {
  freopen("haybales.in","r",stdin);
  freopen("haybales.out","w",stdout);
  
  int n, q;
  scanf("%d %d", &n, &q);
  segtree seg(n);
  for(int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    seg.add(i, i, v);
  }
  while(q--) {
    char c; int l, r, v;
    scanf(" %c %d %d", &c, &l, &r);
    if(c == 'M') {
      printf("%lld\n", seg.get_min(l, r));
    } else if(c == 'S') {
      printf("%lld\n", seg.get_sum(l, r));
    } else {
      scanf("%d", &v);
      seg.add(l, r, v);
    }
  }
  return 0;
}
