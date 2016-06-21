#include <bits/stdc++.h>

using namespace std;

const int N = 75e3 + 5;

int a[N], ql[N], qr[N];
vector<int> push, cnt;

struct segtree {
  segtree(int n, vector<int> tmp) : n(n), tmp(tmp) {
    if(push.empty()) {
      push.resize(n << 2);
      cnt.resize(n << 2);
    }
    build(1, 0, n - 1);
  }
  void combine(int p, int l, int r) {
    cnt[p] = cnt[p + p] + cnt[p + p + 1];
  }
  void relax(int p, int l, int r) {
    if(push[p] != -1) {
      if(l != r) {
        push[p + p] = push[p + p + 1] = push[p];
      }
      if(push[p] == 0) {
        cnt[p] = r - l + 1;
      } else {
        cnt[p] = 0;
      }
      push[p] = -1;
    }
  }

  void build(int p, int l, int r) {
    push[p] = -1;
    cnt[p] = r - l + 1;
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    combine(p, l, r);
  }

  void update(int l, int r, int v) {
    update(1, 0, n - 1, l, r, v);
  }

  void update(int p, int l, int r, int ll, int rr, int v) {
    relax(p, l, r);
    if(ll <= l && r <= rr) {
      push[p] = v;
      relax(p, l, r);
      return;
    }
    if(r < ll || rr < l) {
      return;
    }
    int mid = (l + r) >> 1;
    update(p + p, l, mid, ll, rr, v);
    update(p + p + 1, mid + 1, r, ll, rr, v);
    combine(p, l, r);
  }

  int find(int l, int r) {
    return find(1, 0, n - 1, l, r);
  }

  int find(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if(ll <= l && r <= rr) {
      return cnt[p];
    }
    if(r < ll || rr < l) {
      return 0;
    }
    int mid = (l + r) >> 1;
    return find(p + p, l, mid, ll, rr) + find(p + p + 1, mid + 1, r, ll, rr);
  }
  int n;
  vector<int> tmp;
};

int main() {
  int n, q, k;
  scanf("%d %d %d", &n, &q, &k);
  int mn = 2e9 + 5;
  int mk = -mn;
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    mn = min(mn, a[i]);
    mk = max(mk, a[i]);
  }
  for(int i = 0; i < q; i++) {
    scanf("%d %d", ql + i, qr + i);
  }
  int l = mn, r = mk;
  while(l < r) {
    int mid = (l + r) >> 1;
    segtree seg(n);
    for(int i = 0; i < n; i++) {
      seg.update(i, i, a[i] >= mid);
    }
    for(int i = 0; i < q; i++) {
      int count = seg.find(ql[i], qr[i]);
      seg.update(ql[i], ql[i] + count - 1, 0);
      seg.update(ql[i] + count, qr[i], 1);
    }
    int val = !seg.find(k, k);
    if(val) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
  return 0;
}
