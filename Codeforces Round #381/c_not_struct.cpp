#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

long long a[N];
int n;

int* lup;
int* ldo;
int* lhi;
int* rup;
int* rdo;
int* rhi;
int* ans;

long long* lef;
long long* rig;
long long* push;

inline void combine(int p, int l, int r) {
  int mid = (l + r) >> 1, cntl = mid - l + 1, cntr = r - mid;
  int leff = p + p, rigg = leff + 1;
  bool asc = (rig[leff] + push[leff] < lef[rigg] + push[rigg]), des = (rig[leff] + push[leff] > lef[rigg] + push[rigg]);
  lef[p] = lef[leff] + push[leff];
  rig[p] = rig[rigg] + push[rigg];
  int& lupp = lup[p];
  int& ldop = ldo[p];
  int& lhip = lhi[p];
  int& rupp = rup[p];
  int& rdop = rdo[p];
  int& rhip = rhi[p];
  int& ansp = ans[p];
  
  lupp = (lup[leff] == cntl && asc? cntl + lup[rigg] : lup[leff]);
  ldop = (ldo[leff] == cntl && des? cntl + ldo[rigg] : ldo[leff]);
  lhip = lhi[leff];
  int tmp = cntl + ldo[rigg];
  if (lhi[leff] == cntl && des) lhip = max(lhip, tmp);
  if (lup[leff] == cntl && des) lhip = max(lhip, tmp);
  if (lup[leff] == cntl && asc) lhip = max(lhip, tmp);
  if (lup[leff] == cntl && asc) lhip = max(lhip, cntl + lhi[rigg]);
  
  rupp = (rup[rigg] == cntr && des? cntr + rup[leff] : rup[rigg]);
  rdop = (rdo[rigg] == cntr && asc? cntr + rdo[leff] : rdo[rigg]);
  rhip = rhi[rigg];
  tmp = cntr + rdo[leff];
  if (rhi[rigg] == cntr && asc) rhip = max(rhip, tmp);
  if (rup[rigg] == cntr && asc) rhip = max(rhip, tmp);
  if (rup[rigg] == cntr && des) rhip = max(rhip, tmp);
  if (rup[rigg] == cntr && des) rhip = max(rhip, cntr + rhi[leff]);
  
  ansp = max(ans[leff], ans[rigg]);
  ansp = max(ansp, lupp);
  ansp = max(ansp, ldop);
  ansp = max(ansp, lhip);
  ansp = max(ansp, rupp);
  ansp = max(ansp, rdop);
  ansp = max(ansp, rhip);
  if (asc) ansp = max(ansp, rdo[leff] + lhi[rigg]);
  if (des) ansp = max(ansp, rhi[leff] + ldo[rigg]);
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

void init () { 
  lup = new int[n << 2];
  ldo = new int[n << 2];
  lhi = new int[n << 2];
  rup = new int[n << 2];
  rdo = new int[n << 2];
  rhi = new int[n << 2];
  ans = new int[n << 2];
  
  lef = new long long[n << 2];
  rig = new long long[n << 2];
  push = new long long[n << 2];
  build(1, 1, n);
}

void update(int p, int l, int r, int ll, int rr, long long val) {
  if (ll <= l && r <= rr) {
    push[p] += val;
    return;
  }
  int mid = (l + r) >> 1;
  if (ll <= mid) update(p + p, l, mid, ll, rr, val);
  if (mid < rr) update(p + p + 1, mid + 1, r, ll, rr, val);
  combine(p, l, r);
}

void update(int l, int r, long long val) {
  update(1, 1, n, l, r, val);
}

long long get() {
  return ans[1];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
  init();
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r, v;
    scanf("%d %d %d", &l, &r, &v);
    update(l, r, v);
    printf("%d\n", get());
  }

  return 0;
}
