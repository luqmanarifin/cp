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
	int t; sf("%d", &t);
	while(t--) {
		char s[(int) 1e4 + 5];
		sf("%s", s);
		int n = strlen(s), i, j;
		LL ans = 0;
		FORS(i, n/2)
			ans += 1LL*abs(s[i] - s[n-1-i]);
		pf("%lld\n", ans);
	}
	
	return 0;
}
