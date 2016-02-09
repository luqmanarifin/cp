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

int n, len, a[1005];

int find(int now) {
	return now/3*2 + (now % 3);
}

int main(void)
{
	int t, i;
	sf("%d", &t);
	while(t--) {
		sf("%d %d", &len, &n);
		FORS(i, n) sf("%d", a + i);
		int ans = a[0] - 1;
		FOR(i, 1, n-1)
			ans = max(ans, find(a[i] - a[i-1] - 1));
		ans = max(ans, 2*(len - a[n-1]));
		pf("%d\n", ans);
	}
	//FOR(i, 0, 12) pf("%d ", i); nl;
	//FOR(i, 0, 12) pf("%d ", find(i)); nl;
	return 0;
}
