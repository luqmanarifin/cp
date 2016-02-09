#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL fact[N], ifact[N];
int elim[N];

LL power(LL a, LL b) {
	if(b == 0) return 1LL;
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
	if(n < k) return 0LL;
	LL temp = fact[n];
	temp *= ifact[k];
	temp %= mod;
	temp *= ifact[n-k];
	temp %= mod;
	return temp;
}

int main(void)
{
	int i, j;
	// faktorial && invers faktorial
	fact[0] = 1;
	ifact[0] = 1;
	FOR(i, 1, N-1) {
		fact[i] = fact[i-1] * i;
		fact[i] %= mod;
		ifact[i] = inv(fact[i]);
	}

	// eliminasi yang gak koprime
	elim[1] = 1;
	FOR(i, 2, N-1)
		for(j = 1; j*j <= i; j++) {
			if(i % j) continue;
			elim[i] -= elim[j];
			if(j*j != i && j > 1)
				elim[i] -= elim[i/j];
		}

	int q;
	sf("%d", &q);
	while(q--) {
		int n, f;
		sf("%d %d", &n, &f);
		vector<int> factor;
		for(i = 1; i*i <= n; i++) {
			if(n % i) continue;
			if(i < n) factor.push_back(i);
			if(i*i != n && i > 1)
				factor.push_back(n/i);
		}
		
		LL ans = c(n-1, f-1);
		FORS(i, factor.size()) {
			ans += c(factor[i]-1, f-1) * elim[n/factor[i]];
			if(ans < 0) ans += mod;
			ans %= mod;
		}
		
		pf("%I64d\n", ans);
	}
	
	return 0;
}
