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

const LL mod = 1e6;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int dp[1005];

int main(void)
{
	dp[0] = 1;
	int n, i;
	sf("%d", &n);
	FOR(i, 1, n) {
		dp[i] += dp[i-1];
		if(i >= 3) dp[i] += dp[i-3];
		if(dp[i] >= mod)
			dp[i] %= mod;
	}
	cout << dp[n] << endl;
	return 0;
}
