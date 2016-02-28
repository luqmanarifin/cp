#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5;
const int N5 = N + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL fact[2*N5], ifact[2*N5];

LL power(LL a, LL b) {
	if(!b) return 1LL;
	LL temp = power(a, b >> 1);
	temp *= temp;
	temp %= mod;
	if(b&1) {
		temp *= a;
		temp %= mod;
	}
	return temp;
}

LL inv(LL a) {
	return power(a, mod - 2);
}

LL c(int n, int k) {
	LL temp = fact[n];
	temp *= ifact[k];
	temp %= mod;
	temp *= ifact[n-k];
	temp %= mod;
	return temp;
}

int main(void)
{
	int i, n;
	fact[0] = 1;
	ifact[0] = 1;
	FOR(i, 1, 2*N) {
		fact[i] = fact[i-1]*i;
		fact[i] %= mod;
		ifact[i] = inv(fact[i]);
	}
	
	sf("%d", &n);
	LL ans = c(2*n-1, n-1);
	ans = (2*ans - n) % mod;
	if(ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}
