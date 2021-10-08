#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long s, n, k;
    scanf("%lld %lld %lld", &s, &n, &k);
    if (n == 1) {
      puts(s == k? "YES" : "NO");
    } else {
      puts(k <= s? "YES" : "NO");
    }
  }

  return 0;
}
