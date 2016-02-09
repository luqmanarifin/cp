#include <bits/stdc++.h>

/**
 * Codeforces Round #256 (Div. 2)
 * Problem : A
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
	int x, i, a = 0, b = 0, n;
	FORS(i, 3) {
		sf("%d", &x);
		a += x;
	}
	FORS(i, 3) {
		sf("%d", &x);
		b += x;
	}
	sf("%d", &n);
	int ok = 0;
	FOR(i, 0, n) {
		int cups = i*5;
		int medals = (n - i)*10;
		if(a <= cups && b <= medals) {
			ok = 1;
			break;
		}
	}
	puts(ok? "YES" : "NO");
	return 0;
}
