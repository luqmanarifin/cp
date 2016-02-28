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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL high[N];

int main(void)
{
	LL n, i, m;
	sf("%I64d", &n);
	FOR(i, 1, n) sf("%I64d", &high[i]);
	sf("%I64d", &m);
	LL maks = 0;
	while(m--) {
		LL w, h;
		sf("%I64d %I64d", &w, &h);
		LL now = max(maks, high[w]);
		pf("%I64d\n", now);
		maks = now + h;
	}
	
	return 0;
}
