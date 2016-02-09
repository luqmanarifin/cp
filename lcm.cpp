#include <bits/stdc++.h>

typedef long long LL;

#define sf scanf
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

LL gcd(LL a, LL b) { return b? gcd(b, a%b): a; }
LL lcm(LL a, LL b) { return a/ gcd(a, b)*b; }

int main(void)
{
	int n;
	sf("%d", &n);
	LL a, b, c, ans = -1;
	FOR(a, max(1, n - 10), n)
		FOR(b, max(1, n - 10), n)
			FOR(c, max(1, n - 10), n)
				ans = max(ans, lcm(a, lcm(b, c)));
	
	cout << ans << endl;
	return 0;
}
