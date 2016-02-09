#include <bits/stdc++.h>

/**
 * Codeforces Round #260 (Div. 2)
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

int main(void)
{
	char s[N];
	sf("%s", s);
	int n = strlen(s);
	int dor = s[n-1] - '0';
	if(n > 1) dor = s[n-2]*10 + dor;
	int ans = 1;
	dor %= 4;
	if(dor == 0) ans += 3;
	else if(dor == 1) ans += 9;
	else if(dor == 2) ans += 14;
	else ans += 14;
	cout << ans % 5 << endl;
	
	return 0;
}
