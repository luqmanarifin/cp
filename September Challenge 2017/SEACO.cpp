#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

struct segtree {
  segtree(int n) : n(n) {
    a.assign(n << 2, 0);
  }
  void add(int l, int r, int val) {
    add(1, 1, n, l, r, val);
  }
  void add(int p, int l, int r, int ll, int rr, int val) {
    if (ll <= l && r <= rr) {
      a[p] += val;
      a[p] %= mod;
      return;
    }
    int mid = (l + r) >> 1;
    if (ll <= mid) add(p + p, l, mid, ll, rr, val);
    if (mid < rr) add(p + p + 1, mid + 1, r, ll, rr, val);
  }
  int find(int at) {
    return find(1, 1, n, at);
  }
  int find(int p, int l, int r, int at) {
    if (l == r) return a[p];
    int mid = (l + r) >> 1;
    if (at <= mid) {
      return (a[p] + find(p + p, l, mid, at)) % mod;
    } else {
      return (a[p] + find(p + p + 1, mid + 1, r, at)) % mod;
    }
  }
  vector<int> a;
  int n;
};

int t[N], l[N], r[N];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= q; i++) {
      scanf("%d %d %d", t + i, l + i, r + i);
    }
    segtree arr(n);
    segtree que(q);
    que.add(1, q, 1);
    for (int i = q; i >= 1; i--) {
      if (t[i] == 1) {
        int kali = que.find(i);
        arr.add(l[i], r[i], kali);
      } else {
        int kali = que.find(i);
        que.add(l[i], r[i], kali);
      }
    }
    for (int i = 1; i <= n; i++) printf("%d ", arr.find(i)); printf("\n");
  }
  
  return 0;
}