#include <bits/stdc++.h>

/**
 * Codeforces Round #266 (Div. 2) 
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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

inline void add(int &a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}

inline int mul(int a, int b) {
	return int((LL) a*b % mod);
}

int dp[2005][2005], a[2005];

int main(void)
{
	int i, j, n, h;
	sf("%d %d", &n, &h);
	FOR(i, 1, n) sf("%d", a + i);
	dp[0][0] = 1;
	FOR(i, 1, n) {
		FOR(j, 0, i) {
			if(a[i] + j == h) {
				add(dp[i][j], dp[i-1][j]);
				if(j) add(dp[i][j], dp[i-1][j-1]);
				
			} else if(a[i] + j + 1 == h) {
				add(dp[i][j], mul(j, dp[i-1][j]));
				add(dp[i][j], mul(j + 1, dp[i-1][j+1]));
				add(dp[i][j], dp[i-1][j]);
			}
		}
	}
	cout << dp[n][0] << endl;
	return 0;
}
