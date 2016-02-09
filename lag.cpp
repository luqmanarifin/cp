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
	int tt, t;
	sf("%d", &t);
	FOR(tt, 1, t) {
		int l, d;
		sf("%d %d", &l, &d);
		LL x = max(0LL, 1LL*(l - 2)/ 2);
		LL y = 2 * (l + 1);
		LL ans;
		if(d - 1 <= x) ans = 2*l + 1 + (y * (d - 1));
		else ans = 2 * l + 1 + (y * x) + (d - x - 1);
		if(l == 1) ans = d;
		pf("Case #%d: %d\n", tt, (int) (ans % mod));
	}
	
	
	return 0;
}
