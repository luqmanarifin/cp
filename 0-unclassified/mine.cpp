#include <bits/stdc++.h>

/**
 * Codeforces Round #259 (Div. 1)
 * Problem : B
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

void print(int a, int b) {
	int i;
	FORS(i, (a-b)/2) pf("*");
	FORS(i, b) pf("D");
	FORS(i, (a-b)/2) pf("*");
	nl;
}

int main(void)
{
	int n, i;
	sf("%d", &n);
	for(i = 1; i < n; i += 2)
		print(n, i);
	for(i = n; i > 0; i -= 2)
		print(n, i);
	return 0;
}
