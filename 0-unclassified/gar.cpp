#include <bits/stdc++.h>

/**
 * Codeforces Round #261 (Div. 2)
 * Problem : A
 * Luqman Arifin (kadalbonek)
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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int main(void)
{
	int a, b, c, d;
	sf("%d %d %d %d", &a, &b, &c, &d);
	if(a == c) {
		pf("%d %d %d %d\n", a + abs(b - d), b, c + abs(b - d), d);
		return 0;
	}
	if(b == d) {
		pf("%d %d %d %d\n", a, b + abs(a - c), c, d + abs(a - c));
		return 0;
	}
	if(abs(a - c) == abs(b - d)) {
		pf("%d %d %d %d\n", c, b, a, d);
		return 0;
	}
	puts("-1");
	return 0;
}
