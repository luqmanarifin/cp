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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL dp[13][100];

int main(void)
{
	int i, j, k, t;
	dp[1][0] = 1;
	FOR(i, 2, 12)
		FOR(j, 0, 99)
			FOR(k, max(0, j - i + 1), j) {
				dp[i][j] += dp[i-1][k];
			}
	sf("%d", &t);
	while(t--) {
		int n;
		sf("%d %d", &n, &k);
		pf("%I64d\n", dp[n][k]);
	}
	
	return 0;
}
