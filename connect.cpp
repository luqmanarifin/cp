#include <bits/stdc++.h>

/** 
 * Bayan 2015 Contest Warm Up
 * Problem : B
 * بسم الله الرحمان الرحيم
 */

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

int n, m;
char row[25], col[25];
bool vis[25][25];

void dfs(int x, int y) {
	if(x < 1 || n < x || y < 1 || m < y || vis[x][y])
		return;
	vis[x][y] = 1;
	if(row[x] == '>') dfs(x, y + 1);
	else dfs(x, y - 1);
	
	if(col[y] == '^') dfs(x - 1, y);
	else dfs(x + 1, y);
}

int main(void)
{
	int i, j;
	sf("%d %d", &n, &m);
	sf("%s", &row[1]);
	sf("%s", &col[1]);
	FOR(i, 1, n) FOR(j, 1, m) {
		reset(vis, 0);
		dfs(i, j);
		int ii, jj;
		FOR(ii, 1, n) FOR(jj, 1, m) {
			if(!vis[ii][jj]) {
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	return 0;
}
