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
const int inf = 1e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int dist[205][205];
int a[40000], b[40000], w[40000];

void floyd(int n) {
	int i, j, mid;
	FOR(i, 1, n) FOR(j, 1, n) {
		if(i == j) continue;
		if(dist[i][j] == 0) dist[i][j] = inf;
	}
	FOR(mid, 1, n) FOR(i, 1, n) FOR(j, 1, n) {
		dist[i][j] = min(dist[i][j], dist[i][mid] + dist[mid][j]);
	}
}

int main(void)
{
	int i, j, k, n, m;
	sf("%d %d", &n, &m);
	FORS(i, m) {
		sf("%d %d %d", &a[i], &b[i], &w[i]);
		w[i] *= 2;
		dist[a[i]][b[i]] = w[i];
		dist[b[i]][a[i]] = w[i];
	}
	floyd(n);
	int ans = inf;
	/*
	FORS(i, m) {
		int longa = -1, longb = -1, rata = -1;
		FOR(j, 1, n) {
			if(dist[j][a[i]] < dist[j][b[i]])
				longa = max(longa, dist[j][a[i]]);
			else if(dist[j][a[i]] > dist[j][b[i]])
				longb = max(longb, dist[j][b[i]]);
			else
				rata = max(rata, dist[j][a[i]]);
		}
		int cur = (longa + longb + w[i])/2;
		if(longa <= cur && longb <= cur) {
			if(rata != -1) {
				int pen = cur - max(longa, longb);
				cur = max(cur, rata + pen);
			}
		} else {
			cur = max(longa, longb);
			cur = max(cur, rata);
		}
		ans = min(ans, cur);
	} */
	
	FOR(i, 1, n) {
		int longest = -1;
		FOR(j, 1, n) {
			longest = max(longest, dist[i][j]);
		}
		//pf("%d %d\n", i, longest);
		ans = min(ans, longest);
	}
	FOR(i, 1, n) FOR(j, i + 1, n) {
		int longest = -1;
		int d = dist[i][j]/2;
		FOR(k, 1, n) {
			int to = 0;
			if(dist[i][k] + dist[j][k] != dist[i][j])
				to = min(dist[i][k], dist[j][k]);
			longest = max(longest, to);
		}
		ans = min(ans, longest + d);
	}
	
	pf("%.15lf\n", (DB) ans/2);
	return 0;
}
