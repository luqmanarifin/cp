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
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int dp[3005][2], a[3005], b[3005], c[3005];

int solve(int i, bool prev) {
	if(dp[i][prev] >= 0) return dp[i][prev];
	int cur, cuh;
	if(prev) {
		cur = solve(i+1, 1) + b[i];
		cuh = solve(i+1, 0) + c[i];
	} else {
		cur = solve(i+1, 1) + a[i];
		cuh = solve(i+1, 0) + b[i];
	}
	return dp[i][prev] = max(cur, cuh);
}

int main(void)
{
	int i, n;
	sf("%d", &n);
	reset(dp, -1);
	FORS(i, n) sf("%d", a + i);
	FORS(i, n) sf("%d", b + i);
	FORS(i, n) sf("%d", c + i);
	dp[n-1][0] = a[n-1];
	dp[n-1][1] = b[n-1];
	cout << solve(0,0) << endl;
	return 0;
}
