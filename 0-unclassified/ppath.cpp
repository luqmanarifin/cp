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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

pair<int, pair<int,int> > edge[500*500];
int in[505][505];
LL dist[505][505];
#define x first
#define y second

void FloydWarshall(int n, int m) {
	int i, j, a, b, c;
	FOR(i, 1, n) FOR(j, 1, n) dist[i][j] = INF;
	FOR(i, 1, n) dist[i][i] = 0;
	FORS(i, m) {
		dist[edge[i].y.x][edge[i].y.y] = edge[i].x;
		dist[edge[i].y.y][edge[i].y.x] = edge[i].x;
	}
	FOR(b, 1, n) FOR(a, 1, n) FOR(c, 1, n) {
		if(dist[a][b] != INF && dist[b][c] != INF) {
			if(dist[a][c] > dist[a][b] + dist[b][c])
				dist[a][c] = dist[a][b] + dist[b][c],
				dist[c][a] = dist[a][c];
		}
	}
}

int main(void)
{
	int n, m, i, a, b, c, source;
	sf("%d %d", &n, &m);
	FORS(i, m) {
		sf("%d %d %d", &a, &b, &c);
		edge[i] = mp(c, mp(a, b));
	}
	FloydWarshall(n, m);
	FOR(source, 1, n) FORS(i, m) {
		if(dist[source][edge[i].y.y] + edge[i].x == dist[source][edge[i].y.x])
			in[source][edge[i].y.x]++;
		if(dist[source][edge[i].y.x] + edge[i].x == dist[source][edge[i].y.y])
			in[source][edge[i].y.y]++;
	}
	FOR(a, 1, n) FOR(c, a + 1, n) {
		int ans = 0;
		FOR(b, 1, n) if(dist[a][b] + dist[b][c] == dist[a][c]) ans += in[a][b];
		pf("%d ", ans);
	}
	nl; return 0;
}
