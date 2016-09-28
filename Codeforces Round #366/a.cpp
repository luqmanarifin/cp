#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

struct segtree {
  segtree(int n) : n(n) {
    push.assign(n << 2, -1);
    a.resize(n << 2);
    build(1, 1, n);
  }
  void build(int p, int l, int r) {
    a[p] = r - l + 1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
  }
  void relaks(int p, int l, int r) {
    if (push[p] != -1) {
      if (l != r) {
        push[p + p] = 0;
        push[p + p + 1] = 0;
      }
      a[p] = 0;
      push[p] = -1;
    }
  }
  void combine(int p, int l, int r) {
    a[p] = a[p + p] + a[p + p + 1];
  }
  int find(int l, int r) {
    return find(1, 1, n, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    relaks(p, l, r);
    if (rr < l || r < ll) return 0;
    if (ll <= l && r <= rr) return a[p];
    int mid = (l + r) >> 1;
    int ret = find(p + p, l, mid, ll, rr);
    ret += find(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
    return ret;
  }
  void update(int l, int r) {
    update(1, 1, n, l, r);
  }
  void update(int p, int l, int r, int ll, int rr) {
    relaks(p, l, r);
    if (rr < l || r < ll) return;
    if (ll <= l && r <= rr) {
      push[p] = 0;
      relaks(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr);
    update(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
  }
  int n;
  vector<int> push, a;
};

vector<int> at[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  int now = 0;
  segtree seg(q);
  while (q--) {
    int t, v;
    scanf("%d %d", &t, &v);
    if (t == 1) {
      at[v].push_back(++now);
    } else if (t == 2) {
      for (auto it : at[v]) {
        seg.update(it, it);
      }
      at[v].clear();
    } else {
      seg.update(1, v);
    }
    printf("%d\n", seg.find(1, now));
  }
  
  return 0;
}
