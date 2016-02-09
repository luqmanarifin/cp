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
#define open freopen("quest.in","r",stdin);
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int dp[1005][1005];

int main(void)
{
	int i, j, n, m, t, tt;
	sf("%d", &t);
	FOR(tt, 1, t) {
		reset(dp, 0);
		sf("%d %d", &n, &m);
		FOR(i, 1, n) FOR(j, 1, m) sf("%d", &dp[i][j]);
		FOR(i, 1, n) FOR(j, 1, m) {
			if(i == 1)
				dp[i][j] += dp[i][j - 1];
			else if(j == 1)
				dp[i][j] += dp[i - 1][j];
			else
				dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
		}
		pf("Case %d: %d\n", tt, dp[n][m]);
	}
	return 0;
}
