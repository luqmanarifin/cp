/**

Heart beats fast
Colours and promises
How to be brave?
How can I love when I'm afraid to fall?
But watching you stand alone,
All of my doubt suddenly goes away somehow.

One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

Time stands still
Beauty in all she is
I will be brave
I will not let anything take away
What's standing in front of me
Every breath
Every hour has come to this

One step closer
One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

And all along I believed I would find you
Time has brought your heart to me
I have loved you for a thousand years
I'll love you for a thousand more

*/

#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 2e5 + 5;

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long half;

long long arith(long long a, long long b, long long n) {
  return (2*a + (n - 1)*b%mod) % mod * n % mod * half % mod;
}

long long sum(long long l, long long r) {
  return arith(l, 1, r - l + 1);
}

long long sum(long long n) {
  return sum(1, n);
}

long long solve(long long n, long long m) {
  return arith(sum(m), m, n);
}

long long a[N];

long long polos(long long n) {
  return n * (n + 1) / 2;
}

int main() {
#define int long long
  half = inv(2);
  //for (int i = 1; i <= 10; i++) printf("%lld\n", arith(1, 1, i));
  
  int n;
  scanf("%lld", &n);
  if (n > 4000) assert(0);
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
  }
  long long tot = polos(polos(n));
  long long ans = 0, maxi = 0;
  for (int i = 0; i < n; i++) {
    int now = a[i];
    maxi = max(maxi, now);
    for (int j = i; j < n; j++) {
      if (i == 0 && j == n - 1) continue;
      int ada = j - i + 1;
      now = max(now, a[j]);
      ans += now * ada;
      ans %= mod;
      tot -= ada;
    }
    now = max(now, a[0]);
    for (int j = 1; j + 1 < i; j++) {
      int ada = min(j, n - i);
      now = max(now, a[j]);
      ans += now * ada;
      ans %= mod;
      tot -= ada;
    }
  }
  ans += tot % mod * maxi;
  ans %= mod;
  cout << ans << endl;
  return 0;
}
