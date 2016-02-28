#include <bits/stdc++.h>

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
int lcm(int a, int b) { return a*b / gcd(a, b); }

int main(void)
{
	ios_base::sync_with_stdio(false);
	LL n, d, m, l, i = 1, j;
	cin >> n >> d >> m >> l;
	LL space = m - l - 1;
	FOR(i, 1, n-1) {
		LL now = i*m;
		FOR(j, now-space, now-1) if(j % d == 0) {
			cout << j << endl;
			return 0;
		}
	}
	i = (n-1)*m + l + 1;
	while(true) {
		if(i % d == 0) {
			cout << i << endl;
			return 0;
		}
		i++;
	}
	
	return 0;
}
