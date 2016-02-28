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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL prex, prey, prexx, preyy, ans;

int main(void)
{
	int n, i;
	sf("%d", &n);
	FOR(i, 1, n) {
		LL x, y;
		sf("%I64d %I64d", &x, &y);
		ans += (i - 1)*x*x - 2*x*prex + prexx;
		ans += (i - 1)*y*y - 2*y*prey + preyy;
		prex += x;
		prey += y;
		prexx += x*x;
		preyy += y*y;
	}
	cout << ans << endl;
	return 0;
}
