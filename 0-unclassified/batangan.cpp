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
#define open freopen("batang.txt","r",stdin)
#define close fclose(stdin)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int dp[1005][1005];

inline bool magic(int a, int b, int c, int d) {
	int cur = dp[c][d] - dp[c][b-1] - dp[a-1][d] + dp[a-1][b-1];
	return (cur & 1)^1;
}

int main(void)
{
	//open;
	int t;
	sf("%d", &t);
	while(t--) {
		int n, m, i, j, ii, jj, x;
		sf("%d %d", &n, &m);
		reset(dp, 0);
		FOR(i, 1, n) FOR(j, 1, m) {
			sf("%d", &x);
			dp[i][j] = (x & 1);
		}
		FOR(i, 1, n) FOR(j, 1, m) {
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
		int ans = 0;
		FOR(i, 1, n) FOR(j, 1, m)
			FOR(ii, i, n) FOR(jj, j, m) {
				if(magic(i, j, ii, jj)) ans++;
			}
		pf("%d\n", ans);
	}
	//close;
	return 0;
}
