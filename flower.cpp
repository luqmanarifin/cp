#include <bits/stdc++.h>

/**
 * Codeforces Round #258 (Div. 2)
 * Problem : E
 * Luqman Arifin (kadalbonek)
 */

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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int n;
LL f[25], ifact[25];

LL power(LL a, LL b) {
	if(!b) return 1LL;
	LL temp = power(a, b/2);
	temp *= temp;
	temp %= mod;
	if(b & 1) {
		temp *= a;
		temp %= mod;
	}
	return temp;
}

LL inv(LL a) {
	return power(a, mod - 2);
}

LL c(LL n, LL k) {
	if(n < 0 || k < 0 || n < k) return 0LL;
	LL temp = 1, i;
	LL sm = min(k, n - k);
	n %= mod;
	FORS(i, sm) {
		temp *= n - i;
		temp %= mod;
	}
	temp *= ifact[sm];
	temp %= mod;
	return temp;
}

int main(void)
{
	int tm;
	LL s, fact = 1, i;
	ifact[0] = 1;
	FOR(i, 1, 23) {
		fact *= i;
		fact %= mod;
		ifact[i] = inv(fact);
	}
	sf("%d %I64d", &n, &s);
	FORS(i, n) sf("%I64d", f + i);
	LL ans = 0;
	FORS(tm, (1 << n)) {
		LL sisa = s;
		FORS(i, n)
			if(tm & (1 << i))
				sisa -= f[i] + 1;
				
		LL tmp = c(sisa + n - 1, sisa);
		if(__builtin_popcount(tm) & 1)
			ans -= tmp;
		else ans += tmp;
		
		if(ans >= mod) ans -= mod;
		else if(ans < 0) ans += mod;
	}
	cout << ans << endl;
	return 0;
}
