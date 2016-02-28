#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 105;

int par[N][N];

int find(int c, int u) {
	if(par[c][u] != u) par[c][u] = find(c, par[c][u]);
	return par[c][u];
}

void merge(int c, int u, int v) {
	u = find(c, u);
	v = find(c, v);
	par[c][u] = v;
}

int main(void)
{
	int n, m, i, j;
	FORS(i, N) FORS(j, N) par[i][j] = j;
	sf("%d %d", &n, &m);
	FORS(i, m) {
		int a, b, c;
		sf("%d %d %d", &a, &b, &c);
		merge(c, a, b);
	}
	int q;
	sf("%d", &q);
	while(q--) {
		int a, b;
		sf("%d %d", &a, &b);
		int ans = 0;
		FOR(i, 1, m) ans += find(i, a) == find(i, b);
		pf("%d\n", ans);
	}
	
	return 0;
}
