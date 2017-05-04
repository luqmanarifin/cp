#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

char s[N];

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
  scanf("%s", s);
  int n = strlen(s);
  int now = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') now++;
    else {
      ans += power(2, now) - 1;
      ans %= mod;
    }
  }
  ans += mod;
  ans %= mod;
  cout << ans << endl;
  return 0;
}
