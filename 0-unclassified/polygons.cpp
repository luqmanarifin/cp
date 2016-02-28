#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

int ans[N];
pair<long long, int> p[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n_polygons;
    scanf("%d", &n_polygons);
    for(int i = 0; i < n_polygons; i++) {
      long long maxx = -inf, minx = inf, maxy = -inf, miny = inf;
      int n_points;
      scanf("%d", &n_points);
      while(n_points--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        maxx = max(maxx, a);
        minx = min(minx, a);
        maxy = max(maxy, b);
        miny = min(miny, b);
      }
      p[i].first = 1LL * (maxx - minx) * (maxy - miny);
      p[i].second = i;
    }
    sort(p, p + n_polygons);
    for(int i = 0; i < n_polygons; i++) {
      ans[p[i].second] = i;
    }
    for(int i = 0; i < n_polygons; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
  
  return 0;
}
