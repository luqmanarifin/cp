#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
 
/** Deterministic Miller-Rabin
**/
 
#define MAX_P (1000000ull)
vector<ll> primes;
vector<ll> A({2, 3, 5, 7, 11, 13, 17, 19, 23}); // if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.
 
ll mulmod(ll a, ll b, ll n)
{
	ll erg = 0;
	ll r = 0;
	while(b > 0)
	{
		// unsigned long long gives enough room for base 10 operations
		ll x = ((a%n) * (b%10)) % n;        
		for(ll i=0;i<r;i++) x = (x*10)%n;
		erg = (erg + x) % n;
		r++;
		b /= 10;
	}
	return erg;
}
 
ll fastexp(ll a, ll b, ll n)
{
	if(b == 0) return 1;
	if(b == 1) return a%n;
	ll res = 1;
	while(b > 0)
	{
		if(b % 2 == 1) res = mulmod(a, res, n);
		a = mulmod(a, a, n);
		b /= 2;
	}
	return res;
}
 
bool mrtest(ll n)
{
	if(n == 1 || n % 2 == 0) return false;
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
		for(ll r=0;r<=max(0ull,s-1);r++)
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
 
const int N = 1e5 + 5;
const int pol = 1e9 + 5;

bool is[N];
vector<int> prime;

int main()
{  	
  for(int i = 2; i * i < pol; i++) {
    if(!is[i]) {
      for(long long j = 1LL * i * i; j < N; j += i) {
        is[j] = 1;
      }
      prime.push_back(i);
    }
  }
  
  int n;
  scanf("%d", &n);
  if(mrtest(n)) {
    printf("1\n%d\n", n);
    return 0;
  }
  //puts("TAI");
  for(int i = 0; i < prime.size(); i++) {
    //printf("%d\n", prime[i]);
    if(mrtest(n - prime[i]) && n - prime[i] >= 2) {
      printf("2\n%d %d\n", prime[i], n - prime[i]);
      return 0;
    }
  }
  //puts("ANJING");
  n -= 3;
  for(int i = 3; i <= n; i += 2) {
    if(mrtest(i) && mrtest(n - i)) {
      printf("3\n%d %d %d\n", 3, i, n - i);
      return 0;
    }
  }
  assert(false);
  return 0;
}