#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b, int c, int d) {
  int dx = abs(a - c);
  int dy = abs(b - d);
  return max(dx, dy);
}

int a, b, c, d;

int check(int x, int y) {
  if (solve(x, y, a, b) >= solve(x, y, c, d)) {
    return solve(x, y, a, b) + 1;
  }
  return -1;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%d %d %d %d", &a, &b, &c, &d);
  if (a == c && b == d) {
    cout << 0 << endl;
    return 0;
  }
  if (a == c) {
    if (d < b) {
      cout << b << endl;
      return 0;
    } else {
      cout << m - b + 1 << endl;
      return 0;
    }
  }
  if (b == d) {
    if (c < a) {
      cout << a << endl;
      return 0;
    } else {
      cout << n - a + 1 << endl;
      return 0;
    }
  }
  int ans = 0;
  ans = max(ans, check(1, 1));
  ans = max(ans, check(1, m));
  ans = max(ans, check(n, 1));
  ans = max(ans, check(n, m));
  cout << ans << endl;
  return 0;
}
