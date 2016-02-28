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
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[105], b[105];

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		reset(a, 0);
		reset(b, 0);
		char s[105];
		sf("%s", &s[1]);
		int i, j, n = strlen(&s[1]);
		FOR(i, 1, n) {
			if(s[i] == 'A') a[i]++;
			else b[i]++;
		}
		FOR(i, 1, n) b[i] += b[i-1];
		FORD(i, n, 1) a[i] += a[i+1];
		int ans = inf;
		FOR(i, 1, n+1)
			ans = min(ans, b[i-1] + a[i]);
			
		pf("%d\n", ans);
	}
	return 0;
}
