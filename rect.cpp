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
int lcm(int a, int b) { return a*b / gcd(a, b); }

int sub[45][45], a[45][45];
LL ans[45][45][45][45];

int main(void)
{
	int i, j, k, l, n, m, q;
	char s[45];
	sf("%d %d %d", &n, &m, &q);
	FOR(i,1,n) {
		sf("%s", &s[1]);
		FOR(j,1,m)
			a[i][j] = s[j] - '0';
	}
	FOR(i,1,n)
		FOR(j,1,m)
			sub[i][j] = sub[i][j-1] + sub[i-1][j] - sub[i-1][j-1] + a[i][j];
	FOR(i,1,n)
		FOR(j,1,m)
			FOR(k,i,n)
				FOR(l,j,m) {
					int sum = sub[k][l] - sub[k][j-1] - sub[i-1][l] + sub[i-1][j-1];
					ans[i][j][k][l] = (sum == 0);
				}
	FORD(i,n,1)
		FOR(j,1,m)
			FOR(k,i,n)
				FOR(l,j,m)
					ans[i][j][k][l] += ans[i+1][j][k][l];
	FOR(i,1,n)
		FORD(j,m,1)
			FOR(k,i,n)
				FOR(l,j,m)
					ans[i][j][k][l] += ans[i][j+1][k][l];
	FOR(i,1,n)
		FOR(j,1,m)
			FOR(k,i,n)
				FOR(l,j,m)
					ans[i][j][k][l] += ans[i][j][k-1][l];
	FOR(i,1,n)
		FOR(j,1,m)
			FOR(k,i,n)
				FOR(l,j,m)
					ans[i][j][k][l] += ans[i][j][k][l-1];
	while(q--) {
		int h, b, c, d;
		sf("%d %d %d %d", &h, &b, &c, &d);
		pf("%I64d\n", ans[h][b][c][d]);
	}
	return 0;
}
