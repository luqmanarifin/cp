#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

// row - column

struct segtree {
  segtree(vector<pair<int, int>> a) : a(a) {
    num.resize(a.size() << 2);
    build(1, 0, a.size() - 1);
  }
  void build(int p, int l, int r) {
    num[p].resize(r - l + 1);
    if (l == r) {
      num[p][0] = a[l].second;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    merge(num[p+p].begin(), num[p+p].end(), num[p+p+1].begin(), num[p+p+1].end(), num[p].begin());
  }
  int find(int x1, int y1, int x2, int y2) {
    if (x1 > x2) return 0;
    if (y1 > y2) return 0;
    return find(1, 0, a.size() - 1, x1, y1, x2, y2);
  }
  int find(int p, int l, int r, int x1, int y1, int x2, int y2) {
    if (a[r].first < x1 || a[l].first > x2) return 0;
    if (x1 <= a[l].first && a[r].first <= x2) {
      return upper_bound(num[p].begin(), num[p].end(), y2)
      - lower_bound(num[p].begin(), num[p].end(), y1);
    }
    int mid = (l + r) >> 1;
    return find(p + p, l, mid, x1, y1, x2, y2) + find(p + p + 1, mid + 1, r, x1, y1, x2, y2);
  }
  vector<pair<int, int>> a;
  vector<vector<int>> num;
};

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  vector<pair<int, int>> p;
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    p.emplace_back(v, i);
  }
  sort(p.begin(), p.end());
  segtree seg(p);
  while (q--) {
    int l, d, r, u;
    scanf("%d %d %d %d", &l, &d, &r, &u);
    long long ans = 1LL * n * (n - 1) / 2;
    long long lef = seg.find(1, 1, n, l - 1);
    long long rig = seg.find(1, r + 1, n, n);
    
    long long satu = seg.find(u + 1, 1, n, l - 1);
    long long dua = seg.find(u + 1, l, n, r);
    long long tiga = seg.find(u + 1, r + 1, n, n);
    
    long long enam = seg.find(1, 1, d - 1, l - 1);
    long long tujuh = seg.find(1, l, d - 1, r);
    long long delapan = seg.find(1, r + 1, d - 1, n);
    
    ans -= lef * (lef - 1) / 2;
    ans -= rig * (rig - 1) / 2;
    
    ans -= satu * dua;
    ans -= satu * tiga;
    ans -= dua * (dua - 1) / 2;
    ans -= dua * tiga;
    
    ans -= enam * tujuh;
    ans -= enam * delapan;
    ans -= tujuh * (tujuh - 1) / 2;
    ans -= tujuh * delapan;
    
    printf("%I64d\n", ans);
  }
  return 0;
}