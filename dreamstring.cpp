#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

char s[2005], p[2005];
int first[2005][26];
int last[2005];
int dp[2005][2005];

int main(void)
{
	int i, j, n, m;
	FORS(i, 2005) FORS(j, 26) first[i][j] = inf;
	FORS(i, 2005) FORS(j, 2005) dp[i][j] = -inf;
	FORS(i, 2005) last[i] = inf;
	
	sf("%s %s", &s[1], &p[1]);
	n = strlen(&s[1]);
	m = strlen(&p[1]);

	FORD(i, n, 1) {
		FORS(j, 26) first[i][j] = first[i+1][j];
		first[i][s[i]-'a'] = i;
	}
	FOR(i, 1, n) {
		int now = i;
		for(j = 1; j <= m && now <= n; j++) {
			now = first[now][p[j]-'a'];
			if(j < m) now++;
		}
		if(now <= n) last[i] = now;
	}
	FOR(i, 1, n) last[i] -= i;
	dp[0][0] = 0;
	FOR(i, 1, n) {
		FOR(j, 0, n) {
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
			if(j) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
			if(i + last[i] <= n) {
				dp[i + last[i]][j + last[i] + 1 - m] = max(
				dp[i + last[i]][j + last[i] + 1 - m], dp[i - 1][j] + 1);
			}
			if(i == n) pf("%d ", max(0, dp[i][j]));
		}
	}
	nl;
	return 0;
}
