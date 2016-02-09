#include <bits/stdc++.h>

/** 
 * Codeforces Round #271 (Div. 2)
 * Problem : D
 * بسم الله الرحمان الرحيم
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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL dp[N];

int main(void)
{
	int t, k, i;
	sf("%d %d", &t, &k);
	dp[0] = 1;
	FOR(i, 1, N-1) {
		dp[i] = dp[i-1];
		if(i - k >= 0) dp[i] += dp[i-k];
		if(dp[i] >= mod) dp[i] -= mod;
	}
	FOR(i, 1, N-1) {
		dp[i] += dp[i-1];
		if(dp[i] >= mod) dp[i] -= mod;
	}
	while(t--) {
		int a, b;
		sf("%d %d", &a, &b);
		LL ans = dp[b] - dp[a - 1];
		if(ans < 0) ans += mod;
		pf("%I64d\n", ans);
	}
	
	return 0;
}
