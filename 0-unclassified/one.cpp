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
const int inf = 1e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int dist[105][105];

int main(void)
{
	int tt, t, i, j, k;
	sf("%d", &t);
	FOR(tt, 1, t) {
		FORS(i, 105) FORS(j, 105) dist[i][j] = inf;
		int n, m;
		sf("%d %d", &n, &m);
		while(m--) {
			int a, b;
			sf("%d %d", &a, &b);
			dist[a][b] = min(dist[a][b], 0);
			dist[b][a] = min(dist[b][a], 1);
		}
		FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) {
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
		int q;
		sf("%d", &q);
		pf("Case #%d:\n", tt);
		while(q--) {
			int a, b;
			sf("%d %d", &a, &b);
			pf("%d\n", (dist[a][b] == inf? -1 : dist[a][b]));
		}
	}
	
	return 0;
}
