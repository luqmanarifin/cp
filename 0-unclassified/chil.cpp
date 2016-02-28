#include <bits/stdc++.h>

/**
 * Codeforces Round #257 (Div. 2)
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

int a[105];

int main(void)
{
	int n, m, i, maks = -1, ans;
	sf("%d %d", &n, &m);
	FORS(i, n) {
		sf("%d", a + i);
		int kali = (a[i] % m? a[i]/m + 1 : a[i]/m);
		if(kali >= maks) {
			ans = i;
			maks = kali;
		}
	}
	cout << ans + 1 << endl;
	return 0;
}
