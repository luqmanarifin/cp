#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int cur = min(a / i, b / (n - i));
    ans = max(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
