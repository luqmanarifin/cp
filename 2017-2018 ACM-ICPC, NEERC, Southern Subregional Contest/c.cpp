#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const long long MAX = 2e7;

long long f, T, t0;
long long a1, t1, p1;
long long a2, t2, p2;

long long ceil(long long a, long long b) {
  return (a + b - 1) / b;
}

int main() {
  scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld", &f, &T, &t0, &a1, &t1, &p1, &a2, &t2, &p2);
  long long ans = inf;
  for (int it = 0; it < 2; it++) {
    long long til = ceil(f, a1);
    for (long long i = 0; i <= til; i++) {
      long long kos = max(0LL, f - i * a1);
      long long t = min(f, i * a1) * t1 + kos * t0;
      if (t > T) {
        if (t2 < t0) {
          long long perk_per_package = a2 * (t0 - t2);
          long long need_perk = t - T;
          long long max_perk = kos * (t0 - t2);
          if (need_perk <= max_perk) {
            long long j = ceil(need_perk, perk_per_package);
            ans = min(ans, i * p1 + j * p2);
          } else {
            continue;
          }
        } else {
          continue;
        }
      } else {
        ans = min(ans, i * p1);
      }
    }
    swap(a1, a2);
    swap(t1, t2);
    swap(p1, p2);
  }
  if (ans == inf) ans = -1;
  cout << ans << endl;
  return 0;
}
