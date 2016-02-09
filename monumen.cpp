#include <bits/stdc++.h>

/**
 * Penyisihan Lomba Programming Gemastik 7 UGM
 * Gajah Wangi
 * Problem : B
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
const int inf = 25e7 + 1;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[505][505];
LL dp[1005][1005];

inline LL get(int xi, int yi, int xj, int yj) {
	return dp[xj][yj] - dp[xj][yi - 1] - dp[xi - 1][yj] + dp[xi - 1][yi - 1];
}

int main(void)
{
	int t, i, j, n, m, k;
	sf("%d", &t);
	while(t--) {
		sf("%d %d", &n, &m);
		reset(a, 0);
		FOR(i, 1, n) FOR(j, 1, m) sf("%d", &a[i][j]);
		FORS(i, 1005) FORS(j, 1005) dp[i][j] = -inf;
		FOR(i, 1, n) {
			int x = i;
			int y = m + i - 1;
			FORD(j, m, 1) {
				dp[x][y] = a[i][j];
				x++, y--;
			}
			if(i < n) {
				x = i + 1;
				y = m + i - 1;
				FORD(j, m-1, 1) {
					dp[x][y] = 0;
					x++, y--;
				}
			}
		}
		int maks = n + m - 1;
		FOR(i, 1, maks) FOR(j, 1, maks) {
			dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
		}
		LL ans = -INF;
		FOR(i, 1, maks) {
			int low = 1 + abs(i - m);
			int hih = maks - abs(i - n);
			FOR(j, 1, maks) {
				if(j < low) continue;
				if(j > hih) continue;
				if((m + 1) % 2 != (i + j) % 2) continue;
				for(k = 3; j + k - 1 <= hih; k += 2) {
					int cor = i + k - 1;
					int bat = maks - abs(cor - n);
					if(j + k - 1 > bat) break;
					ans = max(ans, get(i, j, i + k - 1, j + k - 1));
					//pf("%d %d sisi %d %I64d\n", i, j, k, get(i, j, i + k - 1, j + k - 1));
				}
			}	
		}
		pf("%lld\n", ans);
	}
	
	return 0;
}
