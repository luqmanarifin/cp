#include <bits/stdc++.h>

using namespace std;

bool can(int a, int b, int k) {
  int d = b / k * k;
  return a <= d - k;
}

long long solve(int a, int b, int c, int d, int k) {
  if (k == 1) return 1LL * (b - a) * (d - c);
  if (!can(a, b, k) || !can(c, d, k)) return solve(a, b, c, d, k / 2);

  int upper_x = b / k * k;
  int ada_x = (upper_x - a) / k;
  int upper_y = d / k * k;
  int ada_y = (upper_y - c) / k;
  int low_x = upper_x - ada_x * k;
  int low_y = upper_y - ada_y * k;
  long long sum = 1LL * ada_x * ada_y;
  if (a < low_x && c < low_y) {
    sum += solve(a, low_x, c, low_y, k / 2);
  }
  if (c < low_y) {
    sum += solve(low_x, upper_x, c, low_y, k / 2);
  }
  if (upper_x < b && c < low_y) {
    sum += solve(upper_x, b, c, low_y, k / 2);
  }
  if (upper_x < b) {
    sum += solve(upper_x, b, low_y, upper_y, k / 2);
  }
  if (upper_x < b && upper_y < d) {
    sum += solve(upper_x, b, upper_y, d, k / 2);
  }
  if (upper_y < d) {
    sum += solve(low_x, upper_x, upper_y, d, k / 2);
  }
  if (a < low_x && upper_y < d) {
    sum += solve(a, low_x, upper_y, d, k / 2);
  }
  if (a < low_x) {
    sum += solve(a, low_x, low_y, upper_y, k / 2);
  }
  return sum;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%lld\n", solve(a, b, c, d, 1 << 20));
  }

  return 0;
}
