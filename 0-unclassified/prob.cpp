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

double dp[105][105], a[105], aks[105][105];

int main(void)
{
	ios_base::sync_with_stdio(false);
	int n, i, j;
	FORS(i, 105) FORS(j, 105) dp[i][j] = 0.0;
	FORS(i, 105) FORS(j, 105) aks[i][j] = 1.0;
	sf("%d", &n);
	FOR(i, 1, n)
		sf("%lf", &a[i]);
		
	FOR(i, 1, n)
		FOR(j, 1, i) {
			double cur = dp[i-1][j-1]*(1 - a[i]) + aks[i-1][j-1]*a[i];
			if(cur > dp[i-1][j]) {
				dp[i][j] = cur;
				aks[i][j] = aks[i-1][j-1]*(1 - a[i]);
			} else {
				dp[i][j] = dp[i-1][j];
				aks[i][j] = aks[i-1][j];
			}
		}
			
	double ans = 0;
	FOR(i, 0, n)
		ans = max(ans, dp[n][i]);
	pf("%.12f\n", ans);
	return 0;
}
