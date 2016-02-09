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

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1005;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int up[N][N], down[N][N], lef[N][N], rig[N][N];
int a[N][N];

void update(int x, int y) {
	int i, j;
	a[x][y] ^= 1;
	if(a[x][y]) {
		down[x][y] = down[x+1][y] + a[x][y];
		up[x][y] = up[x-1][y] + a[x][y];
		lef[x][y] = lef[x][y-1] + a[x][y];
		rig[x][y] = rig[x][y+1] + a[x][y];
	} else {
		down[x][y] = 0;
		up[x][y] = 0;
		lef[x][y] = 0;
		rig[x][y] = 0;
	}
	i = x + 1;
	while(a[i][y]) {
		up[i][y] = up[i-1][y] + a[i][y];
		i++;
	}
	i = x - 1;
	while(a[i][y]) {
		down[i][y] = down[i+1][y] + a[i][y];
		--i;
	}
	j = y - 1;
	while(a[x][j]) {
		rig[x][j] = rig[x][j+1] + a[x][j];
		j--;
	}
	j = y + 1;
	while(a[x][j]) {	
		lef[x][j] = lef[x][j-1] + a[x][j];
		j++;
	}
}

int main(void)
{
	int n, i, j, m, q;
	sf("%d %d %d", &n, &m, &q);
	FOR(i,1,n) FOR(j,1,m) sf("%d", &a[i][j]);
	FOR(j,1,m) FOR(i,1,n)
		if(a[i][j]) up[i][j] = up[i-1][j] + a[i][j];
	FOR(j,1,m) FORD(i,n,1)
		if(a[i][j]) down[i][j] = down[i+1][j] + a[i][j];
	FOR(i,1,n) FOR(j,1,m)
		if(a[i][j]) lef[i][j] = lef[i][j-1] + a[i][j];
	FOR(i,1,n) FORD(j,m,1)
		if(a[i][j]) rig[i][j] = rig[i][j+1] + a[i][j];
		
	while(q--) {
		int type, x, y;
		sf("%d %d %d", &type, &x, &y);
		if(type == 2) {
			int ans = 0, l, r;
			int lim = up[x][y]; l = y, r = y;
			while(lim) {
				while(l && up[x][l] >= lim) l--;
				while(r <= m && up[x][r] >= lim) r++;
				ans = max(ans, lim*(r - l - 1));
				lim--;
			}
			lim = down[x][y]; l = y, r = y;
			while(lim) {
				while(l && down[x][l] >= lim) l--;
				while(r <= m && down[x][r] >= lim) r++;
				ans = max(ans, lim*(r - l - 1));
				lim--;
			}
			lim = rig[x][y]; l = x, r = x;
			while(lim) {
				while(l && rig[l][y] >= lim) l--;
				while(r <= n && rig[r][y] >= lim) r++;
				ans = max(ans, lim*(r - l - 1));
				lim--;
			}
			lim = lef[x][y]; l = x, r = x;
			while(lim) {
				while(l && lef[l][y] >= lim) l--;
				while(r <= n && lef[r][y] >= lim) r++;
				ans = max(ans, lim*(r - l - 1));
				lim--;
			}
			pf("%d\n", ans);
		} else 
			update(x, y);
	}
	return 0;
}
