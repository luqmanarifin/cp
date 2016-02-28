#include <bits/stdc++.h>

/**
 * Codeforces Round #275 (Div. 1)
 * Problem : A
 * Luqman Siswanto
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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }


int main(void)
{
	int n, k, i, j;
	sf("%d %d", &n, &k);
	int now = 1;
	bool yea = 1;
	pf("1 ");
	for(i = k; i > 0; i--) {
		if(yea) now += i;
		else now -= i;
		pf("%d ", now);
		yea ^= 1;
	}
	FOR(i, k + 2, n) pf("%d ", i); nl;
	
	return 0;
}
