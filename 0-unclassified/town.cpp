#include <bits/stdc++.h>

/**
 * Codeforces Round #284 (Div. 2)
 * Problem : C
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

int get(LL a) {
	return a > 0;
}

int main(void)
{
	LL x1, x2, y1, y2;
	sf("%I64d %I64d %I64d %I64d", &x1, &y1, &x2, &y2);
	int ans = 0;
	int i, n;
	sf("%d", &n);
	FORS(i, n) {
		LL a, b, c;
		sf("%I64d %I64d %I64d", &a, &b, &c);
		if(get(a*x1 + b*y1 + c) != get(a*x2 + b*y2 + c)) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
