#include <bits/stdc++.h>

/**
 * Codeforces Round #256 (Div. 2)
 * Problem : D
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

LL n, m, ans;

int main(void)
{
	LL k;
	sf("%I64d %I64d %I64d", &n, &m, &k);
	if(n > m) swap(n, m);
	LL l = 1, r = n*m, mid, i;
	while(l < r) {
		mid = (l + r) >> 1;
		LL less = 0;
		FOR(i, 1, n) less += min(m, mid/i);
		if(less < k) l = mid + 1;
		else r = mid;
	}
	cout << l << endl;
	return 0;
}
