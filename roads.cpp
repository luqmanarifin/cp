#include <bits/stdc++.h>
#include <iomanip>

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
#define reset(cok,n) memset(cok, (n), sizeof(cok))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair
#define R first
#define C second

const LL mod = 1e9 + 7;
const LL inf = 4e18;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL dp[305][305], seg[305][305];

/*
	dp[a][b] artinya
	a : pojok kanan
	b : banyak lubang yg dicover
*/

int main(void)
{
	int n, m, k, i, j, a;
	sf("%d %d %d", &n, &m, &k);
	FORS(i,305)
		FORS(j,305) {
			dp[i][j] = inf;
			seg[i][j] = inf;
		}
	
	while(m--) {
		int l, r, c;
		sf("%d %d %d", &l, &r, &c);
		FOR(i, l, r)
			seg[l][i] = min(seg[l][i], 1LL*c);
	}
	
	dp[0][0] = 0;
	FOR(i, 1, n)
		FOR(j, 0, i) {
			dp[i][j] = min(dp[i][j], dp[i-1][j]);
			FOR(a, 1, j)
				dp[i][j] = min(dp[i][j], dp[i-a][j-a] + seg[i-a+1][i]);
		}
	
	LL ans = inf;
	FOR(i,k,n) if(dp[n][i] < ans) ans = dp[n][i];
	if(ans == inf) ans = -1;
	cout << ans << endl;
	
	return 0;
}
