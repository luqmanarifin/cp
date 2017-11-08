#include <bits/stdc++.h>

using namespace std;

const int N = 105;

vector<tuple<int, int, double>> p, a;

int main() {
  int tx, ty, n;
  scanf("%d %d %d", &tx, &ty, &n);
  for (int i = 0; i < n; i++) {
    int u, v;
    double c;
    scanf("%d %d %lf", &u, &v, &c);
    p.emplace_back(u, v, c);
  }
  sort(p.begin(), p.end());
  int now = 0;
  for (auto it : p) {
    int u, v; double c;
    tie(u, v, c) = it;
    if (now < u) {
      a.emplace_back(now, u, 1);
    }
    a.emplace_back(u, v, c);
    now = v;
  }
  if (now < ty) {
    a.emplace_back(now, ty, 1);
  }
  double l = -1e15, r = 1e15;
  for (int it = 0; it < 200; it++) {
    double mid = (l + r) / 2;
    double x = 0;
    for (auto it : a) {
      int u, v; double c;
      tie(u, v, c) = it;
      int to = min(v, ty);
      if (u == to) break;
      double time = to - u;
      x += time * mid * c;
    }
    if (x < tx) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%.15f\n", r);
  return 0;
}
