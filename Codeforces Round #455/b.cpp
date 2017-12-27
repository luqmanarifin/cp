#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cur = i * (n - i + 1);
    ans = max(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
