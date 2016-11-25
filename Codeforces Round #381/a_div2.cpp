#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, a, b, c;
  scanf("%I64d %I64d %I64d %I64d", &n, &a, &b, &c);
  long long ans = 1e18;
  for (int i = 0; i <= 4; i++) {
    for (int j = 0; j <= 4; j++) {
      for (int k = 0; k <= 4; k++) {
        long long tot = n + i + 2 * j + 3 * k;
        if (tot % 4 == 0) {
          ans = min(ans, i * a + j * b + k * c);
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
