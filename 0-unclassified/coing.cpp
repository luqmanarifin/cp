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

// get total edge of complete graph
long long get(int n) {
	return (long long) n * (n - 1)/2;
}

int main(void)
{
	int s, i, j, n;
	sf("%d", &s);
	if(s == 2 || s == 5) {
		puts("Impossible");
		return 0;
	}
	int l = 1, r = 100000;
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(get(mid) <= s) l = mid;
		else r = mid - 1;
	}
	n = l;
	LL m = 2*get(n) - s;
	pf("%d %I64d\n", n, m);
	FOR(i, 2, n) {
		pf("1 %d\n", i);
	}
	m -= n - 1;
	FOR(i, 2, n) {
		FOR(j, i+1, n) {
			if(m == 0) return 0;
			m--;
			pf("%d %d\n", i, j);
		}
	}
	return 0;
}
