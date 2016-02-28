#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

LL dp[1 << 18][105];
char s[20];
int n, occ[10];

int print(int a) {
	int i;
	FORS(i, n) {
		pf((1 << i) & a? "1" : "0");
	}
}

int main(void)
{
	int i, j, m;
	sf("%s %d", s, &m);
	n = strlen(s);
	FORS(i, n) occ[s[i] -= '0']++;
	int pol = (1 << n), mask;
	dp[0][0] = 1;
	FORS(mask, pol) {
		FORS(j, m) {
			if(dp[mask][j] == 0) continue;
			FORS(i, n) if((mask & (1 << i)) == 0) {
				if(mask == 0 && s[i] == 0) continue;
				dp[mask | (1 << i)][(j * 10 + s[i]) % m] += dp[mask][j];
			}
		}
	}
	FOR(i, 0, 9) FOR(j, 2, occ[i]) {
		dp[pol - 1][0] /= (LL) j;
	}
	cout << dp[pol - 1][0] << endl;;
	return 0;
}
