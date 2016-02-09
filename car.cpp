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

const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL ans = -INF;

int main(void)
{
	int p = 0, q = 0, a, b, i, j;
	sf("%d %d", &a, &b);
	int n = min(a, b);
	FOR(i, 1, n) {
		LL cur, qq;
		FOR(j, -1, 1) {
			cur = 1LL*(a - i + 1)*(a - i + 1) + i - 1;
			qq = i + j;
			if(qq > b || qq < 1) continue;
			int div = b / qq;
			int mod = b % qq;
			cur -= 1LL*div*div*(qq - mod) + 1LL*(div + 1)*(div + 1)*mod;
			//pf("%I64d %d %d\n", cur, i, qq);
			if(cur > ans) {
				ans = cur;
				p = i;
				q = qq;
			}
		}
	}
	if(!a) q = 1, ans = -1LL*b*b;
	if(!b) p = 1, ans = 1LL*a*a;
	cout << ans << endl;
	int x = (q? b/q : 0);
	int mod = (q? b % q : 0);
	if(q > p) {
		FORS(i, x) pf("x");
		if(mod) {
			pf("x");
			mod--;
		}
	}
	FORS(i, p) {
		if(i) pf("o");
		else
			FORS(j, a - p + 1) pf("o");
		if(i == p - 1 && p > q)
			break;
		if(i < mod)
			FORS(j, x + 1) pf("x");
		else
			FORS(j, x) pf("x");
	}
	nl; return 0;
}
