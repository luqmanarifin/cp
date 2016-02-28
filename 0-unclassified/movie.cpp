#include <bits/stdc++.h>

/**
 * Codeforces Round #284 (Div. 2)
 * Problem : A
 * Luqman Arifin (kadalbonek)
 * بسم الله الرحمان الرحيم
 */

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

int l[55];
int r[55];

int main(void)
{
	int n, i, x;
	sf("%d %d", &n, &x);
	FORS(i, n) sf("%d %d", &l[i], &r[i]);
	int now = 1;
	int ans = 0;
	FORS(i, n) {
		while(now + x <= l[i]) now += x;
		//pf("now %d\n", now);
		ans += r[i] - now + 1;
		now = r[i] + 1;
	}
	cout << ans << endl;
	
	return 0;
}
