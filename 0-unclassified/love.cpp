#include <bits/stdc++.h>

/* Codeforces Round #FF (Div. 2)
 * Problem : B
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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[1005];
int c[1005];
int val[30];

int main(void)
{
	sf("%s", s);
	int n = strlen(s), i, j, k, maks = 0;
	sf("%d", &k);
	FORS(i, 26) {
		sf("%d", &val[i]);
		maks = max(maks, val[i]);
	}
	FORS(i, n) {
		c[i] = val[s[i] - 'a'];
	}
	LL ans = 0;
	FORS(i, n) {
		ans += 1LL*c[i]*(i + 1);
	}
	FOR(i, n + 1, n + k)
		ans += 1LL*maks*i;
	cout << ans << endl;
	return 0;
}
