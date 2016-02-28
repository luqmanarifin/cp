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
const int inf = 1e9;
const double eps = 1e-13;
const int N = 105;

int dist[N][N];

int main(void)
{
	int i, j, n, m, k;
	sf("%d %d %d", &n, &m, &k);
	FORS(i, N) FORS(j, N) dist[i][j] = inf;
	FORS(i, N) dist[i][i] = 0;
	while(m--) {
		int u, v, c;
		sf("%d %d %d", &u, &v, &c);
		dist[u][v] = min(dist[u][v], c);
		dist[v][u] = min(dist[v][u], c);
	}
	int mid, q;
	FOR(mid, 1, n) FOR(i, 1, n) FOR(j, 1, n) {
		dist[i][j] = min(dist[i][j], dist[i][mid] + dist[mid][j]);
	}
	
	sf("%d", &q);
	while(q--) {
		int u, v;
		sf("%d %d", &u, &v);
		puts(dist[u][v] <= k? "YES" : "NO");
	}
	
	return 0;
}
