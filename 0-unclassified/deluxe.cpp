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
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int coin[35];
LL dp[(int) 1e6 + 5];
// harusnya semiyar tapi jelas memori kurang
// lagipula pasti TLE -__-

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int n, x, i, j;
		sf("%d %d", &n, &x);
		FORS(i, n) sf("%d", coin + i);
		reset(dp, 0);
		dp[0] = 1;
		FOR(i, 1, x)
			FORS(j, n) {
				if(i < coin[j]) continue;
				dp[i] += dp[i-coin[j]];
				if(dp[i] >= mod) dp[i] -= mod;
			}
		pf("%d\n", (int) dp[x]);
	}
	return 0;
}
