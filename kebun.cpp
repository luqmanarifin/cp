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

int dp[2][1005][1005], source[1005][1005];
int d, a, b, c, p, n, m;
int w, x, y, z, q, petak;

// dp[state][row][col]
// state 1 itu ubi, kalo 0 singkong

void build() {
	int i, j, k;
	reset(source, 0);
	reset(dp, 0);
	
	source[1][1] = (d >= p);
	int prev = d;
	FOR(i, 1, n) FOR(j, 1, n) {
		if(i == 1 && j == 1) continue;
		int next = (a*prev + b) % c;
		source[i][j] = (next >= p);
		prev = next;
	}
	
	dp[w >= q][1][1]++;
	prev = w;
	FOR(i, 1, m) FOR(j, 1, m) {
		if(i == 1 && j == 1) continue;
		int next = (x*prev + y) % z;
		dp[next >= q][i][j]++;
		prev = next;
	}
	
	FOR(i, 1, m) FOR(j, 1, m) {
		dp[0][i][j] += dp[0][i-1][j] + dp[0][i][j-1] - dp[0][i-1][j-1];
		dp[1][i][j] += dp[1][i-1][j] + dp[1][i][j-1] - dp[1][i-1][j-1];
	}
}

int get(int st, int i, int j, int ii, int jj) {
	petak += (ii - i + 1)*(jj - j + 1);
	return dp[st][ii][jj] - dp[st][i-1][jj] - dp[st][ii][j-1] + dp[st][i-1][j-1];
}

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int i, j, k;
		sf("%d %d", &n, &m);
		sf("%d %d %d %d %d", &d, &a, &b, &c, &p);
		sf("%d %d %d %d %d", &w, &x, &y, &z, &q);
		build();
		LL ans = 0;
		petak = 0;
		FOR(i, 1, n) FOR(j, 1, n) {
			int st = source[i][j];
			int maxx = min(i, m);
			int minx = max(m - n + i, 1);
			int maxy = min(j, m);
			int miny = max(m - n + j, 1);
			ans += 1LL*get(st^1, minx, miny, maxx, maxy);
		}
		pf("%lld\n", ans);
	}
	return 0;
}
