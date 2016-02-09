#include <bits/stdc++.h>

using namespace std;

long long digit(long long a) {
  long long ret = 1;
  while(a >= 10) {
    ret++;
    a /= 10;
  }
  return ret;
}

long long cnt(long long a, long long b) {
  //printf("%d %d\n", a, b);
  return 1LL * digit(a) * (b - a + 1);
}

int main() {
  long long n;
  scanf("%I64d", &n);
  long long bef = 1, now = 10;
  long long ans = 0;
  while(bef <= n) {
    ans += cnt(bef, min(now - 1, n));
    bef *= 10;
    now *= 10;
  }
  cout << ans << endl;
  return 0;
}
