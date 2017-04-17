#include <bits/stdc++.h>

using namespace std;

double pointToLine(long long x, long long y, long long x1, long long y1, long long x2, long long y2) {

  long long A = x - x1;
  long long B = y - y1;
  long long C = x2 - x1;
  long long D = y2 - y1;

  long long dot = A * C + B * D;
  long long len_sq = C * C + D * D;
  double param = (double) dot / len_sq;

  double xx, yy;

  if (param < 0) {
    xx = x1;
    yy = y1;
  }
  else if (param > 1) {
    xx = x2;
    yy = y2;
  }
  else {
    xx = x1 + param * C;
    yy = y1 + param * D;
  }

  double dx = x - xx;
  double dy = y - yy;
  return sqrt(dx * dx + dy * dy);
}

const int N = 1005;

int x[N], y[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", x + i, y + i);
  double ans = 1e18;
  for (int i = 0; i < n; i++) {
    int bef = (i - 1 + n) % n;
    int aft = (i + 1 + n) % n;
    ans = min(ans, pointToLine(x[i], y[i], x[bef], y[bef], x[aft], y[aft]) / 2);
  }
  printf("%.15f\n", ans);
  return 0;
}