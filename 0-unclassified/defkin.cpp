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

int row[40005];
int col[40005];
#define x first
#define y second

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int n, m, i, j, num;
		sf("%d %d %d", &n, &m, &num);
		FORS(i, num) {
			sf("%d %d", row + i, col + i);
		}
		col[num] = 0;
		col[num+1] = m+1;
		row[num] = 0;
		row[num+1] = n+1;
		sort(row, row + num + 2);
		sort(col, col + num + 2);
		int maxcol = -1, maxrow = -1;
		FOR(i, 1, num + 1) maxcol = max(maxcol, col[i]-col[i-1]-1);
		FOR(i, 1, num + 1) maxrow = max(maxrow, row[i]-row[i-1]-1);
		pf("%d\n", maxcol*maxrow);
	}
	return 0;
}
