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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const int mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int dp[2][5005], n;

int take(int i, int l, int r) {
	int temp = dp[i][r] - dp[i][l - 1];
	if(temp < 0) temp += mod;
	return temp;
}

int main(void)
{
	int a, b, k, i , j;
	sf("%d %d %d %d", &n, &a, &b, &k);
	dp[0][a] = 1;
	FOR(i, 1, k) {
		int now = i & 1;
		int pre = now ^ 1;
		FOR(j, 1, n) {
			dp[now][j] = 0;
			dp[pre][j] += dp[pre][j-1];
			if(dp[pre][j] >= mod) dp[pre][j] -= mod;
		}
		FOR(j, 1, n) {
			if(j == b) continue;
			int dis = (abs(b - j) - 1)/2;
			int isi;
			if(j < b) {
				isi = take(pre, 1, j + dis);
			} else {
				isi = take(pre, j - dis, n);
			}
			isi -= take(pre, j, j);
			if(isi < 0) isi += mod;
			dp[now][j] = isi;
		}
	}
	int ans = 0;
	i = k & 1;
	FOR(j, 1, n) {
		ans += dp[i][j];
		if(ans >= mod) ans -= mod;
	}
	pf("%d\n", ans);
	
	return 0;
}
