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

const LL mod = 1e9;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N];

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	FOR(i, 1, n) sf("%d", a + i);
	while(m--) {
		int t, l, r;
		sf("%d %d %d", &t, &l, &r);
		if(t == 1) a[l] = r;
		else {
			LL ans = 0;
			int fib[] = {1, 1};
			FOR(i, l, r) {
				int ke = i - l;
				if(ke > 1) fib[ke&1] += fib[(ke&1)^1];
				if(fib[ke&1] >= mod) fib[ke&1] -= mod;
				ans += 1LL*fib[ke&1]*a[i];
				ans %= mod;
			}
			pf("%d\n", (int) ans);
		}
	}
	return 0;
}
