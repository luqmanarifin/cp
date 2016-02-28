#include <bits/stdc++.h>

/* Codeforces Round #FF (Div. 2)
 * Problem : A
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

int ada[305];

int main(void)
{
	int p, n, i;
	sf("%d %d", &p, &n);
	FORS(i, n) {
		int x;
		sf("%d", &x);
		if(ada[x % p]) {
			cout << i + 1 << endl;
			return 0;
		}
		ada[x % p] = 1;
	}
	puts("-1");
	return 0;
}
