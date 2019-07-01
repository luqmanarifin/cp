#include <bits/stdc++.h>

using namespace std;

// segment tree
// add range
// max range

const int N = 1e6 + 5;
const int inf = 1e9;
const long long mod = 1e9 + 7;

int num[N << 2], push[N << 2], a[N];

struct segtree {
  segtree(int n) : n(n) {
    build(1, 1, n);
  }
  void build(int p, int l, int r) {
    if (l == r) {
      num[p] = a[l];
      push[p] = 0;
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = max(num[p + p], num[p + p + 1]);
    push[p] = 0;
  }
  void relax(int p, int l, int r) {
    if (push[p] != 0) {
      if (l < r) {
        push[p + p] += push[p];
        push[p + p + 1] += push[p];
      }
      num[p] += push[p];
      push[p] = 0;
    }
  }
  void combine(int p, int l, int r) {
    num[p] = max(num[p + p], num[p + p + 1]);
  }

  void add(int l, int r, int val) {
    add(1, 1, n, l, r, val);
  }
  void add(int p, int l, int r, int ll, int rr, int val) {
    relax(p, l, r);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
      push[p] += val;
      relax(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    add(p + p, l, mid, ll, rr, val);
    add(p + p + 1, mid + 1, r, ll, rr, val);
    combine(p, l, r);
  }
  int find(int l, int r) {
    return find(1, 1, n, l, r);
  }
  int find(int p, int l, int r, int ll, int rr) {
    // printf("%d %d %d %d %d\n", p, l, r, ll, rr);
    relax(p, l, r);
    if (r < ll || rr < l) return -inf;
    if (ll <= l && r <= rr) return num[p];
    int mid = (l + r) >> 1;
    int ret = max(find(p + p, l, mid, ll, rr), find(p + p + 1, mid + 1, r, ll, rr));
    combine(p, l, r);
    return ret;
  }
  int n;
};

char s[N];
long long two[N];

int main() {
  two[0] = 1;
  for (int i = 1; i < N; i++) {
    two[i] = two[i-1] * 2 % mod;
  }

  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, k;
    scanf("%d %d %s", &n, &k, s + 1);
    int num = 0;
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'A') {
        num--;
      } else {
        num++;
      }
      a[i] = 0;
    }
    segtree seg(n);
    vector<int> v;
    long long ans = 0;
    for (int i = n; i >= 1; i--) {
      seg.add(i, n, s[i] == 'A'? -1 : +1);
      if (s[i] == 'B') {
        v.push_back(i);
      }
      while (seg.find(i, n) > k) {
        auto it = v.back();
        v.pop_back();
        seg.add(it, n, -2);
        ans += two[it];
        ans %= mod;
      }
    }

    printf("Case #%d: %lld\n", tt, ans);
    cerr << tt << " done!" << endl;
  }

  return 0;
}
