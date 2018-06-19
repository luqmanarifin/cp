#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long s[N];

struct segtree {
  segtree(int n) : n(n) {
    num.assign(n << 2, 0);
    add.assign(n << 2, 0);
    build(1, 1, n);
  }
  void build(int p, int l, int r) {
    if (l == r) {
      num[p] = s[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p + p, l, mid);
    build(p + p + 1, mid + 1, r);
    num[p] = max(num[p + p], num[p + p + 1]);
  }
  void relax(int p, int l, int r) {
    if (add[p] != 0) {
      num[p] += add[p];
      if (l < r) {
        add[p + p] += add[p];
        add[p + p + 1] += add[p];
      }
      add[p] = 0;
    }
  }
  void combine(int p, int l, int r) {
    num[p] = max(num[p + p] + add[p + p], num[p + p + 1] + add[p + p + 1]);
  }
  void tambah(int l, int r, long long val) {
    tambah(1, 1, n, l, r, val);
  }
  void tambah(int p, int l, int r, int ll, int rr, long long val) {
    relax(p, l, r);
    if (ll <= l && r <= rr) {
      add[p] += val;
      relax(p, l, r);
      return;
    }
    if (r < ll || rr < l) return;
    int mid = (l + r) >> 1;
    tambah(p + p, l, mid, ll, rr, val);
    tambah(p + p + 1, mid + 1, r, ll, rr, val);
    combine(p, l, r);
  }
  int find(long long val) {
    return find(1, 1, n, val);
  }
  int find(int p, int l, int r, long long val) {
    relax(p, l, r);
    if (l == r) return l;
    long long lef = num[p + p] + add[p + p];
    long long rig = num[p + p + 1] + add[p + p + 1];
    int mid = (l + r) >> 1, ret = -1;
    if (lef < val) {
      relax(p + p, l, mid);
      ret = find(p + p + 1, mid + 1, r, val);
    } else {
      relax(p + p + 1, mid + 1, r);
      ret = find(p + p, l, mid, val);
    }
    combine(p, l, r);
    return ret;
  }
  long long find_at(int at) {
    return find_at(1, 1, n, at);
  }
  long long find_at(int p, int l, int r, int at) {
    relax(p, l, r);
    if (at < l || r < at) return -1;
    if (l == r) return num[p];
    int mid = (l + r) >> 1;
    long long ret = max(find_at(p + p, l, mid, at), find_at(p + p + 1, mid + 1, r, at));
    combine(p, l, r);
    return ret;
  }
  vector<long long> num, add;
  int n;
};

long long a[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    s[i] = s[i-1] + a[i];
    // printf("asu %d %lld\n", i, s[i]);
  }
  long long sum = s[n];
  segtree seg(n);
  // printf("masa "); for (int i = 1; i <= n; i++) printf("%lld ", seg.find_at(i)); printf("\n");

  while (q--) {
    int at; long long val;
    scanf("%d %lld", &at, &val);
    long long d = val - a[at];
    sum += d;
    seg.tambah(at, n, d);
    a[at] = val;

    // printf("masa "); for (int i = 1; i <= n; i++) printf("%lld ", seg.find_at(i)); printf("\n");

    if (a[1] == 0) {
      puts("1");
      continue;
    }
    long long now = a[1];
    int ans = -1;
    while (2 * now <= sum) {
      int p = seg.find(2 * now);
      // printf("now %lld: %d\n", now, p);
      long long bef = seg.find_at(p - 1);
      // printf("banding %lld %lld\n", bef, a[p]);
      if (bef == a[p]) {
        ans = p;
        break;
      }
      now = bef + a[p];
    }
    printf("%d\n", ans);
  }

  return 0;
}
