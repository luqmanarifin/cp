#include <bits/stdc++.h>

using namespace std;

#define int long long

pair<long long, long long> find(int xl, int xr, int yl, int yr, long long v) {
  if (xl == xr && yl == yr) {
    return {xl, yl};
  }
  long long tot = 1LL * (xr - xl + 1) * (yr - yl + 1);
  int xmid = (xl + xr) >> 1;
  int ymid = (yl + yr) >> 1;
  long long biji = tot / 4;
  if (v <= biji) {
    return find(xl, xmid, yl, ymid, v);
  } else if (v <= biji * 2) {
    return find(xmid + 1, xr, ymid + 1, yr, v - biji);
  } else if (v <= biji * 3) {
    return find(xmid + 1, xr, yl, ymid, v - 2 * biji);
  } else { 
    return find(xl, xmid, ymid + 1, yr, v - 3 * biji);
  }
}

long long find(int xl, int xr, int yl, int yr, int xp, int yp, long long v) {
  if (xl == xr && yl == yr) {
    return v + 1;
  }
  long long tot = 1LL * (xr - xl + 1) * (yr - yl + 1);
  int xmid = (xl + xr) >> 1;
  int ymid = (yl + yr) >> 1;
  long long biji = tot / 4;
  if (xp <= xmid && yp <= ymid) {
    return find(xl, xmid, yl, ymid, xp, yp, v);
  } else if (xp > xmid && yp > ymid) {
    return find(xmid + 1, xr, ymid + 1, yr, xp, yp, v + biji);
  } else if (xp > xmid && yp <= ymid) {
    return find(xmid + 1, xr, yl, ymid, xp, yp, v + 2 * biji);
  } else {
    return find(xl, xmid, ymid + 1, yr, xp, yp, v + 3 * biji);
  }
}

char s[5];

int32_t main() {
  int t;
  scanf("%lld", &t);
  while (t--) {
    int n, q;
    scanf("%lld %lld", &n, &q);
    while (q--) {
      scanf("%s", s);
      long long x, y;
      if (s[0] == '-') {
        scanf("%lld %lld", &x, &y);
        printf("%lld\n", find(1, 1 << n, 1, 1 << n, x, y, 0));
      } else {
        scanf("%lld", &x);
        auto it = find(1, 1 << n, 1, 1 << n, x);
        printf("%lld %lld\n", it.first, it.second);
      }
    }
  }

  return 0;
}
