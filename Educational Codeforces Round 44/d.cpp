#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

ull sum(ull n) {
  return n * (n + 1) / 2;
}

void asu(ull n, ull h) {
  ull ans = h + 1;
  n -= sum(h) + h;

  ull l = h, r = 2e9 + 5e8;
  while (l < r) {
    ull mid = (l + r + 1) >> 1;
    ull need = mid + 2 * (sum(mid - 1) - sum(h));
    if (need > n) {
      r = mid - 1;
    } else {
      l = mid;
    }
  }
  long long biggest = h;
  if (l > h) {
    biggest = l;
    long long len = l - h;
    ans += 2 * (len - 1) + 1;
    n -= l + 2 * (sum(l - 1) - sum(h));
  }

  ull full = n / biggest;
  ans += full;
  n -= full * biggest;

  if (n) ans++;
  cout << ans << endl;
}

int main() {
  // cout << sum(2e9 + 5e8) << endl;
  // cout << sum(2e9 + 5e8) - sum(1e9 + 5e8) << endl;
  // cout << (ull) 1e18 << endl;


  ull n, h;
  cin >> n >> h;
  if (h < 2e9 && n >= sum(h) + h) {
    asu(n, h);
    return 0;
  }
  ull l = 1, r = min(h, (ull)2e9);
  while (l < r) {
    ull mid = (l + r + 1) >> 1;
    if (sum(mid) > n) {
      r = mid - 1;
    } else {
      l = mid;
    }
  }
  ull ans = l;
  n -= sum(l);

  ull biggest = l;

  ull full = n / biggest;
  ans += full;
  n -= full * biggest;

  if (n) ans++;
  cout << ans << endl;
  return 0;
}
