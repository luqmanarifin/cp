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

int s[30][30], pet[30][30], n, m;
bool vis[30][30];

int dfs(int x, int y) {
	if(x < 1 || n < x || y < 1 || m < y) return 0;
	if(vis[x][y]) return 0;
	vis[x][y] = 1;
	int ret = 1;
	ret += (s[x][y + 1] == s[x][y]? dfs(x, y + 1) : 0);
	ret += (s[x][y - 1] == s[x][y]? dfs(x, y - 1) : 0);
	ret += (s[x + 1][y] == s[x][y]? dfs(x + 1, y) : 0);
	ret += (s[x - 1][y] == s[x][y]? dfs(x - 1, y) : 0);
	return ret;
}

void rusak(int x, int y) {
	if(x < 1 || n < x || y < 1 || m < y) return;
	if(vis[x][y]) return;
	vis[x][y] = 1;
	pet[x][y] = -99;
	if(s[x][y + 1] == s[x][y]) rusak(x, y + 1);
	if(s[x][y - 1] == s[x][y]) rusak(x, y - 1);
	if(s[x + 1][y] == s[x][y]) rusak(x + 1, y);
	if(s[x - 1][y] == s[x][y]) rusak(x - 1, y);
}	

int main(void)
{
	int i, j;
	sf("%d %d", &n, &m);
	FOR(i, 1, n) FOR(j, 1, m) {
		sf("%d", &s[i][j]);
		pet[i][j] = s[i][j];
	}
	int x, y;
	int ans = 0;
	FOR(i, 1, n) FOR(j, 1, m) {
		int cur = dfs(i, j);
		if(cur > ans) {
			ans = cur;
			x = i; y = j;
		}
	}
	reset(vis, 0);
	rusak(x, y);
	FORD(i, n, 1) FOR(j, 1, m) {
		if(pet[i][j] == -99) {
			int ii = i;
			while(ii) {
				if(pet[ii][j] != -99) break;
				ii--;
			}
			if(ii) swap(pet[ii][j], pet[i][j]);
		}
	}
	
	FOR(i, 1, n) {
		pf("%c", (pet[i][1] == -99? '.' : pet[i][1] + '0'));
		FOR(j, 2, m) pf(" %c", (pet[i][j] == -99? '.' : pet[i][j] + '0'));
		nl;
	}
	return 0;
}
