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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

double a[10005], high = -INF, low = INF, mean, sds = 0;

int main(void)
{
	int n, i;
	sf("%d", &n);
	FORS(i, n) {
		sf("%lf", &a[i]);
		if(a[i] > high) high = a[i];
		if(a[i] < low) low = a[i];
		mean += a[i];
		sds += a[i]*a[i];
	}
	mean = (DB) mean / n;
	sds = sqrt((DB) (sds - mean*mean*n)/(n - 1));
	pf("%.2f %.2f %.2f %.2f\n", low, high, mean, sds);
	return 0;
}
