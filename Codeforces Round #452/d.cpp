
#include <bits/stdc++.h>

using namespace std;

long long n;

long long make(int nine, int at, int num) {
  long long ret = 0;
  for (int i = 0; i < nine; i++) {
    if (i == at) {
      ret = ret * 10 + num;
    }
    ret = ret * 10 + 9;
  }
  if (nine == at) {
    ret = ret * 10 + num;
  }
  return ret;
}

long long solve(long long sum) {
  long long l = max(1LL, sum - n);
  long long r = (sum - 1) / 2;
  return (l > r? 0 : r - l + 1);
}

int dig(long long n) {
  if (n < 10) return 1;
  return 1 + dig(n / 10);
}

int main() {
  scanf("%lld", &n);
  int d = dig(n);
  if (make(d, 0, 0) > 2 * n - 1) d--;
  if (d == 0) {
    cout << n * (n - 1) / 2 << endl;
    return 0;
  }
  long long ans = 0;
  for (int at = 0; at <= 0; at++) {
    for (int num = 0; num <= 8; num++) {
      long long sum = make(d, at, num);
      if (sum > 2 * n - 1) continue;
      ans += solve(sum);
    }
  }
  cout << ans << endl;
  return 0;
}
