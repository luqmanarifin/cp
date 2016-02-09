#include <bits/stdc++.h>

using namespace std;

long long mod;

long long power(long long a, long long b) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2);
  temp *= temp;
  temp %= mod;
  if(b & 1) {
    temp *= a;
    temp %= mod;
  }
  return temp;
}

int main() {
  long long n;
  cin >> n >> mod;
  long long ans = power(3, n) - 1;
  ans %= mod;
  if(ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}