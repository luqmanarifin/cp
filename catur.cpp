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

int s[1005][1005], n, m;
int a[1005][1005], b[1005][1005], c[1005][1005], d[1005][1005];

bool valid(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= m);
}

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int i, j;
		sf("%d %d", &n, &m);
		reset(s, 0);
		reset(a, 0);
		reset(b, 0);
		reset(c, 0);
		reset(d, 0);
		FOR(i, 1, n) FOR(j, 1, m) sf("%d", &s[i][j]);
		for(i = n, j = 1; valid(i, j);) {
			int ii = i, jj = j;
			while(valid(ii, jj)) {
				a[ii][jj] = a[ii-1][jj-1] + s[ii-1][jj-1];
				ii++, jj++;
			}
			if(i > 1) i--;
			else j++;
		}
		for(i = 1, j = 1; valid(i, j);) {
			int ii = i, jj = j;
			while(valid(ii, jj)) {
				b[ii][jj] = b[ii+1][jj-1] + s[ii+1][jj-1];
				ii--; jj++;
			}
			if(i < n) i++;
			else j++;
		}
		for(i = n, j = 1; valid(i, j);) {
			int ii = i, jj = j;
			while(valid(ii, jj)) {
				c[ii][jj] = c[ii+1][jj+1] + s[ii+1][jj+1];
				ii--; jj--;
			}
			if(j < m) j++;
			else i--;
		}
		for(i = 1, j = 1; valid(i, j); ) {
			int ii = i, jj = j;
			while(valid(ii, jj)) {
				d[ii][jj] = d[ii-1][jj+1] + s[ii-1][jj+1];
				ii++; jj--;
			}
			if(j < m) j++;
			else i++;
		}
		
		int ans = 0;
		FOR(i, 1, n) FOR(j, 1, m) {
			int cur = a[i][j] + b[i][j] + c[i][j] + d[i][j];
			//pf("cur %d %d = %d\n", i, j, cur);
			ans = max(ans, cur);
		}
		pf("%d\n", ans);
	}
	return 0;
}
