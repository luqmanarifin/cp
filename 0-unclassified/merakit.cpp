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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 9;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL fact[N], ifact[N];

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
	if(n < k || n < 0 || k < 0) return 0;
	LL temp = fact[n]*ifact[k];
	temp %= mod;
	temp *= ifact[n-k];
	temp %= mod;
	return temp;
}

LL cat(LL n) {
	LL temp = fact[2*n]*ifact[n];
	temp %= mod;
	temp *= ifact[n+1];
	temp %= mod;
	return temp;
}

int main(void)
{
	int n, k, i, j;
	fact[0] = ifact[0] = 1;
	FOR(i, 1, N-1) {
		fact[i] = fact[i-1]*i;
		fact[i] %= mod;
		ifact[i] = inv(fact[i]);
	}
	sf("%d %d", &n, &k);
	LL ans = cat(k)*c(n, 2*k);
	ans %= mod;
	ans *= fact[k];
	ans %= mod;
	cout << ans << endl;
	return 0;
}
