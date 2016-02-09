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

int dp[1005][2];
int a[1005][2];
int b[1005][2];

int main(void)
{
	int i, j, n;
	sf("%d %d %d", &n, &a[0][0], &b[0][0]);
	a[0][1] = a[0][0];
	b[0][1] = b[0][0];
	FOR(i, 1, n) {
		if(dp[i-1][0] + a[i-1][0] < dp[i-1][1] + a[i-1][1]) {
			dp[i][0] = dp[i-1][1] + a[i-1][1];
			a[i][0] = a[i-1][1] - 1;
			b[i][0] = b[i-1][1] + 1;
		} else {
			dp[i][0] = dp[i-1][0] + a[i-1][0];
			a[i][0] = a[i-1][0] - 1;
			b[i][0] = b[i-1][0] + 1;
		}
		if(dp[i-1][0] + b[i-1][0] < dp[i-1][1] + b[i-1][1]) {
			dp[i][1] = dp[i-1][1] + b[i-1][1];
			b[i][1] = b[i-1][1] - 1;
			a[i][1] = a[i-1][1] + 1;
		} else {
			dp[i][1] = dp[i-1][0] + b[i-1][0];
			b[i][1] = b[i-1][0] - 1;
			a[i][1] = a[i-1][0] + 1;
		}
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
	return 0;
}
