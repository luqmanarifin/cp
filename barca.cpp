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

LL dp[1005][15];

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		reset(dp, 0);
		int n, k, i, j, l;
		sf("%d %d", &n, &k);
		dp[0][0] = 1;
		FOR(i, 1, n)
			FOR(j, 0, k)
				FOR(l, 0, k) {
					if(j == l) continue;
					dp[i][j] += dp[i-1][l];
					if(dp[i][j] >= mod)
						dp[i][j] -= mod;
				}
		cout << dp[n][0] << endl;
	}
	
	return 0;
}
