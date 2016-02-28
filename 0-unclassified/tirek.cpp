#include <bits/stdc++.h>

/**
 * Codeforces Round #259 (Div. 1)
 * Problem : E
 * Luqman Arifin (kadalbonek)
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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int s[N], m[N], r[N], last[N];

int main(void)
{
	int n, i, j, q;
	sf("%d", &n);
	FOR(i, 1, n) sf("%d %d %d", s + i, m + i, r + i);
	sf("%d", &q);
	int prev = 0;
	while(q--) {
		int t, lef, rig;
		sf("%d %d %d", &t, &lef, &rig);
		LL ans = 0;
		FOR(i, lef, rig) {
			ans += min(1LL*m[i], s[i] + 1LL*(t-last[i])*r[i]);
			s[i] = 0;
			last[i] = t;
		}
		prev = t;
		pf("%I64d\n", ans);
	}
	return 0;
}
