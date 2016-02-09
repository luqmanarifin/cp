#include <bits/stdc++.h>

/**
 * Codeforces Round #263 (Div. 2)
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
const int N = 3e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL a[N];

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, n) sf("%I64d", a + i);
	sort(a, a + n);
	int now = 1;
	LL ans = 0;
	FORS(i, n) {
		if(i == n-1) {
			ans += now*a[i];
			break;
		}
		//pf("%d %I64d", now, a[i]); nl;
		now++;
		ans += now*a[i];
	}
	cout << ans << endl;
	return 0;
}
