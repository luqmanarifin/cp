/**

Heart beats fast
Colours and promises
How to be brave?
How can I love when I'm afraid to fall?
But watching you stand alone,
All of my doubt suddenly goes away somehow.

One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

Time stands still
Beauty in all she is
I will be brave
I will not let anything take away
What's standing in front of me
Every breath
Every hour has come to this

One step closer
One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

And all along I believed I would find you
Time has brought your heart to me
I have loved you for a thousand years
I'll love you for a thousand more

*/

#include <bits/stdc++.h>

using namespace std;

struct segtree {
  segtree() {}
  segtree(int n) : n(n) {
    num.assign(n << 2, 0);
    lazy.assign(n << 2, 0);
  }
  void relax(int p, int l, int r) {
    if (lazy[p]) {
      if (l < r) {
        lazy[p + p] += lazy[p];
        lazy[p + p + 1] += lazy[p];
      }
      num[p] += lazy[p];
      lazy[p] = 0;
    }
  }
  void combine(int p, int l, int r) {
    num[p] = max(num[p + p] + lazy[p + p], num[p + p + 1] + lazy[p + p + 1]);
  }
  
  void add(int l, int r) {
    add(1, 0, n - 1, l, r);
  }
  void add(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      lazy[p]++;
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    add(p + p, l, mid, ll, rr);
    add(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
  }
  int find() {
    return num[1] + lazy[1];
  }
  void set(int at, int val) {
    set(1, 0, n - 1, at, val);
  }
  void set(int p, int l, int r, int at, int val) {
    relax(p, l, r);
    if (r < at || at < l) return;
    if (l == r) {
      num[p] = val;
      return;
    }
    int mid = (l + r) >> 1;
    set(p + p, l, mid, at, val);
    set(p + p + 1, mid + 1, r, at, val);
    combine(p, l, r);
  }
  
  int n;
  vector<int> num, lazy;
};

const int N = 5e4 + 5;

char c[N];
int s[N], d[N];
int id[256];

segtree seg[2];
vector<pair<int, int>> a[N];
int ans[N];

int main() {
  id['D'] = id['M'] = 1;
  
  int t;
  scanf("%d", &t);
  while (t--) {
    fill(ans, ans + N, N);
    for (int i = 0; i < N; i++) a[i].clear();
    
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) scanf(" %c", c + i);
    for (int i = 0; i < n; i++) scanf("%d", s + i);
    for (int i = 0; i < n; i++) scanf("%d", d + i);
    seg[0] = segtree(m + 1);
    seg[1] = segtree(m + 1);
    for (int i = 0; i < n; i++) {
      if (s[i] < d[i]) {
        a[d[i]].emplace_back(s[i], id[c[i]]);
      }
    }
    for (int e = 1; e <= m; e++) {
      for (auto it : a[e]) {
        int st = it.first;
        int tp = it.second;
        seg[tp].add(0, st);
      }
      int best = max(seg[0].find(), seg[1].find());
      seg[0].set(e, best);
      seg[1].set(e, best);
      ans[best] = min(ans[best], e);
    }
    for (int i = n; i >= 1; i--) ans[i] = min(ans[i], ans[i + 1]);
    for (int i = 1; i <= n; i++) {
      if (ans[i] == N) ans[i] = -1;
      printf("%d%c", ans[i], " \n"[i == n]);
    }
  }

  return 0;
}
