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
const LL inf = 4e18;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int pos[30][1005];
LL dp[30][1005];

int main(void)
{
	int z;
	sf("%d", &z);
	while(z--) {
		int i, j, c, t, l, k;
		sf("%d %d %d", &c, &t, &l);
		FOR(i,1,c)
			FOR(j,1,t)
				sf("%d", &pos[i][j]);
		
		FOR(i,1,c)
			FOR(j,1,t)
				sf("%I64d", &dp[i][j]);
				
		FOR(i,1,t)
			dp[1][i] += pos[1][i];
			
		FOR(i,2,c)
			FOR(j,1,t) {
				LL add = inf;
				FOR(k,1,t) {
					add = min(add, abs(pos[i][j] - pos[i-1][k]) + dp[i-1][k]);
				}
				dp[i][j] += add;
			}
		
		LL ans = inf;
		FOR(i,1,t) {
			LL cur = l - pos[c][i] + dp[c][i];
			if(cur < ans) ans = cur;
		}
		pf("%I64d\n", ans); 
		FOR(i,1,c) {
			FOR(j,1,t)
				pf("%I64d ", dp[i][j]);
			nl;
		} 
	}
	
	return 0;
}
