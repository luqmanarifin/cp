#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return b? gcd(b, a % b) : a;
}

long long lcm(int a, int b) {
  return 1LL * a * b / gcd(a, b);
}

int a[505];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    long long ans = 4e18;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        ans = min(ans, lcm(a[i], a[j]));
      }
    }
    cout << ans << endl;
  }

  return 0;
}
