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

LL inv(LL a) {
	return power(a, mod - 2);
}

void norm(LL &a) {
	a %= mod;
	if(a < 0) a += mod;
}

int main(void)
{
	LL a, b, x, n, y;
	sf("%lld %lld %lld %lld %lld", &a, &b, &x, &n, &y);
	LL ans, rig;
	if(a == 1) {
		norm(n);
		ans = x + b*n;
		norm(ans);
	} else {
		ans = power(a, n)*x;
		norm(ans);
		//cout << ans << endl;
		rig = power(a, n) - 1;
		norm(rig);
		//cout << rig << endl;
		rig *= inv(a - 1);
		norm(rig);
		rig *= b;
		norm(rig);
		ans += rig;
		norm(ans);
	}
	if(ans == y) {
		puts("BENAR");
	} else {
		pf("SEHARUSNYA %lld\n", ans);
	}
	
	return 0;
}
