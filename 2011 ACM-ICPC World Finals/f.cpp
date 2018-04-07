#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, c, D;
int d[N], p[N], r[N], g[N], id[N];

typedef long long ll;

const ll is_query = -(1LL<<62);
struct Line {
  ll m, b;
  mutable function<const Line*()> succ;
  bool operator<(const Line& rhs) const {
    if (rhs.b != is_query) return m < rhs.m;
    const Line* s = succ();
    if (!s) return 0;
    ll x = rhs.m;
    return b - s->b < (long double)(s->m - m) * x;
  }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
  bool bad(iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b;
    }
    auto x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    return (long double)(x->b - y->b)*(z->m - y->m) >= (long double)(y->b - z->b)*(y->m - x->m);
  }
  void insert_line(ll m, ll b) {
    auto y = insert({ m, b });
    y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
    if (bad(y)) { erase(y); return; }
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }
  ll eval(ll x) {
    auto l = *lower_bound((Line) { x, is_query });
    return l.m * x + l.b;
  }
};

int main() {
  scanf("%d %d %d", &n, &c, &D);
  for (int tc = 1; n || c || D; ++tc) {
    for (int i = 0; i < n; ++i) {
      scanf("%d %d %d %d", d+i, p+i, r+i, g+i);
      id[i] = i;
    }
    sort(id, id+n, [&](int l, int r) { return d[l] < d[r]; });
    HullDynamic hd;
    hd.insert_line(0, c);
    for (int i = 0; i < n;) {
      int v = id[i];
      int now = d[v];
      long long val = hd.eval(now-1);
      while (i < n && d[id[i]] == now) {
        v = id[i];
        if (p[v] <= val)
          hd.insert_line(g[v], val - p[v] + r[v] - 1LL * g[v] * d[v]);
        ++i;
      }
    }
    printf("Case %d: %lld\n", tc, hd.eval(D));
    scanf("%d %d %d", &n, &c, &D);
  }
  return 0;
}
