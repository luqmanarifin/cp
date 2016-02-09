#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  while(n--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    ans += (max(a, c) - min(a, c) + 1) * (max(b, d) - min(b, d) + 1);
  }
  cout << ans << endl;
  return 0;
}
