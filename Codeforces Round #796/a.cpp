#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
long long s[N];

long long sum(long long n) {
  return n * (n + 1) / 2;
}

long long sum(long long l, long long r) {
  return sum(r) - sum(l - 1);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      s[i] = s[i - 1] + a[i];
    }
    long long ans = 0;
    if (k >= n) {
      ans = s[n] + sum(k - n, k - 1);
    } else {
      for (int i = k; i <= n; i++) {
        ans = max(ans, s[i] - s[i - k]);
      }
      ans += sum(1, k - 1);
    }
    printf("%lld\n", ans);
  }


  return 0;
}
