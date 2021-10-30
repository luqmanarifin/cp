#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long mod = 998244353;

long long a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long bar = a[i];
      for (int j = i - 1; j >= 0; j--) {
        long long need = (a[j] + bar - 1) / bar;
        ans += (need - 1) * (j + 1);
        ans %= mod;
        bar = a[j] / need;
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
