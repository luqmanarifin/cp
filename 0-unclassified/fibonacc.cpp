#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 1000005;

int fib[N];

int main(void)
{
	int t, i, j;
	fib[0] = 0, fib[1] = 1;
	FOR(i, 2, N-1) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if(fib[i] >= mod) fib[i] -= mod;
	}
	sf("%d", &t);
	while(t--) {
		int a, b;
		sf("%d %d", &a, &b);
		pf("%d\n", fib[__gcd(a, b)]);
	}
	
	return 0;
}
