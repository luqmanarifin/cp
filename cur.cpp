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
const int N = 1e5 + 105;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL fact[N], ifact[N], ans[N], dp[N][105];

#define upd(x) if(x >= mod) x -= mod; else if(x < 0) x += mod

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
	if(k > n) return 0LL;
	LL temp = fact[n]*ifact[k];
	temp %= mod;
	temp *= ifact[n-k];
	temp %= mod;
	return temp;
}

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	fact[0] = 1, ifact[0] = 1;
	FOR(i, 1, n + 100) {
		fact[i] = fact[i-1]*i;
		fact[i] %= mod;
		ifact[i] = inv(fact[i]);
	}
	FORS(i, n) sf("%I64d", &ans[i]);
	while(m--) {
		int l, r, k;
		sf("%d %d %d", &l, &r, &k);
		int len = r - l;
		--l;
		dp[l][k]++;
		FOR(i, 0, k) {
			dp[r][k-i] -= c(len + i, i);
			upd(dp[r][k-i]);
		}
	}
	
	FORS(i, n) FORD(j, 100, 0) {
		dp[i][j] += dp[i][j+1] + dp[i-1][j];
		dp[i][j] %= mod;
	}
	FORS(i, n) {
		ans[i] += dp[i][0];
		upd(ans[i]);
	}
	FORS(i, n) pf("%d ", (int) ans[i]); nl;
	return 0;
}
