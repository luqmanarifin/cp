#include <bits/stdc++.h>

/**
 * Codeforces Round #FF (Div. 2)
 * Problem : D
 * Luqman Arifin (kadalbonek)
 */

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
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL col[1005], row[1005], sumcol[N], sumrow[N];
priority_queue<LL> cols, rows;

int main(void)
{
	int i, j, n, m, k, p, x;
	sf("%d %d %d %d", &n, &m, &k, &p);
	FORS(i, n) FORS(j, m) {
		sf("%d", &x);
		row[i] += x;
		col[j] += x;
	}
	FORS(i, n) rows.push(row[i]);
	FORS(j, m) cols.push(col[j]);
	LL temp;
	FOR(i, 1, k) {
		temp = rows.top();
		rows.pop();
		rows.push(temp - m*p);
		sumrow[i] = sumrow[i-1] + temp;
		
		temp = cols.top();
		cols.pop();
		cols.push(temp - n*p);
		sumcol[i] = sumcol[i-1] + temp;
	}
	LL ans = -INF;
	FOR(i, 0, k) {
		LL cur = sumrow[i] + sumcol[k - i] - 1LL*i*(k - i)*p;
		if(cur > ans) ans = cur;
	}
	cout << ans << endl;
	return 0;
}
