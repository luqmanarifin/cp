#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <cstdio>
#include <set>
#include <bitset>
using namespace std;
#define db(a) (cout << (#a) << " = " << (a) << endl)
typedef unsigned long long ll;
 
/** Deterministic Miller-Rabin
**/
 
#define MAX_P (1000000ull)
vector<ll> primes;
vector<ll> A({2, 3, 5, 7, 11, 13, 17, 19, 23}); // if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.
ll N;
 
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
 
bool sieve[MAX_P+1];
 
void preprimes(ll l)
{
  ll limit = min(MAX_P, l);
  for(ll i=0;i<=limit;i++) sieve[i] = false;
  for(ll p=2;p<=limit;p++)
  {
    if(sieve[p]) continue;
    sieve[p] = true;
    primes.push_back(p);
    ll i = 2*p;
    while(i <= limit)
    {
      sieve[i] = true;
      i += p;
    }
  }
}
 
// how accurate is this? can we generate cases were this fails?
bool sqtest(ll n)
{
  ll ns = (ll) sqrt((long double)n);
  if(ns*ns==n) return true;
  ns++;
  if(ns*ns==n) return true;
  return false;
}
 
int main()
{  	
  cin>>N;
  ll erg = 1;
  preprimes(N);
  ll restN = N;
  for(ll i=0;i<(ll)primes.size();i++)
  {	
    if(N % primes[i] == 0) 
    {			
      ll tN = N;
      ll p = 0;	
      while(tN % primes[i] == 0) {tN /= primes[i]; restN /= primes[i]; p++;}
      // p occurences of primes[i]
      erg *= p+1;				
    }
  }
 
  if(restN> 1 && sqtest(restN)) erg *= 3;
  else if(restN > 1 && !mrtest(restN)) erg *= 4;
  else if(restN > 1) erg *= 2;

  cout << erg << "\n";
  return 0;
}