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
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N];

int main(void)
{
	int n, k, i, lim = inf, now = 0;
	sf("%d %d", &n, &k);
	FORS(i, n) {
		sf("%d", &a[i]);
		if(i < k) now += a[i];
		lim = min(lim, a[i]);
	}
	int mark = 0;
	FOR(i, k-1, n-1) {
		int j = i;
		while(now >= 0) {
			int dif = a[j] - lim;
			if(now - dif < 0) {
				mark += abs(now + 1);
				a[j] -= now + 1;
				now = -1;
			} else {
				mark += abs(dif);
				a[j] -= dif;
				now -= dif;
			}
			j--;
		}
		now += a[i+1] - a[i-k+1];
	}
	pf("%d\n", mark);
	FORS(i, n) pf("%d ", a[i]); nl;
	
	return 0;
}
