#include <bits/stdc++.h>

// This is a fucking beautiful solution
// Welcome to this source code

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
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N];

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	FOR(i, 1, n) sf("%d", a + i);
	while(m--) {
		char s[5];
		int l, r, val;
		sf("%s %d %d %d", s, &l, &r, &val);
		if(s[0] == '=')
			FOR(i, l, r) a[i] = val;
		else {
			LL ans = 0;
			FOR(i, l, r) {
				LL pln = 1;
				FORS(j, val) pln = pln*(i - l + 1) % mod;
				ans += pln*a[i];
				ans %= mod;
			}
			pf("%d\n", (int) ans);
		}
	}
	return 0;
}
