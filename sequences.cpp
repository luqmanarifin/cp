#include <bits/stdc++.h>

/* Codeforces Round #FF (Div. 2)
 * Problem : C
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

int fir[N], last[N], a[N], ans;

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, n) sf("%d", &a[i]);
	fir[0] = 0;
	FOR(i, 1, n-1) {
		if(a[i-1] < a[i]) fir[i] = fir[i-1];
		else fir[i] = i;
	}
	last[n-1] = n-1;
	FORD(i, n-2, 0) {
		if(fir[i] == fir[i+1]) last[i] = last[i+1];
		else last[i] = i;
	}
	FORS(i, n) ans = max(ans, last[i] - fir[i] + 1);
	if(n > 1) {
		ans = max(ans, last[1]+1);
		ans = max(ans, n - fir[n-2]);
	}
	FOR(i, 1, n-2) {
		if(a[i-1] + 1 < a[i+1])
			ans = max(ans, last[i+1] - fir[i-1] + 1);
		ans = max(ans, i - fir[i-1] + 1);
		ans = max(ans, last[i+1] - i + 1);
	}
	cout << ans << endl;
	//FORS(i, n) pf("%d ", fir[i]); nl;
	//FORS(i, n) pf("%d ", last[i]); nl;
	return 0;
}
