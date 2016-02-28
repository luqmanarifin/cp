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

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

pair<int,int> a[5005];
bool dp[5005][5];

int main(void)
{
	int i, j, n;
	sf("%d", &n);
	FORS(i, n) sf("%d %d", &a[i].first, &a[i].second);
	sort(a, a + n);
	bool ok = 1;
	dp[n-1][1] = 1;
	#define x first
	#define y second
	FORD(i, n-1, 1) {
		if(a[i-1].x <= a[i].x) dp[i-1][0] = dp[i-1][0] || dp[i][0];
		if(a[i-1].x <= a[i].y) dp[i-1][0] = dp[i-1][0] || dp[i][1];
		if(a[i-1].y <= a[i].x) dp[i-1][1] = dp[i-1][1] || dp[i][0];
		if(a[i-1].y <= a[i].y) dp[i-1][1] = dp[i-1][1] || dp[i][1];
	}
	int ans = a[n - 1].first;
	if(dp[0][0] || dp[0][1]) ans = min(ans, a[n - 1].second);
	cout << ans << endl;
	return 0;
}
