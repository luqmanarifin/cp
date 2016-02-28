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

LL gcd(LL a, LL b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int main(void)
{
	LL l, r, i, j, k;
	sf("%I64d %I64d", &l, &r);
	FOR(i, l, r)
		FOR(j, i+1, r)
			FOR(k, j+1, r) {
				if(gcd(i, j) == 1 && gcd(j, k) == 1 && gcd(i, k) != 1) {
					pf("%I64d %I64d %I64d\n", i, j, k);
					return 0;
				}
			}
	puts("-1");
	return 0;
}
