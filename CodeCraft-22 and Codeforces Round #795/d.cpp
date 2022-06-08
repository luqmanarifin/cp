#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const long long INF = 1e18;

struct segtree {
  segtree(int n) : n(n) {
    num.assign(n << 2, 0);
    push.assign(n << 2, 0);
  }
  void lazy(int p, int l, int r) {
    if (push[p] != 0) {
      if (l < r) {
        push[p + p] += push[p];
        push[p + p + 1] += push[p];
      }
      num[p] += push[p];
      push[p] = 0;
    }
  }
  void add(int l, int r, long long val) {
    add(1, 1, n, l, r, val);
  }
  void add(int p, int l, int r, int ll, int rr, long long val) {
    lazy(p, l, r);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
      push[p] += val;
      lazy(p, l, r);
      return;
    }
    int mid = (l + r) >> 1;
    add(p + p, l, mid, ll, rr, val);
    add(p + p + 1, mid + 1, r, ll, rr, val);
    num[p] = max(num[p + p], num[p + p + 1]);
  }
  long long find(int l, int r) {
    return find(1, 1, n, l, r);
  }
  long long find(int p, int l, int r, int ll, int rr) {
    lazy(p, l, r);
    if (r < ll || rr < l) return -INF;
    if (ll <= l && r <= rr) return num[p];
    int mid = (l + r) >> 1; long long ret = -INF;
    ret = max(ret, find(p + p, l, mid, ll, rr));
    ret = max(ret, find(p + p + 1, mid + 1, r, ll, rr));
    num[p] = max(num[p + p], num[p + p + 1]);
    return ret;
  }
  vector<long long> num, push;
  int n;
};

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);

    segtree seg(n);
    stack<tuple<int, int, int>> s;
    s.emplace(a[n], n, n);
    bool found = 0;
    for (int i = n - 1; i >= 1; i--) {
      // update sum
      seg.add(i, n, a[i]);

      // update max
      seg.add(i, i, -a[i]);
      int til = i;
      while (!s.empty() && a[i] >= get<0>(s.top())) {
        int v, l, r;
        tie(v, l, r) = s.top();
        s.pop();
        seg.add(l, r, v - a[i]);
        til = r;
      }
      s.emplace(a[i], i, til);
      if (seg.find(i, n) > 0) {
        found = 1;
        break;
      }
    }
    puts(found? "NO" : "YES");
  }
  return 0;
}
