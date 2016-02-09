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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL n, k, d;

LL power(LL a, LL b) {
	if(b == 0) return 1;
	LL temp = power(a, b/2);
	temp *= temp;
	if(temp > inf) return inf;
	if(b & 1) {
		temp *= a;
		if(temp > inf) return inf;
	}
	return temp;
}

int main(void)
{
	LL i, j;
	sf("%I64d %I64d %I64d", &n, &k, &d);
	if(power(k, d) < n) {
		puts("-1");
		return 0;
	}
	LL now = 1;
	FORS(i, d) {
		FORS(j, n)
			pf("%I64d ", j/now % k + 1);
		nl;
		now *= k;
		if(now > n) now = n;
	}
	return 0;
}
