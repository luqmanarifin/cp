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
#define open freopen("lompat.txt","r",stdin); freopen("out.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[1005][1005];
int sx, sy, fx, fy, ans[1005][1005], n, m, res = inf;

void dfs(int x, int y, int at) {
	//pf("%d %d %d\n", x, y, at);
	if(x < 1 || x > n || y < 1 || y > m || at >= ans[x][y]) return;
	ans[x][y] = min(ans[x][y], at);
	if(s[x][y] == 'T') {
		res = min(res, ans[x][y]);
		return;
	}
	if(s[x][y+1] == '#') dfs(x, y + 1, at);
	if(s[x][y-1] == '#') dfs(x, y - 1, at);
	if(s[x+1][y] == '#') dfs(x + 1, y, at);
	if(s[x-1][y] == '#') dfs(x - 1, y, at);
	
	int xx = x + 1, yy = y;
	while(xx <= n && s[xx][yy] == '.') xx++;
	if(xx <= n && s[xx][yy] != '.') dfs(xx, yy, ans[x][y] + 1);
	
	xx = x - 1, yy = y;
	while(xx >= 1 && s[xx][yy] == '.') xx--;
	if(xx >= 1 && s[xx][yy] != '.') dfs(xx, yy, ans[x][y] + 1);
	
	xx = x, yy = y + 1;
	while(yy <= m && s[xx][yy] == '.') yy++;
	if(yy <= m && s[xx][yy] != '.') dfs(xx, yy, ans[x][y] + 1);
	
	xx = x, yy = y - 1;
	while(yy >= 1 && s[xx][yy] == '.') yy--;
	if(yy >= 1 && s[xx][yy] != '.') dfs(xx, yy, ans[x][y] + 1);
}

int main(void)
{
	//open;
	int i, j;
	char junk[20];
	sf("%s", junk);
	sf("%d %d", &n, &m);
	FOR(i, 1, n) sf("%s", &s[i][1]);
	FORS(i, 1005) FORS(j, 1005) ans[i][j] = inf;
	FOR(i, 1, n) {
		FOR(j, 1, m) {
			//pf("%c", s[i][j]);
			if(s[i][j] == 'S') sx = i, sy = j;
			if(s[i][j] == 'T') fx = i, fy = j;
		}
		//nl;
	}
	stack<pair<int,int> > st;
	st.push(mp(fx, fy));
	while(!st.empty()) {
		int x = st.top().first;
		int y = st.top().second;
		s[x][y] = 'T';
		st.pop();
		if(s[x][y+1] == '#') st.push(mp(x, y+1));
		if(s[x][y-1] == '#') st.push(mp(x, y-1));
		if(s[x+1][y] == '#') st.push(mp(x+1, y));
		if(s[x-1][y] == '#') st.push(mp(x-1, y));
	}
	dfs(sx, sy, 0);
	pf("%d\n", (res == inf? -1 : res));
	//close;
	return 0;
}
