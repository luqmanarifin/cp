#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long done = 1, ans = 0, now = 1;
    while (done < n) {
      if (now >= k) {
        long long rem = n - done;
        ans += (rem + k - 1) / k;
        break;
      }
      ans++;
      long long add = min(k, now);
      done += add;
      now += add;
    }
    printf("%lld\n", ans);
  }

  return 0;
}
