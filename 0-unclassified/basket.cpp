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

int main(void)
{
	int i, n, m, H, s = 0, h;
	sf("%d %d %d", &n, &m, &H);
	FOR(i, 1, m) {
		int x; sf("%d", &x);
		s += x;
		if(i == H) h = x;
	}
	if(s < n) {
		puts("-1");
		return 0;
	}
	double ans = 1;
	int a = s - n;
	int b = s - 1;
	FORS(i, h-1)
		ans *= (double)(a - i)/(b - i);
		
	pf("%.12f\n", (1 - ans));
	return 0;
}
