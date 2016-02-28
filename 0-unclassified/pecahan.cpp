#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;
typedef unsigned long long ULL;

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

ULL gcd(ULL a, ULL b) { return b? gcd(b, a%b): a; }
ULL lcm(ULL a, ULL b) { return a*b / gcd(a, b); }

int main(void)
{
	ULL a, b, c, d, e, f;
	cin >> a >> b >> c >> d;
	ULL k = gcd(b, d);
	e = d/k*a + b/k*c;
	f = b/k*d;
	ULL fpb = gcd(e, f);
	cout << e/fpb << ' ' << f/fpb << endl;
	return 0;
}
