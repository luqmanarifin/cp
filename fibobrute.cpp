#include <bits/stdc++.h>

using namespace std;

const long long mod = 99991LL;

map<long long, long long> F;

long long f(long long n) {
  if (F.count(n)) return F[n];
  long long k=n/2;
  if (n%2==0) { // n=2*k
    return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % mod;
  } else { // n=2*k+1
    return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % mod;
  }
}

int a[mod];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  long long ans = 0;
  F[0] = F[1] = 1;
  for(int mask = 0; mask < (1 << n); mask++) {
    int bit = __builtin_popcount(mask);
    if(bit != k) {
      continue;
    }
    long long sum = 0;
    for(int i = 0; i < n; i++) if(mask & (1 << i)) {
      sum += a[i];
    }
    ans += f(sum - 1);
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
