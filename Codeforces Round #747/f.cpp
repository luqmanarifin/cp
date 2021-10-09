#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long s, n, k;
    scanf("%lld %lld %lld", &s, &n, &k);
    if (s == k) {
      puts("YES");
      continue;
    }
    long long ans = s / (2 * k) * k;
    long long rem = s % (2 * k);
    ans += min(rem + 1, k);
    puts(n + 1 > ans? "YES" : "NO");
  }
  return 0;
}
