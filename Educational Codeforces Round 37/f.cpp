#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int NODE = 3e5 + 5;
const int MAX = 6;

int last[N], divs[N], step[N];
int a[NODE][7], added[NODE];

struct segtree {
  segtree(int n) : n(n) {
    ans.resize(n << 2);
    done.resize(n << 2);
    c.resize(n << 2);
    build(1, 1, n);
  }
  void build(int p, int l, int r) {
    done[p] = c[p] = 0;
    if (l == r) {
      ans[p] = a[l][0];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    ans[p] = ans[p + p] + ans[p + p + 1];
  }
  void relax(int p, int l, int r) {
    if (c[p]) {
      if (l < r) {
        c[p + p] = c[p + p + 1] = 1;
      }
      if (!done[p]) {
        ans[p] = 0;
        done[p] = 1;
        for (int i = l; i <= r; i++) {
          if (added[i] != MAX) done[p] = 0;
          ans[p] += a[i][added[i]];
        }
      }
      c[p] = 0;
    }
  }
  void combine(int p, int l, int r) {
    ans[p] = ans[p + p] + ans[p + p + 1];
  }
  void tambah(int l, int r, int v) {
    tambah(1, 1, n, l, r, v);
  }
  void tambah(int p, int l, int r, int ll, int rr, int v) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      if (!done[p]) {
        for (int i = l; i <= r; i++) added[i] = min(MAX, added[i] + v);
        c[p] = 1;
      }
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    tambah(p + p, l, mid, ll, rr, v);
    tambah(p + p + 1, mid + 1, r, ll, rr, v);
    combine(p, l, r);
  }
  long long find(int l, int r) {
    return find(1, 1, n, l, r);
  }
  long long find(int p, int l, int r, int ll, int rr) {
    relax(p, l, r);
    if (ll <= l && r <= rr) return ans[p];
    if (r < ll || rr < l) return 0;
    int mid = (l + r) >> 1;
    long long ret = find(p + p, l, mid, ll, rr) + find(p + p + 1, mid + 1, r, ll, rr);
    combine(p, l, r);
    return ret;
  }
  vector<long long> ans;
  vector<int> done, c;
  int n;
};

int main() {
  for (int i = 2; i < N; i++) {
    if (last[i] == 0) {
      for (long long j = i; j < N; j += i) {
        last[j] = i;
      }
    }
  }
  divs[1] = 1;
  int pol = 0;
  for (int i = 2; i < N; i++) {
    int ada = 0;
    int now = i;
    while (now % last[i] == 0) {
      ada++;
      now /= last[i];
    }
    //printf("%d last %d ada %d\n", i, last[i], ada);
    divs[i] = divs[now] * (ada + 1);
    if (divs[i] < i) {
      step[i] = step[divs[i]] + 1;
      pol = max(pol, step[i]);
    }
  }
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i][0]);
    for (int j = 1; j <= MAX; j++) {
      a[i][j] = divs[a[i][j-1]];
    }
  }
  segtree seg(n);
  while (q--) {
    int t, l, r;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1) {
      seg.tambah(l, r, 1);
    } else {
      printf("%lld\n", seg.find(l, r));
    }
  }
  return 0;
}
