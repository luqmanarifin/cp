#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int mod = 4001;

long long tot;
int a[N];
int b;

struct segtree {
public:
  segtree() {
    
  }
  segtree(int _n) : n(_n) {
    lef.resize(n << 2);
    rig.resize(n << 2);
    all.resize(n << 2);
    len.resize(n << 2);
    tmp.resize(n << 2);
    build(1, 1, n);
  }
  void update(int at) {
    update(1, 1, n, at);
  }
  void find(int l, int r) {
    find(1, 1, n, l, r);
  }
private:
  void single(int p, int l, int r) {
    all[p] = (a[l] & (1 << b)? 1 : 0);
    lef[p] = rig[p] = tmp[p] = all[p];
    len[p] = 1;
  }
  void combine(int p, int l, int r) {
    lef[p] = lef[p + p] + (all[p + p]? len[p + p + 1] - lef[p + p + 1] : lef[p + p + 1]);
    rig[p] = rig[p + p + 1] + (all[p + p + 1]? len[p + p] - rig[p + p] : rig[p + p]);
    all[p] = all[p + p] ^ all[p + p + 1];
    len[p] = len[p + p] + len[p + p + 1];
    
    tmp[p] = tmp[p + p] + tmp[p + p + 1];
    tmp[p] += 1LL * rig[p + p] * (len[p + p + 1] - lef[p + p + 1]);
    tmp[p] += 1LL * (len[p + p] - rig[p + p]) * lef[p + p + 1];
  }
  void build(int p, int l, int r) {
    if(l == r) {
      single(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
  }
  void update(int p, int l, int r, int at) {
    if(l == r) {
      single(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    if(at <= mid) {
      update(p + p, l, mid, at);
    } else {
      update(p + p + 1, mid + 1, r, at);
    }
    combine(p, l, r);
  }
  tuple<int, int, int, int> find(int p, int l, int r, int ll, int rr) {
    if(r < ll || rr < l) {
      return make_tuple(0, 0, 0, 0);
    }
    if(ll <= l && r <= rr) {
      tot += tmp[p];
      return make_tuple(lef[p], rig[p], all[p], len[p]);
    }
    int mid = (l + r) >> 1;
    int pl0, pl1, pl2, pl3, pr0, pr1, pr2, pr3;
    tie(pl0, pl1, pl2, pl3) = find(p + p, l, mid, ll, rr);
    tie(pr0, pr1, pr2, pr3) = find(p + p + 1, mid + 1, r, ll, rr);
    tot += 1LL * pl1 * (pr3 - pr0) + 1LL * (pl3 - pl1) * pr0;
    
    int r0, r1, r2, r3;
    r3 = pl3 + pr3;
    r0 = pl0 + (pl2? pr3 - pr0 : pr0);
    r1 = pr1 + (pr2? pl3 - pl1 : pl1);
    r2 = pl2 ^ pr2;
    return make_tuple(r0, r1, r2, r3);
  } 
  vector<int> lef, rig, all, len;
  vector<long long> tmp;
  int n;
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  segtree* seg[10];
  for(int i = 0; i < 10; i++) {
    b = i;
    seg[i] = new segtree(n);
  }
  while(q--) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    if(t == 1) {
      a[l] = r;
      for(int i = 0; i < 10; i++) {
        b = i;
        seg[i]->update(l);
      }
    } else {
      long long ans = 0;
      for(int i = 0; i < 10; i++) {
        b = i;
        tot = 0;
        seg[i]->find(l, r);
        tot %= mod;
        tot = tot * (1 << i) % mod;
        ans += tot;
      }
      ans %= mod;
      printf("%d\n", (int) ans);
    }
  }
  
  return 0;
}
