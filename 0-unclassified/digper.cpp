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

int main(void)
{
	int base;
	sf("%d", &base);
	switch(base) {
		case 2 : puts("1"); break;
		case 4 : puts("123"); break;
		case 6 : puts("14325"); break;
		case 8 : puts("3254167"); break;
		case 10 : puts("381654729"); break;
		case 14 : puts("9C3A5476B812D"); break;
		default : puts("No");
	}
	
	return 0;
}
