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

int i, j, k, t, n, m, x, s[105];
double r[105];

int main(void)
{
	sf("%d", &t);
	while(t--) {
		sf("%d %d", &n, &m);
		reset(s, 0);
		FOR(i, 1, n) {
			sf("%d", &x);
			s[x]++;
		}
		FORS(j, 102) r[j] = 1;
		FOR(j, 1, m) {
			double ans = 0;
			FOR(k, 0, 100) {
				ans += (DB)r[k]*s[k]*k*1.0/100;
				r[k] *= (DB)(100 - k)/100;
			}
			pf("%.3lf\n", ans);
		}
	}
	return 0;
}
