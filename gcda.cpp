#include <bits/stdc++.h>

typedef unsigned long long LL;
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
const double eps = 1e-13;

LL gcd(LL a, LL b) { return b? gcd(b, a%b): a; }
LL lcm(LL a, LL b) { return a/ gcd(a, b)*b; }

int main(void)
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		LL a, b;
		cin >> a >> b;;
		cout << gcd(a, b) << '\n';
	}
	
	return 0;
}
