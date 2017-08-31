#include <bits/stdc++.h>

using namespace std;

const int BIT = 20;

struct segtree {
  segtree() {
    n = (1 << BIT);
    full.assign(n << 2, 0);
  }
  void insert(int v) {
    insert(1, 19, v);
  }
  void insert(int p, int i, int v) {
    if (i == -1) {
      full[p] = 1;
      return;
    }
    if (v & (1 << i)) {
      insert(p + p + 1, i - 1, v);
    } else {
      insert(p + p, i - 1, v);
    }
    full[p] = full[p + p] && full[p + p + 1];
  }
  int find(int val) {
    return find(1, 0, (1 << BIT) - 1, 19, val);
  }
  int find(int p, int l, int r, int i, int val) {
    if (i == -1) return l;
    int mid = (l + r) >> 1;
    if ((val & (1 << i)) == 0) {
      if (full[p + p] == 0) {
        return find(p + p, l, mid, i - 1, val);
      } else {
        return find(p + p + 1, mid + 1, r, i - 1, val);
      }
    } else {
      if (full[p + p + 1] == 0) {
        return find(p + p + 1, mid + 1, r, i - 1, val);
      } else {
        return find(p + p, l, mid, i - 1, val);
      }
    }
  }
  vector<int> full;
  int n;
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  segtree seg;
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    seg.insert(v);
  }
  int now = 0;
  while (m--) {
    int v;
    scanf("%d", &v);
    now ^= v;
    printf("%d\n", now ^ seg.find(now));
  }
  
  return 0;
}