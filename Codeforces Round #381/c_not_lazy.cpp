#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

long long a[N];

struct segtree {
  segtree(int n) : n(n) { 
    lup = new long long[n << 2];
    ldo = new long long[n << 2];
    lhi = new long long[n << 2];
    rup = new long long[n << 2];
    rdo = new long long[n << 2];
    rhi = new long long[n << 2];
    ans = new long long[n << 2];
    
    lef = new long long[n << 2];
    rig = new long long[n << 2];
    push = new long long[n << 2];
    build(1, 1, n);
  }
  inline void combine(int p, int l, int r) {
    int mid = (l + r) >> 1, cntl = mid - l + 1, cntr = r - mid;
    bool asc = (rig[p+p] + push[p+p] < lef[p+p+1] + push[p+p+1]), des = (rig[p+p] + push[p+p] > lef[p+p+1] + push[p+p+1]);
    lef[p] = lef[p+p] + push[p+p];
    rig[p] = rig[p+p+1] + push[p+p+1];
    
    lup[p] = (lup[p+p] == cntl && asc? cntl + lup[p+p+1] : lup[p+p]);
    ldo[p] = (ldo[p+p] == cntl && des? cntl + ldo[p+p+1] : ldo[p+p]);
    lhi[p] = lhi[p+p];
    if (lhi[p+p] == cntl && des) lhi[p] = max(lhi[p], cntl + ldo[p+p+1]);
    if (lup[p+p] == cntl && des) lhi[p] = max(lhi[p], cntl + ldo[p+p+1]);
    if (lup[p+p] == cntl && asc) lhi[p] = max(lhi[p], cntl + ldo[p+p+1]);
    if (lup[p+p] == cntl && asc) lhi[p] = max(lhi[p], cntl + lhi[p+p+1]);
    
    rup[p] = (rup[p+p+1] == cntr && des? cntr + rup[p+p] : rup[p+p+1]);
    rdo[p] = (rdo[p+p+1] == cntr && asc? cntr + rdo[p+p] : rdo[p+p+1]);
    rhi[p] = rhi[p+p+1];
    if (rhi[p+p+1] == cntr && asc) rhi[p] = max(rhi[p], cntr + rdo[p+p]);
    if (rup[p+p+1] == cntr && asc) rhi[p] = max(rhi[p], cntr + rdo[p+p]);
    if (rup[p+p+1] == cntr && des) rhi[p] = max(rhi[p], cntr + rdo[p+p]);
    if (rup[p+p+1] == cntr && des) rhi[p] = max(rhi[p], cntr + rhi[p+p]);
    
    ans[p] = max(ans[p+p], ans[p+p+1]);
    ans[p] = max(ans[p], lup[p]);
    ans[p] = max(ans[p], ldo[p]);
    ans[p] = max(ans[p], lhi[p]);
    ans[p] = max(ans[p], rup[p]);
    ans[p] = max(ans[p], rdo[p]);
    ans[p] = max(ans[p], rhi[p]);
    if (asc) ans[p] = max(ans[p], rdo[p+p] + lhi[p+p+1]);
    if (des) ans[p] = max(ans[p], rhi[p+p] + ldo[p+p+1]);
  }
  inline void one(int p, int l, int r) {
    lup[p] = ldo[p] = lhi[p] = 1;
    rup[p] = rdo[p] = rhi[p] = 1;
    ans[p] = 1;
    lef[p] = rig[p] = a[l];
    push[p] = 0;
  }
  void build(int p, int l, int r) {
    one(p, l, r);
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
  }
  void update(int l, int r, long long val) {
    update(1, 1, n, l, r, val);
  }
  void update(int p, int l, int r, int ll, int rr, long long val) {
    if (ll <= l && r <= rr) {
      push[p] += val;
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    if (ll <= mid) update(p + p, l, mid, ll, rr, val);
    if (mid < rr) update(p + p + 1, mid + 1, r, ll, rr, val);
    combine(p, l, r);
  }
  long long get() {
    return ans[1];
  }
  
  int n;
  long long* lup;
  long long* ldo;
  long long* lhi;
  long long* rup;
  long long* rdo;
  long long* rhi;
  long long* ans;
  long long* lef;
  long long* rig;
  long long* push;
};

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
  segtree seg(n);
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r, v;
    scanf("%d %d %d", &l, &r, &v);
    seg.update(l, r, v);
    printf("%d\n", seg.get());
  }

  return 0;
}
