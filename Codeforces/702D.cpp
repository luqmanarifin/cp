#include <bits/stdc++.h>

using namespace std;

long long d, k, a, b, t;

int main() {
  scanf("%I64d %I64d %I64d %I64d %I64d", &d, &k, &a, &b, &t);
  long long ans = d * b;
  
  long long naik = min(d, k);
  ans = min(ans, naik * a + (d - naik) * b);
  
  if (t + k * a < k * b) {
    long long cnt = d / k;
    if (cnt) {
      ans = min(ans, cnt * k * a + (cnt - 1) * t + min(b * (d % k), t + a * (d % k)));
    }
  }
  cout << ans << endl;
  return 0;
}