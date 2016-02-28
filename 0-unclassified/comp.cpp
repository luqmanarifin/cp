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

LL gcd(LL a, LL b) { return b? gcd(b, a%b): a; }
LL lcm(LL a, LL b) { return a/ gcd(a, b)*b; }

// 1632899 1632913

int main(void)
{
	int n, i;
	LL x, y;
	sf("%d %I64d %I64d", &n, &x, &y);
	LL kpk = lcm(x, y);
	x = kpk/x;
	y = kpk/y;
	FORS(i, n) {
		int a;
		sf("%d", &a);
		LL l = 0, r = 1e17;
		while(l < r) {
			LL mid = (l + r) >> 1;
			LL find = mid / x + mid / y;
			if(find >= a) r = mid;
			else l = mid + 1;
		}
		cout << l << endl;
		if(l % x == 0 && l % y == 0) puts("Both");
		else if(l % x == 0) puts("Vanya");
		else puts("Vova");
	}
	
	return 0;
}
