#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long power(int a, int b) {
  if(b == 0) return 1;
  long long temp = power(a, b / 2);
  temp = temp * temp % mod;
  if(b & 1) temp = temp * a % mod;
  return temp;
}

int main() {
  int n;
  scanf("%d", &n);
  long long ans = power(27, n) - power(7, n);
  if(ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}
