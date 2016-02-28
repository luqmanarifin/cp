#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

ull power(ull a, ull b, ull mod) {
  if(b == 0) return 1;
  ull temp = power(a, b / 2, mod);
  temp = temp * temp % mod;
  if(b & 1) {
    temp = temp * a % mod;
  }
  return temp;
}

int main() {
  ull n, p;
  cin >> n >> p;
  ull ans = power(2, n - 1, p);
  if(ans == 0) ans += p;
  cout << ans << endl;
  return 0;
}
