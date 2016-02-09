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

int lima, nol;

int main(void)
{
	int n, i, j; sf("%d", &n);
	while(n--) {
		int a; sf("%d", &a);
		if(a) lima++;
		else nol++;
	}
	int jadi = lima / 9;
	if(!nol) {
		puts("-1");
		return 0;
	}
	FORS(i, jadi) FORS(j, 9) pf("5");
	if(!jadi) nol = 1;
	FORS(i, nol) pf("0"); nl;
	return 0;
}
