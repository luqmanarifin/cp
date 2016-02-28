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

int m, d;

int main(void)
{
	sf("%d:%d", &m, &d);
	int tot = m * 60 + d;
	tot -= 33;
	if(tot < 0) tot += 60*24;
	int mm = tot / 60;
	int dd = tot % 60;
	pf("%d%d:%d%d\n", mm/10, mm%10, dd/10, dd%10);
	
	return 0;
}
