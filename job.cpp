#include <bits/stdc++.h>

/**
 * Codeforces Round #267 (Div. 2)
 * Problem : C
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

LL num[5005], dp[5005][5005];
int n, m, k;

inline LL take(int i) {
	if(i < m) return 0;
	return num[i] - num[i-m];
}

int main(void)
{
	int i, j;
	sf("%d %d %d", &n, &m, &k);
	FOR(i, 1, n) {
		sf("%I64d", num + i);
		num[i] += num[i-1];
	}
	
	FOR(i, 1, n) {
		int to = i/m;
		FOR(j, 1, to) {
			//pf("%d %d gukguk\n", i, j);
			dp[i][j] = dp[i-1][j];
			if(0 <= i - m) {
				//pf("%d %d anjing\n", i, j);
				if(dp[i][j] < dp[i-m][j-1] + take(i)) {
					dp[i][j] = dp[i-m][j-1] + take(i);
				}
			}
		}
	}
	cout << dp[n][k] << endl;
	return 0;
}
