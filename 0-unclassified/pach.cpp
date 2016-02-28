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

double memo[105][105];
char s[105][105];
int n, m;

inline bool equal(int a, int b) {
	return abs(a - b) < eps;
}

double dfs(int x, int y) {
	if(!equal(memo[x][y], -1))
		return memo[x][y];
	if('0' <= s[x][y] && s[x][y] <= '9')
		return memo[x][y] = s[x][y] - '0';
	if(x == n)
		return memo[x][y] = 0;
	if(s[x][y] == '*')
		return memo[x][y] = 0.5*dfs(x, y + 1) + 0.5*dfs(x, y - 1);
		
	return memo[x][y] = dfs(x + 1, y);
}

int main(void)
{
	int t, i, j;
	sf("%d", &t);
	while(t--) {
		double ans = -inf;
		FORS(i, 105) FORS(j, 105) memo[i][j] = -1;
		sf("%d %d", &n, &m);
		FOR(i, 1, n) sf("%s", &s[i][1]);
		FOR(j, 1, m) ans = max(ans, dfs(1, j));
		pf("%.16lf\n", ans);
	}
	
	return 0;
}
