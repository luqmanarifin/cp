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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL mod;

LL power(LL a, LL b) {
	if(b == 0) return 1;
	LL temp = power(a, b/2);
	temp *= temp;
	temp %= mod;
	if(b & 1) {
		temp *= a;
		temp %= mod;
	}
	return temp;
}

int main(void)
{
	int t, i, j;
	sf("%d", &t);
	while(t--) {
		int n, k;
		sf("%d %lld %d", &n, &mod, &k);
		int ans = 0;
		FOR(i, 1, k) {
			ans += power(i, n);
			if(ans >= mod) ans -= mod;
		}
		cout << ans << '\n';
	}
	
	return 0;
}
