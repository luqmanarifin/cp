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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int n, k[1005], ans, bran[1005][105], dp[1005][105];

int main(void)
{
	int i, j, l;
	sf("%d", &n);
	FORS(i, n) {
		sf("%d", &k[i]);
		FORS(j, k[i])
			sf("%d", &bran[i][j]);
		sort(bran[i], bran[i] + k[i]);
	}
	FORS(i, n) FORS(j, k[i]) {
		int found = -1, posi;
		FORD(l, i, 0) {
			int pos = lower_bound(bran[l], bran[l] + k[l], bran[i][j]) - bran[l];
			if(pos == k[l] || bran[l][pos] >= bran[i][j]) pos--;
			if(pos != -1) {
				found = l;
				posi = pos;
				break;
			}
		}
		if(found != -1)
			dp[i][j] = dp[found][posi] + 1;
		else
			dp[i][j] = 1;
		//pf("%d %d %d %d\n", bran[i][j], found, posi, dp[i][j]);
		if(dp[i][j] > ans)
			ans = dp[i][j];
	}
	cout << ans << endl;
	return 0;
}
