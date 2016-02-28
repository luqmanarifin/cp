#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")
#define ULL unsigned long long

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
const ULL magic = 1775533;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N], b[N];
ULL power[N];

int main(void)
{
	int n, i, j;
	power[0] = 1;
	FOR(i, 1, N-1) power[i] = power[i-1] * magic;
	sf("%d", &n);
	FORS(i, n) sf("%d", &a[i]);
	FORS(i, n) sf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + n);
	vector<ULL> ha, hb;
	FOR(i, 1, n-1) {
		ha.push_back(a[i] - a[i-1]);
		hb.push_back(b[i] - b[i-1]);
	}
	ha.push_back(a[0] + 360000 - a[n-1]);
	hb.push_back(b[0] + 360000 - b[n-1]);
	ULL key = 0;
	FORM(i, n) key = key * magic + ha[i];
	ULL now = 0;
	FORM(i, n) now = now * magic + hb[i];
	FORM(i, n) {
		now -= hb[i] * power[n-1];
		now *= power[1];
		now += hb[i];
		if(now == key) {
			puts("possible");
			return 0;
		}
	}
	puts("impossible");
	return 0;
}
