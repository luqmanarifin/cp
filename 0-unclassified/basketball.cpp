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
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N], b[N];

int main(void)
{
	int n, m, i, j;
	sf("%d", &n);
	FORS(i, n) sf("%d", &a[i]);
	sf("%d", &m);
	FORS(i, m) sf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + m);
	int ans = -inf, ansa, ansb;
	FORS(i, n) {
		int ta = 2 * i + 3 * (n - i);
		int pos = upper_bound(b, b + m, a[i] - 1) - b;
		int tb = 2 * pos + 3 * (m - pos);
		if(ta - tb > ans) {
			ans = ta - tb;
			ansa = ta;
			ansb = tb;
		}
	}
	if(2 * n - 2 * m > ans) {
		ans = 2 * n - 2 * m;
		ansa = 2 * n;
		ansb = 2 * m;
	}
	pf("%d:%d\n", ansa, ansb);
	return 0;
}
