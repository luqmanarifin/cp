#include <bits/stdc++.h>

using namespace std;

int main() {
  long long x1, y1, x2, y2;
  scanf("%I64d %I64d %I64d %I64d", &x1, &y1, &x2, &y2);
  int n, ans = 0;
  scanf("%d", &n);
  while(n--) {
    long long a, b, c;
    scanf("%I64d %I64d %I64d", &a, &b, &c);
    bool s1 = a*x1 + b*y1 + c > 0;
    bool s2 = a*x2 + b*y2 + c > 0;
    ans += s1 != s2;
  }
  cout << ans << endl;
  return 0;
}