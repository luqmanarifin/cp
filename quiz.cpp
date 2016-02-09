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

const LL mod = 1e9 + 9;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

LL power(LL a, LL b) {
	if(!b) return 1LL;
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
	LL n, m, k;
	cin >> n >> m >> k;
	LL enak = (n - m)*k;
	if(enak >= n) {
		cout << m << endl;
		return 0;
	}
	LL ampas = n - enak;
	LL ping = ampas / k;
	LL ans = power(2, ping + 1) - 2;
	if(ans < 0) ans += mod;
	ans = (ans * k) % mod;
	ans += (ampas % k) + (k - 1)*(n - m);
	ans %= mod;
	cout << ans << endl;
	return 0;
}
