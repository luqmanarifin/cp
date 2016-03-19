#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

pair<int, int> all[N][2];

struct segtree {
  segtree(pair<int, int>* a, int n) : a(a), n(n) {
    sort(a, a + n);
    build(1, 0, n - 1);
  }
  int lower(int p, int val) {
    return lower_bound(y[p].begin(), y[p].end(), val) - y[p].begin();
  }
  int upper(int p, int val) {
    return upper_bound(y[p].begin(), y[p].end(), val) - y[p].begin();
  }
  void add_bit(int p, int i, int val) {
    for(; i < y[p].size(); i |= i + 1) {
      bit[p][i] += val;
    }
  }
  int find_bit(int p, int i) {
    int ret = 0;
    for(; i >= 0; i = (i & (i + 1)) - 1) {
      if(i < bit[p].size()) {
        ret += bit[p][i];
      }
    }
    return ret;
  }
  int find_bit(int p, int l, int r) {
    return find_bit(r) - find(l - 1);
  }
  void build(int p, int l, int r) {
    for(int i = l; i <= r; i++) {
      y[p].push_back(a[i].second);
    }
    sort(y[p].begin(), y[p].end());
    y[p].resize(distance(y[p].begin(), unique(y[p].begin(), y[p].end())));
    bit[p].resize(y[p].size());
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
  }
  void add(int x, int y) {
    add(1, 0, n - 1, x, y);
  }
  void add(int p, int l, int r, int x, int y) {
    int t = lower(p, y);
    add_bit(p, t, 1);
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(x <= a[mid].first) {
      add(p + p, l, mid, x, y);
    } else {
      add(p + p + 1, mid + 1, r, x, y);
    }
  }
  int find(int x1, int y1, int x2, int y2) {
    return find(1, 0, n - 1, x1, x2, y1, y2);
  }
  int find(int p, int l, int r, int x1, int x2, int y1, int y2) {
    if(x2 < a[l].first && a[r].first < x1) return 0;
    if(x1 <= a[l].first && a[r].first <= x2) {
      return find_bit(p, lower(p, y1), upper(p, y2) - 1);
    }
    int ret = 0, mid = (l + r) >> 1;
    ret += find(p + p, l, mid, x1, x2, y1, y2);
    ret += find(p + p + 1, mid + 1, x1, x2, y1, y2);
    return ret;
  }
  vector<int> y[N << 2];
  vector<int> bit[N << 2];
  pair<int, int>* a;
  int n;
};

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    b[i]()
  }
  segtree seg[2];
  return 0;
}
