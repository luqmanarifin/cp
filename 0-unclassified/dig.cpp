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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int main(void)
{
	int m, s, i, j;
	sf("%d %d", &m, &s);
	if((m > 1 && s == 0) || s > 9*m) {
		puts("-1 -1");
		return 0;
	}
	if(m == 1 && s == 0) {
		puts("0 0");
		return 0;
	}
	int now = s;
	int ans = max(1, now - 9*(m - 1));
	pf("%d", ans);
	now -= ans;
	FORD(i, m-2, 0) {
		ans = max(0, now - 9*i);
		pf("%d", ans);
		now -= ans;
	}
	pf(" ");
	now = s;
	FORS(i, m) {
		ans = min(9, now);
		pf("%d", ans);
		now -= ans;
	}
	nl;
	return 0;
}
