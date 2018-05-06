
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long ans = 0;
  for (int b = k + 1; b <= n; b++) {
    ans += b - k;
    long long til = n / b * b;
    long long block = (til - b) / b;
    ans += block * (b - k);
    if (n % b >= k) {
      ans += n % b - k + 1;
    }
  }
  if (k == 0) ans -= n;
  cout << ans << endl;
  return 0;
}
