#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int g[N << 2], a[N];
vector<int> num[N << 2];

void build(int p, int l, int r) {
  num[p].resize(r - l + 1);
  if(l == r) {
    g[p] = a[l];
    num[p][0] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  g[p] = __gcd(g[p + p], g[p + p + 1]);
  merge(num[p + p].begin(), num[p + p].end(), num[p + p + 1].begin(), num[p + p + 1].end(), num[p].begin());
}

int get(int p, int l, int r, int ll, int rr) {
  if(ll <= l && r <= rr) return g[p];
  if(r < ll || rr < l) return 0;
  int mid = (l + r) >> 1;
  return __gcd(get(p + p, l, mid, ll, rr), get(p + p + 1, mid + 1, r, ll, rr));
}

int count(int p, int l, int r, int ll, int rr, int val) {
  if(ll <= l && r <= rr) return upper_bound(num[p].begin(), num[p].end(), val) - lower_bound(num[p].begin(), num[p].end(), val);
  if(r < ll || rr < l) return 0;
  int mid = (l + r) >> 1;
  return count(p + p, l, mid, ll, rr, val) + count(p + p + 1, mid + 1, r, ll, rr, val);
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  build(1, 1, n);
  int q;
  scanf("%d", &q);
  while(q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", r - l + 1 - count(1, 1, n, l, r, get(1, 1, n, l, r)));
  }
  
  return 0;
}
