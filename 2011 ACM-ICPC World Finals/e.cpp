#include <bits/stdc++.h>

using namespace std;

const int N = 4e3 + 4, C = 1e6 + 5;;

int n, m, c, q;
int x[C], y[C];
int val[N], add[N];

int main() {
  for (int tc = 1; (scanf("%d %d %d %d", &n, &m, &c, &q) == 4 && n && m); ++tc) {
    printf("Case %d:\n", tc);
    for (int i = 0; i < c; ++i)
      scanf("%d %d", x+i, y+i), --x[i], --y[i];
    while (q--) {
      int d;
      scanf("%d", &d);
      vector<tuple<int, int, int, int> > ev;
      for (int i = 0; i < c; ++i) {
        ev.emplace_back(max(y[i]-x[i]-d, -n+1), max(y[i]+x[i]-d, 0), min(y[i]+x[i]+d+1, n+m), 1);
        ev.emplace_back(min(y[i]-x[i]+d+1, m), max(y[i]+x[i]-d, 0), min(y[i]+x[i]+d+1, n+m), -1);
      }
      sort(ev.begin(), ev.end());
      tuple<int, int, int> best(-1, -1, -1);
      fill(val, val+n+m, 0);
      for (int u = -n, i = 0; u <= m; ++u) {
        fill(add, add+n+m, 0);
        while (i < ev.size() && get<0>(ev[i]) == u) {
          int l, r, k;
          tie(ignore, l, r, k) = ev[i];
          add[l] += k;
          add[r] -= k;
          ++i;
        }
        for (int v = 0, now = 0; v < n+m; ++v) {
          now += add[v];
          val[v] += now;
          if ((u & 1) == (v & 1)) {
            int yy = (u+v)/2, xx = v - yy;
            if (0 <= xx && xx < n && 0 <= yy && yy < m) {
              tuple<int, int, int> cur(val[v], -yy, -xx);
              if (cur > best)
                best = cur;
            }
          }
        }
      }
      int k, xx, yy;
      tie(k, yy, xx) = best;
      printf("%d (%d,%d)\n", k, -xx+1, -yy+1);
    }
  }
  
  
  return 0;
}
