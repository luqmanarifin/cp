#include <bits/stdc++.h>

using namespace std;

long long sum(long long n) {
  return n * (n + 1) / 2;
}

int main() {
  // cout << sum(2e9) << endl;
  // cout << (long long) 1e18 << endl;

  long long n, h;
  cin >> n >> h;
  long long l = 1, r = min(h, (long long)2e9);
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    if (sum(mid) > n) {
      r = mid - 1;
    } else {
      l = mid;
    }
  }
  long long ans = l;
  n -= sum(l);

  long long biggest = l;

  long long full = n / biggest;
  ans += full;
  n -= full * biggest;

  if (n) ans++;
  cout << ans << endl;
  return 0;
}
