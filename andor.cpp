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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int main(void)
{
	int t, tt;
	sf("%d", &t);
	FOR(tt, 1, t) {
		LL a, b, i;
		sf("%lld %lld", &a, &b);
		LL n = 0, r = 0;
		FORS(i, 63) {
			LL now = (1LL << i);
			if(a/now == b/now && (a/now) % 2) n |= now;
			if(!(a/now == b/now && (a/now) % 2 == 0) ) r |= now;
		}
		pf("Case %d: %lld %lld\n", tt, r, n);
	}
	
	return 0;
}
