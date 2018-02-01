#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n; cin >> n;
    int k = sqrt(n);
    long long ans = 0;
    for (int i = 1; i <= k; ++i)
      ans += n / i + n / i;
    ans -= k * k;
    cout << ans << endl;
  }

  return 0;
}
