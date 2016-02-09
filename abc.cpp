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

int a[3], x, y, z;

LL total(int n) {
	return 1LL*n*(n + 1)/2;
}

int main(void)
{
	int t, i;
	sf("%d", &t);
	while(t--) {
		LL ans = 0;
		FORS(i, 3) sf("%d", a + i);
		sort(a, a + 3);
		x = a[0], y = a[1], z = a[2];
		ans += x; 
		ans += (total(y - 1) - total(y - 1 - min(y - 1, x)))*3;
		ans += (total(z - 1) - total(z - 1 - min(z - 1, x)))*3;
		LL cur = 0;
		FOR(i, 1, x) cur += total(z - i - 1) - total(max(0, z - y - 1));
		ans += cur*6;
		pf("%lld\n", ans);
	}
	
	return 0;
}
