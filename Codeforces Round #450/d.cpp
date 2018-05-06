
#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  if (y % x) {
    puts("0");
    return 0;
  }
  y /= x;
  x /= x;
  vector<int> fac;
  for (int i = 1; i * i <= y; i++) {
    if (y % i == 0) {
      fac.push_back(i);
      if (i * i != y) {
        fac.push_back(y / i);
      }
    }
  }
  sort(fac.begin(), fac.end());
  vector<int> ans;
  for (int i = 0; i < fac.size(); i++) {
    long long now = power(2, fac[i] - 1);
    for (int j = 0; j < i; j++) {
      if (fac[i] % fac[j]) continue;
      now -= ans[j];
    }
    now %= mod;
    if (now < 0) now += mod;
    ans.push_back(now);
    //printf("%d: %lld\n", fac[i], now);
  }
  cout << ans.back() << endl;
  return 0;
}
