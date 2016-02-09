#include <bits/stdc++.h>

/**
 * Codeforces Round #261 (Div. 2)
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
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N];

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, n) sf("%d", a + i);
	int maks = -1, mini = inf;
	FORS(i, n) {
		if(a[i] > maks) maks = a[i];
		if(a[i] < mini) mini = a[i];
	}
	LL cntmax = 0, cntmin = 0;
	FORS(i, n) {
		if(a[i] == maks) cntmax++;
		if(a[i] == mini) cntmin++;
	}
	LL sum = cntmax * cntmin;
	if(maks == mini) sum = 1LL*n*(n - 1)/2;
	pf("%d %I64d\n", maks - mini, sum);
	return 0;
}
