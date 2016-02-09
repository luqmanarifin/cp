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

LL dp[2005][505];

int main(void)
{
	int i, j, k, t;
	FOR(i, 1, 9) dp[i][1] = 1;
	FOR(j, 2, 500) {
		FOR(i, j, min(2000, 9*j)) {
			FOR(k, 1, 9) {
				if(i - k <= 0) break;
				dp[i][j] += dp[i - k][j - 1];
			}
			dp[i][j] %= mod;
		}
	}
	sf("%d", &t);
	while(t--) {
		int n, m;
		sf("%d %d", &n, &m);
		pf("%d\n", (int) dp[n][m]);
	}
	return 0;
}
