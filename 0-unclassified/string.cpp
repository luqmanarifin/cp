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
int lcm(int a, int b) { return a*b / gcd(a, b); }

int main(void)
{
	int n, k, i;
	sf("%d %d", &n, &k);
	if(n < k || (k == 1 && n > 1)) {
		puts("-1");
		return 0;
	}
	if(n == 1 && k == 1) {
		puts("a");
		return 0;
	}
	FORS(i, n-k+2)
		if(i & 1) pf("b");
		else pf("a");
	FORS(i, k-2)
		pf("%c", i + 'c');
	nl;
	return 0;
}
