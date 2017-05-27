#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

vector<int> num[N << 2];
int a[N];

void build(int p, int l, int r) {
  num[p].resize(r - l + 1);
  if (l == r) {
    num[p][0] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  merge(num[p+p].begin(), num[p+p].end(), num[p+p+1].begin(), num[p+p+1].end(), num[p].begin());
}

int find(int p, int l, int r, int ll, int rr, int x) {
  if (ll <= l && r <= rr) return upper_bound(num[p].begin(), num[p].end(), x) - num[p].begin();
  if (r < ll || rr < l) return 0;
  int mid = (l + r) >> 1;
  return find(p + p, l, mid, ll, rr, x) + find(p + p + 1, mid + 1, r, ll, rr, x);
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  build(1, 1, n);
  while (q--) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);
    int bef = 0;
    if (l < x) bef += find(1, 1, n, l, x - 1, a[x]);
    if (x < r) bef += find(1, 1, n, x + 1, r, a[x]);
    puts(bef == x - l? "Yes" : "No");
  }
  return 0;
}
