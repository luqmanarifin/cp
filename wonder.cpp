#include <bits/stdc++.h>

/**
 * Codeforces Round #266 (Div. 2) 
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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL n, a, b;

int main(void)
{
	sf("%I64d %I64d %I64d", &n, &a, &b);
	if(a*b >= 6*n) {
		pf("%I64d %I64d %I64d\n", a*b, a, b);
		return 0;
	}
	n *= 6LL;
	bool swapped = 0;
	if(a > b) {
		swapped = 1;
		swap(a, b);
	}
	LL ansa = inf, ansb = inf;
	for(int i = 0; ; i++) {
		LL aa = a + i;
		if((long long) aa*aa > n) break;
		LL bb = max(b, n/aa + (n % aa? 1 : 0));
		//pf("%I64d %I64d\n", aa, bb);
		if(n <= aa*bb) {
			if(aa*bb < ansa*ansb) {
				ansa = aa;
				ansb = bb;
			}
		}
		//puts("gukguk");
	}
	if(swapped) swap(ansa, ansb);
	pf("%I64d\n%I64d %I64d\n", ansa*ansb, ansa, ansb);
	return 0;
}
