#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;

int main() {
  int n;
  scanf("%d", &n);
  long long sumi = 0;
  long long sum = 0;
  long long sumd = 0;
  long long dua = 1;
  long long diag = 0;
  long long triangle = 0;
  long long ans = 0;
  long long all = 0;
  long long first;
  long long carry = 0;
  for (int i = 0; i < n; i++) {
    if (i >= 2) dua = dua * 2 % mod;
    int a;
    scanf("%d", &a);
    if (i == 0) first = a;
    sumi = (sumi + i) % mod;
    triangle = (triangle - diag + mod) % mod;
    if (i) {
      triangle += triangle - (sum - first) * i;
      triangle %= mod;
      if (triangle < 0) triangle += mod;
    }
    sum += a; sum %= mod;
    triangle += sum * (i + 1); triangle %= mod;
    carry = carry * 2 + i; carry %= mod;
    triangle += 1LL * a * carry; triangle %= mod;
    sumd += dua * a; sumd %= mod;
    diag += sumd; diag %= mod;
    ans = all + triangle; ans %= mod;
    all += ans; all %= mod;
  }
  cout << ans << endl;
  return 0;
}