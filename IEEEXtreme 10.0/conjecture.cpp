#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector<ll> A({2, 3, 5, 7, 11, 13, 17, 19, 23});
// if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.

ll fastexp(ll a, ll b, ll n) { // compute (a ^ b) mod n
  if (b == 0) return 1 % n;
  ll tmp = fastexp(a, b / 2, n);
  tmp = tmp * tmp % n;
  if (b & 1) {
    tmp = tmp * a % n;
  }
  return tmp;
}

bool mrtest(ll n)
{
    if(n == 1) return false;
    ll d = n-1;
    ll s = 0;
    while(d % 2 == 0)
    {
        s++;
        d /= 2;
    }
    for(ll j=0;j<(ll)A.size();j++)
    {
        if(A[j] > n-1) continue;
        ll ad = fastexp(A[j], d, n);
        if(ad % n == 1) continue;
        bool notcomp = false;
        for(ll r=0;r<=max(0ll,s-1);r++)
        {
            ll rr = fastexp(2,r,n);
            ll ard = fastexp(ad, rr, n);            
            if(ard % n == n-1) {notcomp = true; break;}
        }
        if(!notcomp)
        {
            return false;
        }
    }
    return true;
}

void brute(long long n) {
  int a = 3;
  n -= a;
  for (long long it = 2; it <= n; it++) {
    if (mrtest(it) && mrtest(n - it)) {
      printf("%d %lld %lld\n", a, it, n - it);
      return;
    }
  }
}

int main() {
  long long n;
  scanf("%lld", &n);
  if (n < 100) {
    brute(n);
    return 0;
  }
  for (long long d = n - 4; d >= 1; d--) {
    if (mrtest(d)) {
      for (long long i = 2; i <= n - d; i++) {
        if (mrtest(i) && mrtest(n - d - i)) {
          printf("%lld %lld %lld\n", d, i, n - d - i);
          return 0;
        }
      }
    }
  }
  assert(0);
  return 0;
}
