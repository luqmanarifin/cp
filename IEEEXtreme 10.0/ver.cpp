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

const int N = 10005;

bool is[N];
vector<int> p;

bool ada[3 * N];
int a[3 * N], b[3 * N], c[3 * N];

int main() {
  for (int i = 2; i < N; i++) {
    if (!is[i]) {
      p.push_back(i);
      for (int j = i * i; j < N; j += i) {
        is[j] = 1;
      }
    }
  }
  
  long long n;
  scanf("%lld", &n);
  for (int i = 0; i < p.size(); i++) {
    for (int j = i; j < p.size(); j++) {
      long long k = n - p[i] - p[j];
      if (k <= 1) break;
      if (mrtest(k)) {
        printf("%lld %lld %lld\n", A[i], A[j], k);
        return 0;
      }
    }
  }
  return 0;
}
