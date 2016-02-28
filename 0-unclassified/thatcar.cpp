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

LL row[1005], col[1005], x[1005], y[1005];
LL ans = INF;
int c[1005][1005];

int main(void)
{
	int n, m, i, j, ii, jj;
	sf("%d %d", &n, &m);
	FOR(i, 1, n) FOR(j, 1, m) {
		sf("%d", &c[i][j]);
		row[i] += c[i][j];
		col[j] += c[i][j];
	}
	FOR(i, 1, n)
		FOR(ii, 0, n) {
			LL dis = (ii < i? (i - ii - 1)*4 + 2 : (ii - i)*4 + 2);
			dis *= dis;
			x[ii] += dis*row[i];
		}
	FOR(j, 1, m)
		FOR(jj, 0, m) {
			LL dis = (jj < j? (j - jj - 1)*4 + 2 : (jj - j)*4 + 2);
			dis *= dis;
			y[jj] += dis*col[j];
		}
	int li, lj;
	FOR(i, 0, n) FOR(j, 0, m) {
		LL cur = x[i] + y[j];
		if(cur < ans) {
			ans = cur;
			li = i;
			lj = j;
		}
	}
	cout << ans << endl;
	pf("%d %d\n", li, lj);
	return 0;
}
