#include <bits/stdc++.h>

using namespace std;

int main() {
  int R, d, n;
  scanf("%d %d %d", &R, &d, &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x, y, r;
    scanf("%d %d %d", &x, &y, &r);
    double dist = sqrt(x * x + y * y);
    if (R - d <= dist - r && dist + r <= R) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}