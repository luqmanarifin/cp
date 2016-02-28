#include <bits/stdc++.h>

/**
 * Codeforces Round #258 (Div. 2)
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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N], d[N];

int main(void)
{
	int n, i, j, st = -1, fn = -1;
	sf("%d", &n);
	FORS(i, n) {
		sf("%d", a + i);
		d[i] = a[i];
	}
	sort(d, d + n);
	FORS(i, n) {
		if(a[i] != d[i] && st == -1) st = i;
		if(a[i] != d[i]) {
			fn = i;
		}
	}
	if(st != -1 && fn == -1) fn = n-1;
	if(st == -1) {
		puts("yes");
		pf("1 1\n");
		return 0;
	}
	int t = 0;
	FOR(i, st, fn) {
		if(a[i] != d[fn-t]) {
			puts("no");
			return 0;
		}
		t++;
	}
	puts("yes");
	pf("%d %d\n", st+1, fn+1);
	return 0;
}
