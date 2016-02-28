#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9 + 5;

tuple<int, int, int> a[N];
#define x(n) get<0>(n)
#define y(n) get<1>(n)
#define i(n) get<2>(n)

bool xas_yas(tuple<int, int, int> l, tuple<int, int, int> r) {
  if(x(l) != x(r)) return x(l) < x(r);
  return y(l) < y(r);
}

bool xas_yds(tuple<int, int, int> l, tuple<int, int, int> r) {
  if(x(l) != x(r)) return x(l) < x(r);
  return y(l) > y(r);
}

bool xds_yas(tuple<int, int, int> l, tuple<int, int, int> r) {
  if(x(l) != x(r)) return x(l) > x(r);
  return y(l) < y(r);
}

bool xds_yds(tuple<int, int, int> l, tuple<int, int, int> r) {
  if(x(l) != x(r)) return x(l) > x(r);
  return y(l) > y(r);
}


int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    int minx = inf, miny = inf, maxx = -inf, maxy = -inf;
    for(int i = 0; i < n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      a[i] = make_tuple(x, y, i);
      maxx = max(maxx, x);
      minx = min(minx, x);
      maxy = max(maxy, y);
      miny = min(miny, y);
    }
    sort(a, a + n, xas_yas);
    if(x(a[0]) == minx && y(a[0]) == miny) {
      puts("1");
      printf("%d NE\n", i(a[0]) + 1);
      continue;
    }
    sort(a, a + n, xas_yds);
    if(x(a[0]) == minx && y(a[0]) == maxy) {
      puts("1");
      printf("%d SE\n", i(a[0]) + 1);
      continue;
    }
    sort(a, a + n, xds_yas);
    if(x(a[0]) == maxx && y(a[0]) == miny) {
      puts("1");
      printf("%d NW\n", i(a[0]) + 1);
      continue;
    }
    sort(a, a + n, xds_yds);
    if(x(a[0]) == maxx && y(a[0]) == maxy) {
      puts("1");
      printf("%d SW\n", i(a[0]) + 1);
      continue;
    }
    sort(a, a + n);
    puts("2");
    if(y(a[0]) < y(a[1])) {
      printf("%d NE\n", i(a[0]) + 1);
      printf("%d SE\n", i(a[1]) + 1);
    } else {
      printf("%d SE\n", i(a[0]) + 1);
      printf("%d NE\n", i(a[1]) + 1);
    }
  }
  return 0;
}
