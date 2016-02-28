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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[100][100], junk[100];
bool ans[100][100];
int n, m;

void dfs(int x, int y) {
	if(x < 0 || n+1 < x || y < 0 || m+1 < y) return;
	if(ans[x][y] || s[x][y] == '#') return;
	ans[x][y] = 1;
	dfs(x, y + 1);
	dfs(x, y - 1);
	dfs(x + 1, y);
	dfs(x - 1, y);
}

int main(void)
{
	int t, i, j;
	sf("%d", &t);
	while(t--) {
		sf("%d %d", &n, &m);
		reset(ans, 0);
		reset(s, ' ');
		gets(junk);
		FOR(i, 1, n) gets(&s[i][1]);
		bool ada = 0;
		FOR(i, 0, n + 1) {
			dfs(i, 0);
			dfs(i, m + 1);
		}
		FOR(j, 0, m + 1) {
			dfs(0, j);
			dfs(n + 1, j);
		}
		//FOR(i, 1, n) { FOR(j, 1, m) pf("%d", ans[i][j]); nl; }
		FOR(i, 1, n) FOR(j, 1, m)
			if(!ans[i][j] && s[i][j] != '#')
				ada = 1;
		if(ada) puts("YA");
		else puts("TIDAK");
		//nl;
	}
	return 0;
}
