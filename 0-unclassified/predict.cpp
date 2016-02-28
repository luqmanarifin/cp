#include <bits/stdc++.h>

/**
 * Codeforces Round #258 (Div. 2)
 * Problem : C
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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int main(void)
{
	int t, tm;
	sf("%d", &t);
	while(t--) {
		LL n, k, d1, d2;
		sf("%I64d %I64d %I64d %I64d", &n, &k, &d1, &d2);
		bool ok = 0;
		FORS(tm, (1 << 2)) {
			LL a = 0, b, c;
			if(tm & 1) b = a + d1;
			else b = a - d1;
			if(tm & 2) c = b + d2;
			else c = b - d2;
			LL sm = min(a, min(b, c));
			LL big = max(a, max(b, c));
			LL rem = a - sm + b - sm + c - sm;
			LL mx = big - a + big - b + big - c;
			LL low = k - rem;
			LL upp = n - k - mx;
			if(low >= 0 && low % 3 == 0 && upp >= 0 && upp % 3 == 0) {
				ok = 1;
				break;
			}
		}
		puts(ok? "yes": "no");
	}
	
	return 0;
}