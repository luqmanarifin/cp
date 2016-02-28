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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[15];
int a[8000];
LL dp[10][55];

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int m, n, q, i, j, k;
		reset(a, 0);
		reset(dp, 0);
		sf("%d %d %d", &m, &n, &q);
		FOR(i, 1, m) {
			sf("%s", s);
			a[i] = strlen(s);
		}
		
		dp[0][0] = 1;
		FOR(i, 1, n) FOR(k, 1, m) {
			FOR(j, a[k], 50) {
				dp[i][j] += dp[i - 1][j - a[k]];
			}
		}
		
		while(q--) {
			int l;
			sf("%d", &l);
			pf("%I64d\n", dp[n][l]);
		}
	}
	
	return 0;
}
