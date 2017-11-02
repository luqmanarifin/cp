#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long ans = 1;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      ans = (ans * (a + 1)) % mod;
    }
    ans--;
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << ans << endl;
  }
  return 0;
}
