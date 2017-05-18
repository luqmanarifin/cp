#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 3e5 + 5;

struct segtree {
  segtree() {}
  segtree(int n) : n(n) {
    a.assign(n << 2, 0);
    add.assign(n << 2, 0);
  }
  inline void combine(int p, int l, int r) {
    assert(l < r);
    a[p] = a[p + p] + a[p + p + 1];
  }
  inline void relax(int p, int l, int r) {
    if (add[p] != 0) {
      if (l < r) {
        add[p + p] += add[p];
        add[p + p + 1] += add[p];
      }
      a[p] += 1LL * (r - l + 1) * add[p];
      //printf("%lld %lld %lld: %lld\n", p, l, r, a[p]);
      add[p] = 0;
    }
  }
  void update(int l, int r, long long val) {
    update(1, 1, n, l, r, val);
  }
  void update(int p, int l, int r, int ll, int rr, long long val) {
    relax(p, l, r);
    if (r < ll || rr < l) return;
    //printf("add %lld %lld: %lld\n", l, r, val);
    if (ll <= l && r <= rr) {
      add[p] += val;
      relax(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr, val);
    update(p + p + 1, mid + 1, r, ll, rr, val);
    combine(p, l, r);
  }
  long long find(int at) {
    return find(1, 1, n, at);
  }
  long long find(int p, int l, int r, int at) {
    relax(p, l, r);
    if (r < at || at < l) return 0;
    //printf("finding %lld: %lld %lld\n", at, l, r);
    if (l == r) return a[p];
    int mid = (l + r) >> 1;
    long long ret = find(p + p, l, mid, at) + find(p + p + 1, mid + 1, r, at);
    combine(p, l, r);
    return ret;
  }
  vector<long long> a, add;
  int n;
};

vector<int> got[N];
int need[N], l[N], r[N], add[N];
int ans[N];
int pt;
int n, m, q;
segtree seg;

void find(int lo, int hi, vector<int>& owner) {
  //printf("%lld %lld\n", lo, hi);
  if (owner.empty()) return;
  int mid = (lo + hi) >> 1;
  while (pt < mid) {
    if (l[pt+1] <= r[pt+1]) {
      seg.update(l[pt+1], r[pt+1], add[pt+1]);
    } else {
      seg.update(l[pt+1], m, add[pt+1]);
      seg.update(1, r[pt+1], add[pt+1]);
    }
    pt++;
  }
  while (pt > mid) {
    if (l[pt] <= r[pt]) {
      seg.update(l[pt], r[pt], -add[pt]);
    } else {
      seg.update(l[pt], m, -add[pt]);
      seg.update(1, r[pt], -add[pt]);
    }
    pt--;
  }
  //printf("after query %lld\n", mid);
  //for (int i = 1; i <= m; i++) printf("%lld ", seg.find(i)); printf("\n");
  vector<int> lef, rig;
  for (auto it : owner) {
    long long cur = 0;
    for (auto i : got[it]) {
      cur += seg.find(i);
      if (cur >= need[it]) break;
    }
    if (cur >= need[it]) {
      lef.push_back(it);
      ans[it] = mid;
    } else {
      rig.push_back(it);
    }
  }
  owner.clear();
  if (lo == hi) return;
  find(lo, mid, lef);
  find(mid + 1, hi, rig);
}

main() {
  scanf("%lld %lld", &n, &m);
  for (int i = 1; i <= m; i++) {
    int v;
    scanf("%lld", &v);
    got[v].push_back(i);
  }
  for (int i = 1; i <= n; i++) scanf("%lld", need + i);
  scanf("%lld", &q);
  for (int i = 1; i <= q; i++) scanf("%lld %lld %lld", l + i, r + i, add + i);
  
  vector<int> owner;
  for (int i = 1; i <= n; i++) owner.push_back(i);
  seg = segtree(m);
  
  //for (int i = 1; i <= m; i++) printf("%lld ", seg.find(i)); printf("\n");
  //seg.update(1, 3, 4);
  //for (int i = 1; i <= m; i++) printf("%lld ", seg.find(i)); printf("\n");
  
  
  find(1, q, owner);
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 0) {
      puts("NIE");
    } else {
      printf("%lld\n", ans[i]);
    }
  }
  
  return 0;
}
