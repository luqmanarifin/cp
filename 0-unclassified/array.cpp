#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const LL inf = -4e18;
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int a[N];
LL dp[N];

int main(void)
{
	int i, n; sf("%d", &n);
	FOR(i,1,n) {
		sf("%d", &a[i]);
		if(i&1) a[i] *= -1LL;
	}
	
	reset(dp, 0);
	LL ans = 0;
	FOR(i,1,n) {
		dp[i] = max(dp[i-1] + a[i], 0LL);
		ans = max(ans, dp[i]);
	}
	
	reset(dp, 0);
	LL cur = 0;
	FOR(i,1,n) {
		a[i] *= -1LL;
		dp[i] = max(dp[i-1] + a[i], 0LL);
		cur = max(cur, dp[i]);
	}
	
	cout << max(ans, cur) << endl;
	return 0;
}
