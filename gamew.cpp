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
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL same[1 << 20];
DB dp[1 << 20];
char s[55][22];

int main(void)
{
	int n, i, j, k, mask;
	sf("%d", &n);
	FORS(i, n) sf("%s", s[i]);
	int len = strlen(s[0]);
	FORS(i, n) {
		FOR(j, i+1, n-1) {
			int pers = 0;
			FORS(k, len) {
				if(s[i][k] == s[j][k])
					pers |= (1 << k);
			}
			same[pers] |= (1LL << i) | (1LL << j);
		}
	}
	FORD(mask, (1 << len)-2, 0) {
		FORS(i, len) {
			if(((1 << i) & mask) == 0) {
				dp[mask] += dp[mask | (1 << i)];
				same[mask] |= same[mask | (1 << i)];
			}
		}
		dp[mask] = dp[mask] / (len - __builtin_popcount(mask)) + 1.0 * __builtin_popcountll(same[mask]) / n;
	}
	pf("%.15lf\n", dp[0]);
	return 0;
}
