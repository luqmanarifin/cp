#include <bits/stdc++.h>

using namespace std;

long long d, k, a, b, t;

long long find(long long kali) {
  return kali * k * a + (kali - 1) * t + b * (d - kali * k);
}

int main() {
  scanf("%I64d %I64d %I64d %I64d %I64d", &d, &k, &a, &b, &t);
  long long ans = d * b;
  
  long long naik = min(d, k);
  ans = min(ans, naik * a + (d - naik) * b);
  
  if (t + k * a < k * b) {
    long long kali = d / k;
    if (kali) {
      ans = min(ans, find(kali));
    }
  }
  cout << ans << endl;
  return 0;
}
