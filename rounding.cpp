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
const DB eps = 1e-4;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

DB a[4006], dp[4005][4005];

bool equal(DB b, DB c) {
	return abs(b - c) < eps;
}

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FOR(i, 1, 2*n) {
		double x, y;
		sf("%lf", &x);
		a[i] = modf(x, &y);
	}
	FORS(i, 2*n) dp[i][i+1] = inf;
	dp[0][0] = 0;
	FOR(i, 1, 2*n) {
		dp[i][0] = dp[i-1][0] - a[i];
		FOR(j, 1, i) {
			DB baru = dp[i-1][j-1] + (equal(a[i], 0)? 0 : 1 - a[i]);
			DB past = dp[i-1][j] - a[i];
			if(abs(baru) < abs(past))
				dp[i][j] = baru;
			else
				dp[i][j] = past;
		}
	}
	pf("%.3f\n", abs(dp[2*n][n]));
	return 0;
}
