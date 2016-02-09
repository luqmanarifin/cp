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

bool vis[1005][1005], ku;
char s[1005][1005];
int n, m;

int dfs(int x, int y) {
	int ret = 0;
	stack<pair<int,int> > st;
	st.push(mp(x, y));
	while(!st.empty()) {
		x = st.top().first;
		y = st.top().second;
		st.pop();
		if(x < 1 || n < x || y < 1 || m < y) continue;
		if(vis[x][y] || s[x][y] == '#') continue;
		vis[x][y] = 1;
		ret++;
		st.push(mp(x + 1, y));
		st.push(mp(x - 1, y));
		st.push(mp(x, y + 1));
		st.push(mp(x, y - 1));
	}
	return ret;
}

int main(void)
{
	sf("%d %d", &n, &m);
	swap(n, m);
	int i, j, bx, by, kx, ky;
	FOR(i, 1, n) sf("%s", &s[i][1]);
	FOR(i, 1, n) FOR(j, 1, m) {
		if(s[i][j] == 'K') kx = i, ky = j;
		if(s[i][j] == 'B') bx = i, by = j;
	}
	reset(vis, 0);
	int beb = dfs(bx, by);
	
	reset(vis, 0);
	int kuc = dfs(kx, ky);
	
	if(beb > kuc) pf("B %d\n", abs(beb - kuc));
	else if(beb < kuc) pf("K %d\n", abs(beb - kuc));
	else puts("SERI");
	//pf("%d %d\n", beb, kuc);
	return 0;
}
